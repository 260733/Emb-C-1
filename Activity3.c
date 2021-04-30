/**
 * @file Activity3.c
 * @author your Daman (damanpreet1495@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

/**
 * @brief initializing PWM
 * 
 */
void init_PWM()
{
    TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B |= (1<<CS00);
    DDRD |= (1<<PD6);
}

/**
 * @brief Comparing the output from the Sensor and give PWM
 * 
 */
void compare_adc()
{
     if (ADC>0 && ADC<200){
        OCR0A = 51;
    }
    else if(ADC > 210 && ADC < 500){
        OCR0A = 101;
    }
    else if(ADC > 510 && ADC < 700){
        OCR0A = 178;
    }
    else if (ADC > 710 && ADC < 1024){
        OCR0A = 242;
    }
}