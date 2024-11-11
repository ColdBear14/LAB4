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
		status_A = INIT;
		status_B = INIT;
		countDownA=count_RED;
		countDownB=count_GREEN;
		break;
	case MODE1:
		if(IsButtonPress(0) == 1){
			status_mode = MODE2;
		}
		break;
	case MODE2:
		status_A = MAN_RED;
		status_B = MAN_RED;
		if(IsButtonPress(0) == 1){
			status_mode = MODE3;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			RED_Timer = RED_Timer + countTemp*1000;
			count_RED += countTemp;
			countTemp=0;
		}
		break;
	case MODE3:
		status_A = MAN_YELLOW;
		status_B = MAN_YELLOW;
		if(IsButtonPress(0) == 1){
			status_mode = MODE4;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			YELLOW_Timer = YELLOW_Timer + countTemp*1000;
			count_YELLOW += countTemp;
			countTemp=0;
		}
		break;
	case MODE4:
		status_A = MAN_GREEN;
		status_B = MAN_GREEN;
		if(IsButtonPress(0) == 1){
			status_mode = MODE0;
		}
		if(IsButtonPress(1) == 1){
			// add value
			countTemp+=2;
		}
		if(IsButtonPress(2) == 1){
			//set value
			GREEN_Timer = GREEN_Timer + countTemp*1000;
			count_GREEN += countTemp;
			countTemp=0;
		}
		break;
	default:
		break;
	}
}
