#include "motor.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"
/*
 * * 麦轮控制 * *
 */
void PWM_INIT()
{
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);    //开启电机左1的PWM输出定时器;打开定时器1，通道1
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);	//开启电机左2的PWM输出定时器;打开定时器1，通道2
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);	//开启电机右1的PWM输出定时器;打开定时器1，通道3
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);    //开启电机右2的PWM输出定时器;打开定时器1，通道4
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
}

void car_go_straight(uint16_t speed)//前进
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,speed);	//设置占空比
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,speed+150);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,speed);
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,speed);

	IN1_L;
	IN2_H;//左2

	IN3_H;
	IN4_L;//右1

	IN5_L;
	IN6_H;//左1

	IN7_L;
	IN8_H;//右2
}

void car_go_left(uint16_t speed)//左转
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

void car_go_right(uint16_t speed)//右转
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
void car_go_stop()//停止
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
void car_go_after(uint16_t speed)//后退
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
void car_track_left(uint16_t speed)//循迹直角左转
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

void car_go_redright(uint16_t speed)//右转
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
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,15);//右舵机平行点
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,14);//左舵机平行点
}

void DJ_stop()
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,6);//右舵机最高点
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,24);//左舵机最高点
}
