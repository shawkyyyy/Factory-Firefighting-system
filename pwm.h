 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the Pwm driver
 *
 * Author: Youssef Essam
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get PWM To start
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
