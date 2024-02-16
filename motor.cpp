/*
(c) Hz.Turqay;
*/


#include "motor.h"
#include "Arduino.h"

void motor_init_struct(Motor_pins *pins){
  pinMode(pins->left_a , OUTPUT);
  pinMode(pins->left_b , OUTPUT);
  pinMode(pins->right_a , OUTPUT);
  pinMode(pins->right_b , OUTPUT);
  pinMode(pins->right_speed_pin , OUTPUT);
  pinMode(pins->left_speed_pin , OUTPUT);
}

void ultrasonic_init(Ultrasonic_pins *us_pins){
  pinMode(us_pins->trig_pin , OUTPUT);
  pinMode(us_pins->echo_pin , INPUT);
}

float read_distance(Ultrasonic_pins *us_pins){
  digitalWrite(us_pins->trig_pin , LOW);
  delayMicroseconds(2);
  digitalWrite(us_pins->trig_pin , HIGH);
  delayMicroseconds(10);
  long duration = pulseIn(us_pins->echo_pin, HIGH);
  return ((float)duration * 0.034 / 2.0);
}

void motor_run(Motor_pins *m_pins , uint8_t speed , Direction dir){
  switch(dir){

    case backward:
    digitalWrite(m_pins->left_a , HIGH);
    digitalWrite(m_pins->left_b , LOW);
    digitalWrite(m_pins->right_a , HIGH);
    digitalWrite(m_pins->right_b , LOW);
    analogWrite(m_pins->right_speed_pin , speed);
    analogWrite(m_pins->left_speed_pin ,speed);
    break;

    case forward:
    digitalWrite(m_pins->left_a , LOW);
    digitalWrite(m_pins->left_b , HIGH);
    digitalWrite(m_pins->right_a , LOW);
    digitalWrite(m_pins->right_b , HIGH);
    analogWrite(m_pins->right_speed_pin , speed);
    analogWrite(m_pins->left_speed_pin ,speed);
    break;

    case stop:
    digitalWrite(m_pins->left_a , LOW);
    digitalWrite(m_pins->left_b , LOW);
    digitalWrite(m_pins->right_a , LOW);
    digitalWrite(m_pins->right_b , LOW);
    analogWrite(m_pins->right_speed_pin , 0);
    analogWrite(m_pins->left_speed_pin ,0);
    break;

    default:
    dir = stop;
    break;
  }
}



