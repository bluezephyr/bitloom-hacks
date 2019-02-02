/*
 * LCD is an example hack for the BitLoom framework.  It implements a
 * simple task that uses a LCD display.
 *
 * Copyright (c) 2018. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "core/scheduler.h"
#include "hal/timer.h"

int main(void)
{
    timer_init();
    schedule_init();

    // Task initializations

    schedule_start();
    while(1)
    {
        schedule_run();
    }
    return(0);
}
