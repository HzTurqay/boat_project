

/*
(c) Hz.Turqay;
*/

#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "stdint.h"

typedef struct{
  uint8_t right_a;
  uint8_t right_b;
  uint8_t left_a;
  uint8_t left_b;
  uint8_t right_speed_pin;
  uint8_t left_speed_pin;
}Motor_pins;


typedef struct{
  uint8_t trig_pin;
  uint8_t echo_pin;
}Ultrasonic_pins;

typedef enum{
  forward,
  backward,
  stop,
}Direction;

void ultrasonic_init(Ultrasonic_pins *us_pins);
void motor_init_struct(Motor_pins *pins);
float read_distance(Ultrasonic_pins *us_pins);
void motor_run(Motor_pins *m_pins , uint8_t speed , Direction dir);



#endif