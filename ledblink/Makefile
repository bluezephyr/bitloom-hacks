#-----------------------------------------------------------------------------#
#			PROJECT SPECIFICS
#-----------------------------------------------------------------------------#

# Project name and source files
NAME   := ledblink
ROOT   := ..

# Name of all source files (all names must be unique)
SRC    := scheduler.c \
	  avr_timer.c \
	  avr_pin_digital_io.c \
	  avr_port_config.c \
	  main.c \
	  blinktask.c \


# Include directories (relative root)
INC    := bitloom-core/include \
	  bitloom-core/include/hal \
	  ledblink/avr_config \
	  ledblink/blinktask \


# Include directories (absolute paths)
INC_A  	:=


# VPATH is used to build all object files locally
# List all source code directories
VPATH = $(ROOT)/bitloom-core/src/scheduler \
        $(ROOT)/bitloom-avr/avr_hal \
        $(ROOT)/ledblink/src \
        $(ROOT)/ledblink/avr_config \
        $(ROOT)/ledblink/blinktask \


#-----------------------------------------------------------------------------#
#			MICROCONTROLLER DETAILS
#-----------------------------------------------------------------------------#
MCU   	= atmega328p
F_CPU 	= 8000000
BAUD 	= 9600


#-----------------------------------------------------------------------------#
#			PROGRAMMER DETAILS
#-----------------------------------------------------------------------------#
PROGRAMMER_TYPE = usbtiny
PROGRAMMER_ARGS = -b 19200


#-----------------------------------------------------------------------------#
#			MAKEFILE CORE
#-----------------------------------------------------------------------------#
.PHONY: clean all debug flash size eeprom help
CC	= avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

INC_P   = $(addprefix $(ROOT)/, $(INC))
INC_L   = $(foreach d, $(INC_P), -I$(d))
INC_AL  = $(foreach d, $(INC_A), -I$(d))
OBJ     = $(SRC:.c=.o)

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD) -Os -I. $(INC_L) $(INC_AL)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -Wall -Wstrict-prototypes -g -ggdb
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections -Wl,--relax
CFLAGS += -std=gnu99


#-----------------------------------------------------------------------------#
#			CORE TARGETS
#-----------------------------------------------------------------------------#
hex: $(NAME).hex

flash: $(NAME).hex
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<

size: $(NAME).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(NAME).elf

eeprom: $(NAME).eeprom

%.hex: %.elf
	$(OBJCOPY) -R .eeprom -O ihex $< $@

%.elf: $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@


#-----------------------------------------------------------------------------#
#			CLEAN
#-----------------------------------------------------------------------------#
clean:
	rm -rf $(OBJ)
	rm -f $(NAME).hex $(NAME).elf $(NAME).eeprom

#-----------------------------------------------------------------------------#
#			DEBUG
#-----------------------------------------------------------------------------#
debug:
	@echo "ROOT:" $(abspath $(ROOT))
	@echo "CURDIR:" $(CURDIR)
	@echo "Source files:" $(SRC)
	@echo "VPATH:" $(VPATH)
	@echo "INC_P:" $(INC_P)
	@echo "INC_AL:" $(INC_AL)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	@echo "OBJCOPY:" $(OBJCOPY)
	@echo "CC:" $(CC)
	@echo "CFLAGS:" $(CFLAGS)

#-----------------------------------------------------------------------------#
#			HELP
#-----------------------------------------------------------------------------#
help:
	@echo "The following commands are available:"
	@echo "hex (default) - Create a hexfile that can be flashed to target"
	@echo "flash         - Flash the hexfile to target using '$(AVRDUDE)'"
	@echo "size          - Get the size of the hexfile"
	@echo "eeprom        - Create a eeprom section"
	@echo "clean         - Delete all outpu files"
	@echo "debug         - Print some debug information"
	@echo "help          - Print this text"

