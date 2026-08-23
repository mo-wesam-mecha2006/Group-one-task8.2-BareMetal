#ifndef ADC_PRIV_H
#define ADC_PRIV_H

#include "bit_math.h"
#include  "RCC.h"



/* GPIOA MODER */
#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOA_MODER          *((volatile unsigned long *)(GPIOA_BASE_ADDRESS + 0x00))


#define Base_Address_for_ADC1 0x40012000
#define ADC_SR *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x00))
#define ADC_CR1 *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x04))
#define ADC_CR2  *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x08))
#define ADC_SMPR2 *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x10))
#define ADC_SQR3 *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x34))
#define ADC_DR *((volatile unsigned long *)(Base_Address_for_ADC1 + 0x4C))




#define ADC_sr()  GET_BIT(ADC_SR,1) 

#define ADC_cr1_24()  CLEAR_BIT(ADC_CR1,24) 
#define ADC_cr1_25()  CLEAR_BIT(ADC_CR1,25) 

#define ADC_cr2_ADON()  SET_BIT(ADC_CR2,0) 
#define ADC_cr2_SWSTART()  SET_BIT(ADC_CR2,30)
#define ADC_cr2_CONT()  CLEAR_BIT(ADC_CR2,1) 
#define ADC_cr2_ALIGN()  CLEAR_BIT(ADC_CR2,11) 

#define ADC_smpr2_0()  SET_BIT(ADC_SMPR2,0)
#define ADC_smpr2_1()  SET_BIT(ADC_SMPR2,1) 
#define ADC_smpr2_2()  SET_BIT(ADC_SMPR2,2) 


#define ADC_sqr3_0()  CLEAR_BIT(ADC_SQR3,0) 
#define ADC_sqr3_1()  CLEAR_BIT(ADC_SQR3,1)
#define ADC_sqr3_2()  CLEAR_BIT(ADC_SQR3,2) 
#define ADC_sqr3_3()  CLEAR_BIT(ADC_SQR3,3)
#define ADC_sqr3_4()  CLEAR_BIT(ADC_SQR3,4)   




#endif 