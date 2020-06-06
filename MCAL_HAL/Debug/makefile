################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MCAL_HAL.lss \

FLASH_IMAGE += \
MCAL_HAL.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MCAL_HAL.elf secondary-outputs

# Tool invocations
MCAL_HAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MCAL_HAL.map -mmcu=atmega32 -o "MCAL_HAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MCAL_HAL.lss: MCAL_HAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MCAL_HAL.elf  >"MCAL_HAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

MCAL_HAL.hex: MCAL_HAL.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MCAL_HAL.elf  "MCAL_HAL.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MCAL_HAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MCAL_HAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MCAL_HAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
