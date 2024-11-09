/*
 * button.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Hy
 */
#include "button.h"

int KeyReg0[5] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[5] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[5] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[5] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress[5] = {300,300,300,300,300};

int button_flag[5];
int button_LongPress_flag[5];

int IsButtonPress(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}


void subKeyProcess(int index) {
	button_flag[index] = 1;
}

int getIndex(int index) {
	switch(index){
		case 1:
			return HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
			break;
		case 2:
			return HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
			break;
		case 3:
			return HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
			break;
		default:
			break;
	}
	return 0;
}

void getKeyInput() {
	for (int i = 0; i < 5; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		KeyReg2[i] = getIndex(i) ;

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESS_STATE) {
					//todo
					subKeyProcess(i);
					TimerForKeyPress[i] = 300;

				}
			} else {
				TimerForKeyPress[i]--;
				if (TimerForKeyPress[i] == 0) {
					//todo
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}

