#include "motor.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"
/*
 * * ���ֿ��� * *
 */
void PWM_INIT()
{
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);    //���������1��PWM�����ʱ��;�򿪶�ʱ��1��ͨ��1
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);	//���������2��PWM�����ʱ��;�򿪶�ʱ��1��ͨ��2
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);	//���������1��PWM�����ʱ��;�򿪶�ʱ��1��ͨ��3
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);    //���������2��PWM�����ʱ��;�򿪶�ʱ��1��ͨ��4
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
}

void car_go_straight(uint16_t speed)//ǰ��
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed);	//����ռ�ձ�
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed+150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

	IN1_L;
	IN2_H;//��2

	IN3_H;
	IN4_L;//��1

	IN5_L;
	IN6_H;//��1

	IN7_L;
	IN8_H;//��2
}

void car_go_left(uint16_t speed)//��ת
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed+150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

//	IN1_L;
//	IN2_H;

//	IN3_H;
//	IN4_L;

//	IN5_H;
//	IN6_L;

//	IN7_L;
//	IN8_H;
	
	IN1_H;
	IN2_L;

	IN3_H;
	IN4_L;
	
	IN5_H;
	IN6_L;
	
	IN7_L;
	IN8_H;
}

void car_go_right(uint16_t speed)//��ת
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed+150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

	IN1_L;
	IN2_H;

	IN3_L;
	IN4_H;
	
	IN5_L;
	IN6_H;
	
	IN7_H;
	IN8_L;
}
void car_go_stop()//ֹͣ
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,0);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,0);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,0);
	
	IN1_L;
	IN2_L;

	IN3_L;
	IN4_L;
	
	IN5_L;
	IN6_L;
	
	IN7_L;
	IN8_L;
}
void car_go_after(uint16_t speed)//����
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed+150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);
	
	IN1_H;
	IN2_L;
	
	IN3_L;
	IN4_H;
	
	IN5_H;
	IN6_L;
	
	IN7_H;
	IN8_L;
}
void car_track_left(uint16_t speed)//ѭ��ֱ����ת
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed-150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

//	IN1_L;
//	IN2_H;

//	IN3_H;
//	IN4_L;

//	IN5_H;
//	IN6_L;

//	IN7_L;
//	IN8_H;
	
	IN1_H;
	IN2_L;

	IN3_H;
	IN4_L;
	
	IN5_H;
	IN6_L;
	
	IN7_L;
	IN8_H;	
}

void car_go_redright(uint16_t speed)//��ת
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed-150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

	IN1_L;
	IN2_H;

	IN3_L;
	IN4_H;
	
	IN5_L;
	IN6_H;
	
	IN7_H;
	IN8_L;
}

void DJ_go()
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,15);//�Ҷ��ƽ�е�
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,14);//����ƽ�е�
}

void DJ_stop()
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,6);//�Ҷ����ߵ�
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,24);//������ߵ�
}
