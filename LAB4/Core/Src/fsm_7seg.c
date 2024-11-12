/*
 * fsm_7seg.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "fsm_7seg.h"

int countDownA;
int countDownB;


void fsm_7segA() {
	switch (fsm_status_A) {
	case FSM_MAN:
		break;
	case FSM_RED:
		if (countDownA <= 0) {
			countDownA = GREEN_Timer;
			fsm_status_A= FSM_GREEN;
		}
		update_indexA(countDownA);
			countDownA--;
		break;
	case FSM_GREEN:
		if (countDownA <= 0) {
			countDownA = YELLOW_Timer;
			fsm_status_A= FSM_YELLOW;
		}
		update_indexA(countDownA);
			countDownA--;
		break;
	case FSM_YELLOW:
		if (countDownA <= 0) {
			fsm_status_A= FSM_RED;
			countDownA = RED_Timer;
		}
		update_indexA(countDownA);
			countDownA--;
		break;

	default:
		break;
	}

}

void fsm_7segB() {
	switch (fsm_status_B) {
	case FSM_MAN:
		break;
	case FSM_GREEN:
		if(countDownB <=0){
			countDownB = YELLOW_Timer;
			fsm_status_B= FSM_YELLOW;
		}
		update_indexB(countDownB);
			countDownB--;

		break;
	case FSM_YELLOW:
		if (countDownB <= 0) {
			countDownB = RED_Timer;
			fsm_status_B= FSM_RED;
		}
		update_indexB(countDownB);
			countDownB--;


		break;
	case FSM_RED:
		if (countDownB <= 0) {
			countDownB = GREEN_Timer;
			fsm_status_B= FSM_GREEN;
		}
		update_indexB(countDownB);
			countDownB--;
		break;
	default:
		break;
	}
}

void fsm_7seg_run() {
	fsm_7segA();
	fsm_7segB();
}

void display_fsm_7seg(){
	display_fsm_7segB();
	display_fsm_7segA();
}
void display_fsm_7segA(){
	switch (fsm_status_A) {
	case FSM_MAN:
		update_7seg_A();
		break;
	case FSM_RED:
		update_7seg_A();
		break;
	case FSM_GREEN:
		update_7seg_A();
		break;
	case FSM_YELLOW:
		update_7seg_A();
		break;
	default:
		break;
	}
}
void display_fsm_7segB(){
	switch (fsm_status_B) {
	case FSM_MAN:
		update_7seg_B();
		break;
	case FSM_RED:
		update_7seg_B();
		break;
	case FSM_GREEN:
		update_7seg_B();
		break;
	case FSM_YELLOW:
		update_7seg_B();
		break;
	default:
		break;
	}
}


