
# Specify the compiler to use
CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++
# Specify the assembler to use
AS=arm-none-eabi-as
# Specity the linker to use
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
STRIP=arm-none-eabi-strip
JLINKEXE = /usr/bin/JLinkExe
JLINKOPT = -device xmc1100-64 -if SWD -speed 400

CCFLAGS=-mcpu=cortex-m0 -mthumb -g
CXXFLAGS=-mcpu=cortex-m0 -mthumb -g

LIBSPEC=-L /usr/lib/arm-none-eabi/lib/armv6-m/
LDFLAGS=$(LIBSPEC) -T linker_script.ld -lc --cref
########################
define SEGGER_FLASH_SOFTDEVICE_CMD
r
loadbin main.bin 0x10001000
r
g
exit
endef

########################
export SEGGER_FLASH_SOFTDEVICE_CMD

# List the object files involved in this project
OBJS=	init.o \
	main.o

TARGET=main
all: $(OBJS) $(TARGET).bin $(TARGET).hex

$(TARGET).elf: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -Map $(TARGET).map -nostartfiles -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

# compile the source 
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	#$(STRIP) $@
%.o: %.c
	$(CC) -c $(CCFLAGS) -o $@ $<
	#$(STRIP) $@


flash: $(TARGET).bin
	@echo "$$SEGGER_FLASH_SOFTDEVICE_CMD" | $(JLINKEXE) $(JLINKOPT)

# if someone types in 'make clean' then remove all object files and executables
# associated wit this project
clean: 
	rm -f $(OBJS) $(TARGET).map $(TARGET).bin $(TARGET).hex  $(TARGET).elf
