# STM32F401CC Bare-Metal Makefile
TARGET = project

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
OBJCOPY = $(PREFIX)objcopy
SIZE = $(PREFIX)size

MCU = cortex-m4
FPU = -mfpu=fpv4-sp-d16 -mfloat-abi=hard

BUILD_DIR = build
SRC_DIR = src
INC_DIR = inc

# قائمة بكل ملفات المصدر (محددة بوضوح)
C_SOURCES = $(SRC_DIR)/startup.c \
            $(SRC_DIR)/gpio.c \
            $(SRC_DIR)/gpio_setup.c \
            $(SRC_DIR)/mainTest.c

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES))

# خيارات المترجم (مع -O0 لمنع التحسين العشوائي)
CFLAGS = -mcpu=$(MCU) $(FPU) -Wall -O0 -fdata-sections -ffunction-sections
CFLAGS += -I$(INC_DIR)
CFLAGS += -DSTM32F401xC

# خيارات الرابط
LDFLAGS = -mcpu=$(MCU) $(FPU) -TSTM32F401CCUX_FLASH.ld
LDFLAGS += -Wl,--gc-sections -Wl,-Map=$(BUILD_DIR)/$(TARGET).map

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf
	$(OBJCOPY) -O ihex $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf
	$(OBJCOPY) -O binary -S $< $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

# عرض التعليمات
help:
	@echo "الأوامر المتاحة:"
	@echo "  make          - بناء المشروع وإنتاج ملفات HEX و BIN و ELF"
	@echo "  make clean    - حذف مجلد build بالكامل"
	@echo "  make help     - عرض هذه التعليمات"