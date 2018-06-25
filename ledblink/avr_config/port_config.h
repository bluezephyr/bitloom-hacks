#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

#include <avr/io.h>
#include <stdint.h>

/*
 * LED config
 *
 * The following needs to be set.
 *
 * LED_DDR  - DDR for the LED
 * LED_PORT - Port for the LED
 * LED      - The pin where the LED is connected.
 */
#define LED_PORT    PORTB
#define LED_DDR     DDRB
#define LED_GREEN   PB1

#endif  // PORT_CONFIG_H
