/*
 * OLEDTEST is an example hack for the BitLoom framework.  It implements a
 * simple task that displays data on an SSD1306 OLED display.
 *
 * Copyright (c) 2018. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "scheduler.h"
#include "timer.h"
#include "i2c.h"
#include "i2c_master.h"
#include "ssd1306.h"
#include "oledtask.h"

int main(void)
{
    timer_init();
    schedule_init();
    i2c_init();

    // Task initializations (tasks A, B, C, ... etc)
    // Run sequence: ... A B A C A B A C A ...
    i2c_master_init(schedule_add_task(2, 0, i2c_master_run));
    ssd1306_init(schedule_add_task(4, 2, ssd1306_run));
    oled_task_init(schedule_add_task(4, 3, oled_task_run));

    schedule_start();
    while(1)
    {
        schedule_run();
    }
    return(0);
}
