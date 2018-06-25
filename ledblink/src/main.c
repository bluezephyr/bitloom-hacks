/*
 * Ledblink is an example hack for the BitLoom framework.  It implements a
 * simple task that blinks with a LED.
 *
 * Copyright (c) 2018. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "scheduler.h"
#include "blinktask.h"
#include "port_config.h"

static void init_port(void)
{
    // Initialize the LEDs.
    LED_DDR |= (1 << LED_GREEN);
    LED_PORT &= ~(1 << LED_GREEN);
}

int main(void)
{
    schedule_init();
    init_port();

    // Task initializations
    blink_task_init(schedule_add_task(240, 0, blink_task_run));

    schedule_start();
    while(1)
    {
        schedule_run();
    }
    return(0);
}
