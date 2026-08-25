#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "gpio_interface.h"

// LEDs (outputs) 
#define LED1_PORT   GPIOA_BASE
#define LED1_PIN    5
#define LED1_MODE   GPIO_MODE_OUTPUT

#define LED2_PORT   GPIOA_BASE
#define LED2_PIN    6
#define LED2_MODE   GPIO_MODE_OUTPUT

#define LED3_PORT   GPIOA_BASE
#define LED3_PIN    7
#define LED3_MODE   GPIO_MODE_OUTPUT

// switches   (Inputs)
#define SW1_PORT    GPIOA_BASE
#define SW1_PIN     3
#define SW1_MODE    GPIO_MODE_INPUT

#define SW2_PORT    GPIOA_BASE
#define SW2_PIN     1
#define SW2_MODE    GPIO_MODE_INPUT

#define SW3_PORT    GPIOA_BASE
#define SW3_PIN     2
#define SW3_MODE    GPIO_MODE_INPUT

#endif