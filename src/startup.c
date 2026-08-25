// src/startup.c - Minimal startup for STM32F401 on Proteus

int main(void);
__attribute__((section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    (void (*)(void))0x20004000,   // Stack pointer (top of RAM)
    (void (*)(void))main,         // Reset_Handler = main
};

void NMI_Handler(void)          { while(1); }
void HardFault_Handler(void)    { while(1); }
void MemManage_Handler(void)    { while(1); }
void BusFault_Handler(void)     { while(1); }
void UsageFault_Handler(void)   { while(1); }
void SVC_Handler(void)          { while(1); }
void DebugMon_Handler(void)     { while(1); }
void PendSV_Handler(void)       { while(1); }
void SysTick_Handler(void)      { while(1); }

