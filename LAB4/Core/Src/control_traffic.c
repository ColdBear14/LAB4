/*
 * control_traffic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "control_traffic.h"

int status_RED_A = 1;
int status_GREEN_A = 0;
int status_YELLOW_A = 0;

int status_RED_B = 0;
int status_GREEN_B = 1;
int status_YELLOW_B = 0;


void displayTraffic() {
	//group a
	if (status_RED_A == 1) {
		HAL_GPIO_WritePin(GPIOA, PA5_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, PA6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA7_Pin, RESET);
	}
	if (status_YELLOW_A == 1) {
		HAL_GPIO_WritePin(GPIOA, PA5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA6_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, PA7_Pin, RESET);
	}
	if (status_GREEN_A == 1) {
		HAL_GPIO_WritePin(GPIOA, PA5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA7_Pin, SET);
	}
	//group b
	if (status_RED_B == 1) {
		HAL_GPIO_WritePin(GPIOA, PA8_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, PA9_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA10_Pin, RESET);
	}
	if (status_YELLOW_B == 1) {
		HAL_GPIO_WritePin(GPIOA, PA8_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA9_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, PA10_Pin, RESET);
	}
	if (status_GREEN_B == 1) {
		HAL_GPIO_WritePin(GPIOA, PA8_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA9_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, PA10_Pin, SET);
	}
}

void status_LED_A() {
	switch (status_A) {
	case AUTO_RED:
		status_RED_A = 1;
		status_GREEN_A = 0;
		status_YELLOW_A = 0;
		break;
	case MAN_RED:
		status_RED_A = 1;
		status_GREEN_A = 0;
		status_YELLOW_A = 0;
		break;
	case AUTO_GREEN:
		status_RED_A = 0;
		status_GREEN_A = 1;
		status_YELLOW_A = 0;
		break;
	case MAN_GREEN:
		status_RED_A = 0;
		status_GREEN_A = 1;
		status_YELLOW_A = 0;
		break;
	case AUTO_YELLOW:
		status_RED_A = 0;
		status_GREEN_A = 0;
		status_YELLOW_A = 1;
		break;
	case MAN_YELLOW:
		status_RED_A = 0;
		status_GREEN_A = 0;
		status_YELLOW_A = 1;
		break;
	default:
		break;
	}
}

void status_LED_B(){
	switch (status_B) {
	case AUTO_RED:
		status_RED_B = 1;
		status_GREEN_B = 0;
		status_YELLOW_B = 0;
		break;
	case AUTO_GREEN:
		status_RED_B = 0;
		status_GREEN_B = 1;
		status_YELLOW_B = 0;
		break;
	case AUTO_YELLOW:
		status_RED_B = 0;
		status_GREEN_B = 0;
		status_YELLOW_B = 1;
		break;
	case MAN_RED:
		status_RED_B = 1;
		status_GREEN_B = 0;
		status_YELLOW_B = 0;
		break;
	case MAN_GREEN:
		status_RED_B = 0;
		status_GREEN_B = 1;
		status_YELLOW_B = 0;
		break;
	case MAN_YELLOW:
		status_RED_B = 0;
		status_GREEN_B = 0;
		status_YELLOW_B = 1;
		break;
	default:
		break;
	}
}
