/*
 * fsm_7seg.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "fsm_7seg.h"

int countDownA;
int countDownB;

int count_RED = 5 ;
int count_GREEN = 3 ;
int count_YELLOW = 2 ;


void fsm_7segA() {
	switch (fsm_status_A) {
	case FSM:
		fsm_status_A= FSM_RED;
		break;
	case FSM_RED:
		if (countDownA <= 0) {
			countDownA = count_GREEN;
			fsm_status_A= FSM_GREEN;
		}
			update_indexA(countDownA);
			countDownA--;
		break;
	case FSM_GREEN:
		if (countDownA <= 0) {
			countDownA = count_YELLOW;
			fsm_status_A= FSM_YELLOW;
		}
			update_indexA(countDownA);
			countDownA--;
		break;
	case FSM_YELLOW:
		if (countDownA <= 0) {
			fsm_status_A= FSM_RED;
			countDownA = count_RED;
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
	case FSM:
	fsm_status_B= FSM_GREEN;
		break;
	case FSM_GREEN:
		if(countDownB <=0){
			countDownB = count_YELLOW;
			fsm_status_B= FSM_YELLOW;
		}
			update_indexB(countDownB);
			countDownB--;

		break;
	case FSM_YELLOW:
		if (countDownB <= 0) {
			countDownB = count_RED;
			fsm_status_B= FSM_RED;
		}
			update_indexB(countDownB);
			countDownB--;


		break;
	case FSM_RED:
		if (countDownB <= 0) {
			countDownB = count_GREEN;
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
