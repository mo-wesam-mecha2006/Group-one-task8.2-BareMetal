#include "gpio_interface.h"

void GPIO_Init(uint32_t port_base, uint8_t pin, uint8_t mode) {
    volatile uint32_t *moder = (volatile uint32_t *)(port_base + GPIO_MODER_OFFSET);
    volatile uint32_t *pupdr = (volatile uint32_t *)(port_base + GPIO_PUPDR_OFFSET);
    
    // 1. تهيئة الـ Mode
    *moder &= ~(0b11 << (pin * 2));
    *moder |= (mode << (pin * 2));
    
    // 2. إلغاء أي Pull-up/down داخلي (عشان الـ Pull-up الخارجي يشتغل)
    *pupdr &= ~(0b11 << (pin * 2));
}

void GPIO_WritePin(uint32_t port_base, uint8_t pin, uint8_t state) {
    volatile uint32_t *bsrr = (volatile uint32_t *)(port_base + GPIO_BSRR_OFFSET);
    if (state) {
        *bsrr = (1 << pin);          // Set pin HIGH
    } else {
        *bsrr = (1 << (pin + 16));   // Set pin LOW
    }
}

uint8_t GPIO_ReadPin(uint32_t port_base, uint8_t pin) {
    volatile uint32_t *idr = (volatile uint32_t *)(port_base + GPIO_IDR_OFFSET);
    return READ_BIT(*idr, pin);
}

void GPIO_TogglePin(uint32_t port_base, uint8_t pin) {
    volatile uint32_t *odr = (volatile uint32_t *)(port_base + GPIO_ODR_OFFSET);
    volatile uint32_t *bsrr = (volatile uint32_t *)(port_base + GPIO_BSRR_OFFSET);
    if (READ_BIT(*odr, pin)) {
        *bsrr = (1 << (pin + 16));   // Turn OFF
    } else {
        *bsrr = (1 << pin);           // Turn ON
    }
}