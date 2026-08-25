#include "gpio_config.h"

void GPIO_Setup(void) {
    //LEDs
    GPIO_Init(LED1_PORT, LED1_PIN, LED1_MODE);
    GPIO_Init(LED2_PORT, LED2_PIN, LED2_MODE);
    GPIO_Init(LED3_PORT, LED3_PIN, LED3_MODE);

    // switches
    GPIO_Init(SW1_PORT, SW1_PIN, SW1_MODE);
    GPIO_Init(SW2_PORT, SW2_PIN, SW2_MODE);
    GPIO_Init(SW3_PORT, SW3_PIN, SW3_MODE);
}