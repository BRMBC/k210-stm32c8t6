# Untitled - By: BLUE - 周六 10月 14 2023
import sensor, image, time, lcd, gc, cmath
from maix import KPU
from fpioa_manager import fm
from machine import UART
#LCD屏幕
lcd.init()                          # Init lcd display
sensor.reset(dual_buff=True)      # improve fps
#sensor.reset()                      # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565) # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)   # Set frame size to QVGA (320x240)
sensor.skip_frames(time = 1000)     # Wait for settings take effect.
#UART通信配置
fm.register(6, fm.fpioa.UART2_RX)
fm.register(8, fm.fpioa.UART2_TX)
uart = UART(UART.UART2, 115200, 8, 0, 0, timeout=1000, read_buf_len=4096)
#时间
last_time = time.ticks_ms()#计算时间
#字符串定义
left='a'
right='d'
move='w'
stop='s'
duojigo='g'
duojistop='h'
u_right='t'
redleft='r'
#模型配置
labels = ["red", "other"] #类名称，按照label.txt顺序填写
anchor = (3.34, 3.38, 4.44, 4.19, 4.97, 4.94, 5.56, 5.44, 7.19, 6.22) # anchors,使用anchor.txt中第二行的值
#KPU设置
kpu = KPU()
# 从sd或flash加载模型
kpu.load_kmodel('/sd/det.kmodel')
#kpu.load_kmodel(0x300000, 584744)
kpu.init_yolo2(anchor, anchor_num=(int)(len(anchor)/2), img_w=320, img_h=240, net_w=320 , net_h=240 ,layer_w=10 ,layer_h=8, threshold=0.8, nms_value=0.2, classes=len(labels))
#距离常数
k=4500
while(True):
    gc.collect()
    img = sensor.snapshot()
    kpu.run_with_output(img)
    dect = kpu.regionlayer_yolo2()
    if len(dect) > 0:
        for l in dect :
            if labels[l[4]] == "other":
                a=img.draw_rectangle(l[0],l[1],l[2],l[3],(0,0,255))
                ox= l[0]+l[2]//2
                if ox > 215:
                    uart.write(right)
                elif ox < 75:
                    uart.write(left)
                elif ox > 75 and ox < 215:
                    uart.write(duojigo)
                    time.sleep_ms(10)
            elif labels[l[4]] == "red" and l[5] > 0.85:
                b=img.draw_rectangle(l[0],l[1],l[2],l[3],(255,0,0))
                rx = l[0]+l[2]//2
                uart.write(duojistop)
                if rx > 90 and rx < 200 :
                    if time.ticks_ms() - last_time >= 10:
                        last_time = time.ticks_ms()
                        uart.write(redleft)
#                if rx < 145:
#                    uart.write(u_right)
#                if rx > 145:
#                    uart.write(redleft)
    else:
        if time.ticks_ms() - last_time >=6000:
            last_time = time.ticks_ms()
            uart.write(duojistop)
    lcd.display(img)
