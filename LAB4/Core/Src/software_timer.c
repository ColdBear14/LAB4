/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "software_timer.h"
#include "stdint.h"

#define TICK 10

int timer_flag[10];
int timer_counter[10];

void setTimer(int index, int counter) {
	timer_flag[index] = 0;
	timer_counter[index] = counter / TICK;
}

void timerun() {
	for (int i = 0; i < 10; i++) {
		if (timer_counter[i] >= 0) {
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
