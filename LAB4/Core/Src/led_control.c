/*
 * led_control.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Hy
 */

#include "led_control.h"

void RED0() {
	HAL_GPIO_TogglePin(GPIOB, PA14_Pin);
}
void RED1() {
	if (IsButtonPress(0) == 1) {
		HAL_GPIO_TogglePin(GPIOB, PB15_Pin);
	}
}
