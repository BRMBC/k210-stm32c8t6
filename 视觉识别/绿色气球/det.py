import sensor, image, time, lcd, gc, cmath
from maix import KPU
from fpioa_manager import fm
from machine import UART
#LCD屏幕
lcd.init()                          # Init lcd display
# sensor.reset(dual_buff=True)      # improve fps
sensor.reset()                      # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565) # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)   # Set frame size to QVGA (320x240)
sensor.skip_frames(time = 1000)     # Wait for settings take effect.
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)

#UART通信配置
fm.register(6, fm.fpioa.UART2_RX)
fm.register(8, fm.fpioa.UART2_TX)
uart = UART(UART.UART2, 115200, 8, 0, 0, timeout=1000, read_buf_len=4096)
#时间
last_time = time.ticks_ms()#计算时间
#字符串定义
left=b'a'
right=b'd'
move=b'w'
stop=b's'
duojigo='g'
duojistop='h'
#模型配置
labels = ["green"] #类名称，按照label.txt顺序填写
anchor = (4.03, 3.78, 5.16, 5.06, 6.00, 5.69, 7.09, 6.47, 9.47, 6.81) # anchors,使用anchor.txt中第二行的值
#KPU设置
kpu = KPU()
# 从sd或flash加载模型
kpu.load_kmodel('/sd/det.kmodel')
kpu.init_yolo2(anchor, anchor_num=(int)(len(anchor)/2), img_w=320, img_h=240, net_w=320 , net_h=240 ,layer_w=10 ,layer_h=8, threshold=0.6, nms_value=0.3, classes=len(labels))
#LAB颜色范围
red_threshold=(30, 100, 15, 127, 15, 127)


while(True):
    gc.collect()
    img = sensor.snapshot()
    kpu.run_with_output(img)
    dect = kpu.regionlayer_yolo2()
#    x=img.width()//2 -60 #图片中心
#    y=img.height()//2 -60 #图片中心
#    w=120 #识别框宽度
#    h=120 #识别框高度
#    blobr = img.find_blobs([red_threshold],roi=[x,y,w,h],x_stride=40,y_stride=30, pixels_threshold=40, area_threshold=45, merge=True, margin=10)
    if len(dect) > 0:
        uart.write(duojigo)
        time.sleep_ms(10)
        for l in dect :
            img.draw_rectangle(l[0],l[1],l[2],l[3],color=(0,255,0))
            if labels[l[4]] == "green" :
                gx= (l[0]+l[2])//2
                if time.ticks_ms() - last_time > 100 and gx > 170:
                    last_time = time.ticks_ms()
                    uart.write(left)
                elif time.ticks_ms() - last_time > 100 and gx < 150:
                    last_time = time.ticks_ms()
                    uart.write(right)
                elif time.ticks_ms() - last_time > 100 and gx > 150 and gx < 170:
                    last_time = time.ticks_ms()
                    uart.write(move)
            elif labels[l[4]] == "red" :
                rx = (l[0]+l[2])//2
                if time.ticks_ms() - last_time > 100 and rx > 160:
                    last_time = time.ticks_ms()
                    uart.write(right)
                elif time.ticks_ms() - last_time > 100 and rx < 160:
                    last_time = time.ticks_ms()
                    uart.write(left)
#    elif blobr :
#        for r in blobr:
#            img.draw_rectangle(r.rect())
#            img.draw_cross(r.cx(), r.cy(),size=5,thickness=1)
#            img.draw_string(r.x()+1,r.y()-1,"red")
#            if time.ticks_ms() - last_time > 100 and 160 - r.cx() > 0:
#                last_time = time.ticks_ms()
#                uart.write(left)
#            elif time.ticks_ms() - last_time > 100 and 160 - r.cx() < 0:
#                last_time = time.ticks_ms()
#                uart.write(right)
    else :
        uart.write(duojistop)
        time.sleep_ms(10)
        if time.ticks_ms() - last_time > 500:
            last_time = time.ticks_ms()
            uart.write(right)

    lcd.display(img)
