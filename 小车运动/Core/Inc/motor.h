#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "main.h"

//×ó2
#define IN1_H HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,GPIO_PIN_SET);
#define IN1_L HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,GPIO_PIN_RESET);
#define IN2_H HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,GPIO_PIN_SET);
#define IN2_L HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,GPIO_PIN_RESET);
//ÓÒ1
#define IN3_H HAL_GPIO_WritePin(IN3_GPIO_Port,IN3_Pin,GPIO_PIN_SET);
#define IN3_L HAL_GPIO_WritePin(IN3_GPIO_Port,IN3_Pin,GPIO_PIN_RESET);
#define IN4_H HAL_GPIO_WritePin(IN4_GPIO_Port,IN4_Pin,GPIO_PIN_SET);
#define IN4_L HAL_GPIO_WritePin(IN4_GPIO_Port,IN4_Pin,GPIO_PIN_RESET);
//×ó1
#define IN5_H HAL_GPIO_WritePin(IN5_GPIO_Port,IN5_Pin,GPIO_PIN_SET);
#define IN5_L HAL_GPIO_WritePin(IN5_GPIO_Port,IN5_Pin,GPIO_PIN_RESET);
#define IN6_H HAL_GPIO_WritePin(IN6_GPIO_Port,IN6_Pin,GPIO_PIN_SET);
#define IN6_L HAL_GPIO_WritePin(IN6_GPIO_Port,IN6_Pin,GPIO_PIN_RESET);
//ÓÒ2
#define IN7_H HAL_GPIO_WritePin(IN7_GPIO_Port,IN7_Pin,GPIO_PIN_SET);
#define IN7_L HAL_GPIO_WritePin(IN7_GPIO_Port,IN7_Pin,GPIO_PIN_RESET);
#define IN8_H HAL_GPIO_WritePin(IN8_GPIO_Port,IN8_Pin,GPIO_PIN_SET);
#define IN8_L HAL_GPIO_WritePin(IN8_GPIO_Port,IN8_Pin,GPIO_PIN_RESET);

void PWM_INIT(void); 
void car_go_straight(uint16_t);
void car_go_right(uint16_t);
void car_go_left(uint16_t);
void car_go_stop(void);
void car_go_after(uint16_t);
void car_track_left(uint16_t);
void car_go_redright(uint16_t speed);
void DJ_go(void);
void DJ_stop(void);
#endif
