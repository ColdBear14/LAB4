/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "fsm_automatic.h"

int RED_Timer = 5000;
int YELLOW_Timer = 2000;
int GREEN_Timer = 3000;


void fsm_automatic_run_A(){
	status_LED_A();
	switch (status_A) {
		case INIT:
			status_A = AUTO_RED;
			setTimer(1, RED_Timer);
			break;
		case AUTO_RED:
			displayTraffic();
			if (timer_flag[1] == 1) {
				status_A = AUTO_GREEN;
				setTimer(1, GREEN_Timer);
			}
			break;
		case AUTO_GREEN:
			displayTraffic();
			if (timer_flag[1] == 1) {
				status_A = AUTO_YELLOW;
				setTimer(1, YELLOW_Timer);
			}

			break;
		case AUTO_YELLOW:
			displayTraffic();
			if (timer_flag[1] == 1) {
				status_A = AUTO_RED;
				setTimer(1, RED_Timer);
			}
			break;
		default:
			break;
		}
}

void fsm_automatic_run_B(){
	status_LED_B();
	switch (status_B) {
		case INIT:
			status_B = AUTO_GREEN;
			setTimer(2, GREEN_Timer);
			break;
		case AUTO_GREEN:
			displayTraffic();
			if (timer_flag[2] == 1) {
				status_B = AUTO_YELLOW;
				setTimer(2, YELLOW_Timer);
			}

			break;
		case AUTO_YELLOW:
			displayTraffic();
			if (timer_flag[2] == 1) {
				status_B = AUTO_RED;
				setTimer(2, RED_Timer);
			}

			break;
		case AUTO_RED:
			displayTraffic();
			if (timer_flag[2] == 1) {
				status_B = AUTO_GREEN;
				setTimer(2, GREEN_Timer);
			}

			break;
		default:
			break;
		}
}

void fsm_automatic_run() {
	fsm_automatic_run_A();
	fsm_automatic_run_B();
}
