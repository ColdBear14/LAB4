/*
 * global.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define MODE0 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

#define AUTO_RED 12
#define AUTO_YELLOW 13
#define AUTO_GREEN 14

#define MAN_RED 22
#define MAN_YELLOW 23
#define MAN_GREEN 24


#define FSM_MAN 31
#define FSM_RED 32
#define FSM_YELLOW 33
#define FSM_GREEN 34

extern int status_A;
extern int status_B;
extern int status_mode;

int fsm_status_A;
int fsm_status_B;

#endif /* INC_GLOBAL_H_ */
