/*
 * This task displays data on an OLED SSD1306 display.
 *
 * Copyright (c) 2018. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <stdbool.h>
#include "oledtask.h"

// This id is given by the scheduler when the task is added.
static uint8_t task_id = 0;

void oled_task_init (uint8_t taskid)
{
    // Set the task id
    task_id = taskid;
}


void oled_task_run (void)
{
}

