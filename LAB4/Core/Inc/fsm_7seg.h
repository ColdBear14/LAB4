/*
 * fsm_7seg.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#ifndef INC_FSM_7SEG_H_
#define INC_FSM_7SEG_H_
#include "main.h"

extern int countDownA;
extern int countDownB;

extern int count_RED;
extern int count_GREEN;
extern int count_YELLOW;

extern void fsm_7seg_run();
extern void fsm_7segA();
extern void fsm_7segB();

#endif /* INC_FSM_7SEG_H_ */
