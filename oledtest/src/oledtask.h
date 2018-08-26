/*
 * This task displays data on an OLED SSD1306 display.
 *
 * Copyright (c) 2018. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 *
 */
#ifndef OLEDTASK_H
#define OLEDTASK_H

#include <stdint.h>

/*
 * Init function. Must be called before the scheduler is started.
 * The id is the task id and is pro
 */
void oled_task_init (uint8_t taskid);

/*
 * Run function for the task. Called by the scheduler.
 */
void oled_task_run (void);

#endif // OLEDTASK_H
