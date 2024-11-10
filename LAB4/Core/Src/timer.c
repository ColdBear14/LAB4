/*
 * timer.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Hy
 */
#include "timer.h"

void timer_red(){
	HAL_GPIO_TogglePin(GPIOA, PA4_Pin);
}

