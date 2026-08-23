#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Priv.h"




void ADC_Init(void)
{
    /* Enable clocks */
    GPIOA_EN();
    ADC1_En();
    /* Configure PA0 as Analog
       PA0 -> MODER[1:0] = 11 */
    SET_BIT(GPIOA_MODER, 0);
    SET_BIT(GPIOA_MODER, 1);

    

    /* ADC resolution = 12-bit
       RES[25:24] = 00 */
    ADC_cr1_24();
    ADC_cr1_25();

    /* Sampling time for Channel 0 = 480 cycles
       SMP0[2:0] = 111 */
    ADC_smpr2_0();
    ADC_smpr2_1();
    ADC_smpr2_2();

    /* Select Channel 0 as SQ1
       SQR3[4:0] = 00000 */
    ADC_sqr3_0();
    ADC_sqr3_1();
    ADC_sqr3_2();
    ADC_sqr3_3();
    ADC_sqr3_4();

    /* Single conversion mode */
    ADC_cr2_CONT();

    /* Right alignment */
    ADC_cr2_ALIGN();

    /* Enable ADC */
    ADC_cr2_ADON();
}


unsigned int ADC_Read(void)
{
    /* Start conversion */
    ADC_cr2_SWSTART();

    /* Wait until conversion is complete */
    while (((ADC_SR >> 1) & 1) == 0)
    {
        /* Wait */
    }

    /* Return ADC conversion result */
    return ADC_DR & 0x0FFF;
}

