#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

// GPIO Ports adrsess from Reference Manual
#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800

//Offsets
#define GPIO_MODER_OFFSET   0x00
#define GPIO_OTYPER_OFFSET  0x04
#define GPIO_OSPEEDR_OFFSET 0x08
#define GPIO_PUPDR_OFFSET   0x0C
#define GPIO_IDR_OFFSET     0x10
#define GPIO_ODR_OFFSET     0x14
#define GPIO_BSRR_OFFSET    0x18

#endif