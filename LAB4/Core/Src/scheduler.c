/*
 * scheduler.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Hy
 */

#include "scheduler.h"

#define TICK 10

sTask SCH_tasks_G[SCH_MAX_TASK];
uint8_t current_index_task = 0;

void SCH_Init(void) {
	current_index_task = 0;
}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	if (current_index_task < SCH_MAX_TASK) {
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY / TICK;
		SCH_tasks_G[current_index_task].Period = PERIOD / TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}
void SCH_Update(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].Delay > 0) {
			SCH_tasks_G[i].Delay--;
		} else {
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period == 0){
				SCH_Delete(i);
			}
		}

	}
}

void SCH_Delete(uint32_t ID) {
	uint32_t i;
	for ( i = ID; i < SCH_MAX_TASK  ; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i+1];
	}
}
