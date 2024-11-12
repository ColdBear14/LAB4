/*
 * fsm_setting.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#include "fsm_setting.h"

int countTemp = 0 ;


void countPressButton1(){
	if(IsButtonPress(0) == 1){
		status_mode++;
	}
	if(status_mode == MODE4 + 1){
		status_mode = MODE0;
	}
}

void fsm_mode(){
	countPressButton1();
	switch(status_mode){
	case MODE0:
		status_mode = MODE1;
		status_A = AUTO_RED;
		status_B = AUTO_GREEN;

		fsm_status_A = FSM_RED;
		fsm_status_B = FSM_GREEN;

		Count_LED_A = RED_Timer;
		Count_LED_B = GREEN_Timer;

		countDownA=RED_Timer;
		countDownB=GREEN_Timer;

		break;
	case MODE1:
		if(IsButtonPress(0) == 1){
			status_mode = MODE2;
		}
		break;
	case MODE2:
		status_A = MAN_RED;
		status_B = MAN_RED;
		fsm_status_A = FSM_MAN;
		fsm_status_B = FSM_MAN;
		if(IsButtonPress(0) == 1){
			status_mode = MODE3;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			RED_Timer = RED_Timer + countTemp;
			countTemp=0;
		}
		break;
	case MODE3:
		status_A = MAN_YELLOW;
		status_B = MAN_YELLOW;
		fsm_status_A = FSM_MAN;
		fsm_status_B = FSM_MAN;
		if(IsButtonPress(0) == 1){
			status_mode = MODE4;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			YELLOW_Timer = YELLOW_Timer + countTemp;
			countTemp=0;
		}
		break;
	case MODE4:
		status_A = MAN_GREEN;
		status_B = MAN_GREEN;
		fsm_status_A = FSM_MAN;
		fsm_status_B = FSM_MAN;
		if(IsButtonPress(0) == 1){
			status_mode = MODE0;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			GREEN_Timer = GREEN_Timer + countTemp;
			countTemp=0;
		}
		break;
	default:
		break;
	}
}
