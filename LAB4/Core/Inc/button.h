/*
 * button.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Hy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET

extern int button_flag[5];

extern int IsButtonPress(int index);
extern void subKeyProcess(int index);
int getIndex(int index);

extern void getKeyInput();

#endif /* INC_BUTTON_H_ */
