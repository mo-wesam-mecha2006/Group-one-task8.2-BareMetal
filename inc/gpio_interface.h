#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include <stdint.h>
#include "bit_math.h"
#include "rcc.h"
#include "gpio_private.h"

// setup mode 
#define GPIO_MODE_INPUT     0
#define GPIO_MODE_OUTPUT    1
#define GPIO_MODE_AF        2
#define GPIO_MODE_ANALOG    3

// Driver functions
void GPIO_Init(uint32_t port_base, uint8_t pin, uint8_t mode);
void GPIO_WritePin(uint32_t port_base, uint8_t pin, uint8_t state);
uint8_t GPIO_ReadPin(uint32_t port_base, uint8_t pin);
void GPIO_TogglePin(uint32_t port_base, uint8_t pin);

// gpio setup main function
void GPIO_Setup(void);

#endif