/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "fsm_automatic.h"

int RED_Timer = 5;
int YELLOW_Timer = 2;
int GREEN_Timer = 3;

int Count_LED_A;
int Count_LED_B;


void fsm_automatic_run_A(){

	switch (status_A) {
		case AUTO_RED:
			if(Count_LED_A <= 0 ){
				status_A = AUTO_GREEN;
				Count_LED_A = GREEN_Timer;
			}
			status_LED_A();
			displayTraffic();
				Count_LED_A--;
			break;
		case AUTO_GREEN:
			if(Count_LED_A <= 0 ){
				status_A = AUTO_YELLOW;
				Count_LED_A = YELLOW_Timer;
			}
			status_LED_A();
			displayTraffic();
				Count_LED_A--;
			break;
		case AUTO_YELLOW:
			if(Count_LED_A <= 0 ){
				status_A= AUTO_RED;
				Count_LED_A = RED_Timer;
			}
			status_LED_A();
			displayTraffic();
				Count_LED_A--;
			break;
		default:
			break;
		}
}

void fsm_automatic_run_B(){
	switch (status_B) {
		case AUTO_GREEN:
			if(Count_LED_B <= 0 ){
				status_B= AUTO_YELLOW;
				Count_LED_B = YELLOW_Timer;
			}
			status_LED_B();
			displayTraffic();
				Count_LED_B--;
			break;
		case AUTO_YELLOW:
			if(Count_LED_B <= 0 ){
				status_B= AUTO_RED;
				Count_LED_B = RED_Timer;
			}
			status_LED_B();
			displayTraffic();
				Count_LED_B--;
			break;
		case AUTO_RED:
			if(Count_LED_B <= 0 ){
				status_B= AUTO_GREEN;
				Count_LED_B = GREEN_Timer;
			}
			status_LED_B();
			displayTraffic();
				Count_LED_B--;

			break;
		default:
			break;
		}
}

void fsm_automatic_run() {
	fsm_automatic_run_A();
	fsm_automatic_run_B();
}
