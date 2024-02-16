#include "motor.h"
#include "stdint.h"

/*
create enumerator to track and control motor direction
for example:
            Direction dir;
            the possible values for dir are:
                               (forward , backward and stop)
*/

/*
1)create structure for motor pins and ultrasonic pins:
for example:    Motor_pins mPins;


2)Create structures for ultrasonic sensors
if you have multiple sensors , create multiple structures
For example : Ultrasonic_pins us_1;
              Ultrasonic_pins us_2;
              Ultrasonic_pins us_3 and etc.
*/

void setup() {
  // put your setup code here, to run once:
/*
define pinouts for created motor and ultrasonic sensor
structures. For example motor sturcture:
                          mPins.right_a = pin number (for ex 5)
                          mPins.right_b = pin number (for ex 6)
                          mPins.left_a = pin number
                          mPins.left_b = pin_number
                          mPins.right_speed_pin = pin number
                          mPins.left_speed_pin = pin number
if you will not control motor by speed dont assign argument to speed pins
if you will contril the motors by speed the speed pins should be
PWM supported pins
*/

/*
define pinouts for created ultrasonic structure:
                          us_1.trig_pin = pin number
                          us_1.echo_pin = pin number
                          us_1.echo_pin = pin number
                          us_3.echo_pin = pin number and etc
*/



/*
initialise the motor and sensors to work properly , 
you should pass the structures to functions by reference
for example:
motor_init_struct(&mPins);
ultrasonic_init(&us_1);
ultrasonic_init(&us_2);
ultrasonic_init(&us_3);
and etc.
*/
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
  you should read the sensor values and create your logic
  return value is float (distance in cm) and the pass value is
  reference to your ultrasonic sensor structure
  for example:
              float right_sensor = read_distance(&us_1);
              float left_sensor = read_distance(&us_2);
              float front_sensor = read_distance(&us_3);
              and etc.
  */


  /*

  after you create and get result from your logic run the
  motors with motor_run() function , the possible arguments
  that motor_run() function take reference are;
                                 your motor_pin structure,
                                 speed and direction enum
            for example:
            dir = forward;
            speed = 255;
                  motor_run(&mPins ,speed , dir);


  */
}

