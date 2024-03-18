 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Youssef Essam
 *
 *******************************************************************************/

#include <avr/io.h>
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 = 0; // Set Timer Initial Value to 0

	/* Equation that take percentage speed and turn it to
	 * its equivalent duty cycle needed to control the motor speed
	 */
	if(duty_cycle == 100){
		duty_cycle = ((duty_cycle/100) * 255);
	}
	else{
		duty_cycle = (uint8)(1 + ((duty_cycle/100.0) * 255));
	}

	OCR0  = duty_cycle; // Set Compare Value

	GPIO_setupPinDirection(PORTB_ID, PIN3_ID,PIN_OUTPUT);// Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

