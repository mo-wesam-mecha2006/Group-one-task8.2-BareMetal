#ifndef RCC_H_
#define RCC_H_

#include "bit_math.h"

#define Base_Address_for_RCC 0x40023800


#define RCC_AHB1ENR *((volatile unsigned long *)(Base_Address_for_RCC + 0x30))  /*AHB1ENR address offset = 0x30 (page 118)*/
#define RCC_APB2ENR *((volatile unsigned long *)(Base_Address_for_RCC + 0x44))  /*APB1ENR address offset = 0x44 (page 122)*/

#define GPIOA_EN()  SET_BIT(RCC_AHB1ENR,0)  /*Enable GPIOA clock*/
#define GPIOB_EN()  SET_BIT(RCC_AHB1ENR,1)  /*Enable GPIOB clock*/
#define GPIOC_EN()  SET_BIT(RCC_AHB1ENR,2)  /*Enable GPIOC clock*/

#define ADC1_En()  SET_BIT(RCC_APB2ENR,8)  /*Enable ADC1 clock*/


#endif 
