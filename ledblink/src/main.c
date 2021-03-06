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

#include "core/scheduler.h"
#include "hal/timer.h"
#include "config/port_config.h"
#include "blinktask.h"

int main(void)
{
    timer_init();
    schedule_init();
    port_init();

    // Task initializations
    blink_task_init(schedule_add_task(240, 0, blink_task_run));

    schedule_start();
    while(1)
    {
        schedule_run();
    }
    return(0);
}
