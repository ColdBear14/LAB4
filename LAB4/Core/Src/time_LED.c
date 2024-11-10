/*
 * time_LED.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Hy
 */


#include "time_LED.h"

void timer_led(){
	HAL_GPIO_TogglePin(GPIOA, PA4_Pin);
}
