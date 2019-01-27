# BitLoom Hacks
This repository contains different small programs that use the BitLoom
framework.  The programs are implemented in C targeting different small embedded
microcontrollers; at the moment AVR (ATMega328P and ATTiny).

## LEB Blink
The LED Blink (ledblink) hack is a trivial program that flashes a LED on and
of at a regular interval (240 ms).  The program has one task (blink_task)
that turns on and off the LED using the pin_digital_io interface.  The current
implementation runs on an ATMega328P and utilizes the HAL defined by the
Bitloom core.  The timer interface and the IO interface are implemented by
the submodule bitloom-avr.  The port configuration is a custom implentation
for this specific hack.

To build the program for AVR, follow the steps below.  It is assumed that
the an AVR cross compilation toolchain is installed on the computer and that an
USBTinyISP programmer is used to flash the board.

 1. git clone https://github.com/bluezephyr/bitloom-hacks.git
 1. cd bitloom-hacks
 1. git submodule update --init
 1. mkdir ledblink/build
 1. cd ledblink/build
 1. cmake .. -DCMAKE_TOOLCHAIN_FILE=../../bitloom-avr/avr-gcc-toolchain.cmake -DCONFIG=avr_config
 1. make
 1. make flash

The program will then be flashed to the MCU and the LED connected to PIN PB1
will start to blink.


## OLED Test
The OLED Test (oledtest) is a hack to try the SSD1306 OLED display using the
Bitloom framework.  The hack is currently implemented for the ATMega328P MCU
with I2C connection to the display.  The driver for the display is implemented
in the submodule bitloom-ssd1306.  From Bitloom core, the scheduler, timer and
the I2C master is used.  The HAL interfaces for I2C and the timer is implemented
in the submodule bitloom-avr.

Work is still in progress for this hack and currently nothing is shown on the
display.
