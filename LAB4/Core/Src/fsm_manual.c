/*
 * fsm_manual.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */


#include "fsm_manual.h"


void fsm_manual_run_A() {
	status_LED_A();
	switch (status_A) {
	case MAN_RED:
		displayTraffic();
		update_indexA(count_RED);
		break;
	case MAN_GREEN:
		displayTraffic();
		break;
	case MAN_YELLOW:
		displayTraffic();
		break;
	default:
		break;
	}
}
void fsm_manual_run_B() {
	status_LED_B();
	switch (status_B) {
	case MAN_RED:
		displayTraffic();
		update_indexB(MODE2);
		break;
	case MAN_GREEN:
		displayTraffic();
		update_indexB(MODE4);
		break;
	case MAN_YELLOW:
		displayTraffic();
		update_indexB(MODE3);
		break;
	default:
		break;
	}
}

void fsm_manual_run() {
fsm_manual_run_A();
fsm_manual_run_B();
}
