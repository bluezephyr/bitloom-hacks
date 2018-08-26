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

## OLED Test
The OLED Test (oledtest) is a hack to try the SSD1306 OLED display using the
Bitloom framework.  The hack is currently implemented for the ATMega328P MCU
with I2C connection to the display.  The driver for the display is implemented
in the submodule bitloom-ssd1306.  From Bitloom core, the scheduler, timer and
the I2C master is used.  The HAL interfaces for I2C and the timer is implemented
in the submodule bitloom-avr.

Work is still in progress for this hack and currently nothing is shown on the
display.
