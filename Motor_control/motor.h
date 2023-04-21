
#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include "stm32f0xx.h"

/* -------------------------------------------------------------------------------------------------------------
 *  Global Variable and Type Declarations
 *  -------------------------------------------------------------------------------------------------------------
 */
extern volatile int16_t error_integral;    // Integrated error signal
extern volatile uint8_t duty_cycle;    // Output PWM duty cycle
extern volatile int16_t target_rpm;    // Desired speed target
extern volatile int16_t motor_speed;   // Measured motor speed
extern volatile int8_t adc_value;      // ADC measured motor current
extern volatile int16_t error;         // Speed error signal
extern volatile uint8_t Kp;            // Proportional gain
extern volatile uint8_t Ki;            // Integral gain

extern volatile int16_t left_error_integral;    // Integrated error signal
extern volatile uint8_t left_duty_cycle;    // Output PWM duty cycle
extern volatile int16_t left_target_rpm;    // Desired speed target
extern volatile int16_t left_motor_speed;   // Measured motor speed
extern volatile int8_t left_adc_value;      // ADC measured motor current
extern volatile int16_t left_error;         // Speed error signal
extern volatile uint8_t left_Kp;            // Proportional gain
extern volatile uint8_t left_Ki;            // Integral gain

extern volatile int16_t right_error_integral;    // Integrated error signal
extern volatile uint8_t right_duty_cycle;    // Output PWM duty cycle
extern volatile int16_t right_target_rpm;    // Desired speed target
extern volatile int16_t right_motor_speed;   // Measured motor speed
extern volatile int8_t right_adc_value;      // ADC measured motor current
extern volatile int16_t right_error;         // Speed error signal
extern volatile uint8_t right_Kp;            // Proportional gain
extern volatile uint8_t right_Ki;            // Integral gain
/* -------------------------------------------------------------------------------------------------------------
 *  Motor Control and Initialization Functions
 * -------------------------------------------------------------------------------------------------------------
 */

// Sets up the entire motor drive system
void motor_init(void);
void left_motor_init(void);
void right_motor_init(void);

// Set the duty cycle of the PWM, accepts (0-100)
void pwm_setDutyCycle(uint8_t duty);
void left_setDutyCycle(uint8_t left_duty);
void right_setDutyCycle(uint8_t right_duty);

// PI control code is called within a timer interrupt
void PI_update(void);
void left_PI_update(void);
void right_PI_update(void);

/* -------------------------------------------------------------------------------------------------------------
 *  Internal-Use Initialization Functions
 * -------------------------------------------------------------------------------------------------------------
 */

// Sets up the PWM and direction signals to drive the H-Bridge
void pwm_init(void);
void left_pwm_init(void);
void right_pwm_init(void);

// Sets up encoder interface to read motor speed
void encoder_init(void);
void left_encoder_init(void);
void right_encoder_init(void);

// Sets up ADC to measure motor current
void ADC_init(void);
void left_ADC_init(void);
void right_ADC_init(void);

#endif /* MOTOR_H_ */
