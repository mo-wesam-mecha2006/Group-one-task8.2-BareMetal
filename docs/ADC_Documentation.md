# ADC Documentation by : Aya Mohamed E295
___

## Fisrt is RCC & GPIO Information Required for ADC Documentation
## 1. RCC  (Clock Enable)
- The ADC driver needs to enable the clocks for GPIOA and ADC1 before using PA0 as an ADC input.

- **RCC Base Address** : #define Base_Address_for_RCC 0x40023800

- **RCC_AHB1ENR**: 


     Required Bit: GPIOAEN → Bit 0

     Value: 1

     Purpose: Enables the clock for GPIOA.

     Macro provided:
     #define GPIOA_EN() SET_BIT(RCC_AHB1ENR, 0)

     Usage:
      GPIOA_EN();

----
- **RCC_APB2ENR:**

   Required Bit: ADC1EN → Bit 8

   Value: 1

   Purpose: Enables the clock for ADC1.

   Macro provided:
  #define ADC1_En() SET_BIT(RCC_APB2ENR, 8)

   Usage:
  ADC1_En();

------
### 2. GPIO ( Configure PA0 as Analog Input )
 - The selected ADC input is: PA0 → ADC1_IN0

 - PA0 must be in Analog mode before starting ADC conversion.

- GPIOA_MODER :

  Purpose: Selects the operating mode of GPIOA pins.

  Pin: PA0

  Required Value: 11

  Mode: Analog mode
  
-----

## Second is Information Required by the ADC Driver 
------
- Overview : 
       The STM32F401CC has one ADC module (ADC1) only, a
12-bit successive approximation analog-to-digital converter.
    It  converts an input voltage between 0V and VREF(3.3V) into a 12-bit digital value (0-4095).

-  It can measure up to 16 external channels + 2 internal channels(temperature sensor and VREFINT).

- The A/D conversion of the channels can be performed in 
single, continuous, scan or discontinuous mode.

- In scan mode, automatic conversion is performed on a selected group of analog inputs.

- The ADC can be served by the DMA controller. An analog watchdog feature allows very precise monitoring of the converted voltage of one, some or all selected channels.

- The analog watchdog feature allows the application to detect if the input voltage goes beyond the user-defined, higher or lower thresholds.

-  Interrupt generation at the end of conversion, end of injected conversion, and in case of analog watchdog or overrun events

-  The result of the ADC is stored into a left- or right-aligned 16-bit data register.

- ADC1 Base address : **0x40012000**
-  Key ADC Registers Used : 

### 1. ADC_SR (Status Register)

Address offset: **0x00**

Purpose:
   The ADC Status Register contains status flags used to monitor ADC operation and The ADC driver uses the EOC flag to determine when a conversion is complete before reading the result.

Relevant Bit: 1

Value : 1

EOC (End Of Conversion) : Indicates that the ADC conversion has completed and the converted value is ready to be read from ADC_DR.

 0: Conversion not complete (EOCS=0), or sequence of conversions not complete (EOCS=1)

 1: Conversion complete (EOCS=0), or sequence of conversions complete (EOCS=1) and  the driver reads the conversion result from ADC_DR.

How it is used: The ADC driver uses polling to wait until the conversion is completed,


### 2. ADC_CR1 (ADC Control Register 1)

Address offset: **0x04**

Purpose: The ADC Control Register 1 contains control and configuration bits for the ADC, such as resolution, scan mode, and interrupt enable bits.

Relevant Bits: 25:24

Value: 00

RES (Resolution): Selects the ADC resolution.

00: 12-bit resolution  (We will use)

01: 10-bit resolution

10: 8-bit resolution

11: 6-bit resolution

 How it is used: The ADC driver configures the ADC to use 12-bit resolution, which provides conversion results from 0 to 4095.



### 3. ADC_CR2 (ADC Control Register 2)

Address offset: **0x08**

Purpose: The ADC Control Register 2 contains control bits used to configure and start the ADC conversion, including ADC enable, continuous conversion, and software start.

Relevant Bits:

1.**ADON**(Bit 0)

Value: 1

ADON (ADC ON): Enables the ADC.

0: ADC is disabled.

1: ADC is enabled.

How it is used: The ADC driver sets ADON = 1 to enable ADC1 before starting conversions.

2.**SWSTART** (Bit 30)

Value: 1

SWSTART (Start Conversion): Starts the ADC conversion when software 
trigger is selected.

0: No conversion started.

1: Starts the ADC conversion.

How it is used: The ADC driver sets SWSTART = 1 to start the ADC conversion.


3.**CONT** (Bit 1)

Value: 0

CONT (Continuous Conversion): Controls whether the ADC continuously converts after a conversion is completed.

0: Single conversion mode.

1: Continuous conversion mode.

How it is used: The driver uses single conversion mode, so CONT = 0. Each conversion is started explicitly using SWSTART.

4.**ALIGN** (Bit 11)

Value: 0

ALIGN (Data Alignment): Determines whether the ADC conversion result is aligned to the right or left in the ADC_DR register.

0: Right alignment

1: Left alignment

How it is used: The ADC driver uses right alignment (ALIGN = 0) so the 12-bit conversion result is stored in the least significant bits of ADC_DR, making it easy to read the ADC value directly.

### 4. ADC_SMPR2 (ADC Sample Time Register 2)

Address offset: **0x10**

Purpose: The ADC Sample Time Register 2 selects the sampling time for ADC channels 0 to 9.

Relevant Bits: [2:0] (for Channel 0)

Value: 111

SMP0 (Channel 0 Sampling Time): Selects the sampling time for ADC Channel 0.

000: 3 cycles

001: 15 cycles

010: 28 cycles

011: 56 cycles

100: 84 cycles

101: 112 cycles

110: 144 cycles

111: 480 cycles

How it is used: The ADC driver configures the sampling time for the selected ADC channel before starting the conversion. 

### 5. ADC_SQR3 (ADC Regular Sequence Register 3)

Address offset: **0x34**

Purpose: The ADC Regular Sequence Register 3 defines the ADC channels that will be converted in the regular conversion sequence.

Relevant Bits: 4:0

Value: 0

Meaning: ADC1_INO is selected as the first conversion in the regular sequence.

SQ1 (1st Conversion in Regular Sequence): Selects the ADC channel that will be converted first.

0-15: ADC channel number selected for the first conversion.

How it is used: Since the task uses a single analog input, the selected ADC channel is configured as the first and only conversion in the regular sequence


### 6.ADC_DR (ADC Data Register)

Address offset: 0x4C

Purpose: The ADC Data Register contains the result of the ADC conversion. The ADC driver reads this register after the conversion is completed.

Relevant Bits: 11:0

Value: 12-bit ADC result (0-4095)

DATA: Contains the converted digital value of the analog input.

0: Minimum ADC input value.

4095: Maximum ADC input value for 12-bit resolution.

How it is used: After the driver detects that the conversion is complete by checking the EOC flag in ADC_SR, it reads the converted value from ADC_DR.


------
## Third is  Converting the Raw Value to Voltage

Voltage = (ADC_DR_value / 4095.0) * 3.3


-----
## References
1. [**Data Sheet**]  (https://www.st.com/resource/en/datasheet/stm32f401cc.pdf)   

2. [**Reference Manual**]  (https://www.st.com/resource/en/reference_manual/rm0368-stm32f401xbc-and-stm32f401xde-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)  
