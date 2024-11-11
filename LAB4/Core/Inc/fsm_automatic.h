/*
 * fsm_automatic.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"
#include "global.h"


extern int RED_Timer ;
extern int YELLOW_Timer ;
extern int GREEN_Timer ;

extern void status_LEDA();
extern void status_LEDB();

extern void fsm_automatic_run_A();
extern void fsm_automatic_run_B();
extern void fsm_automatic_run();



#endif /* INC_FSM_AUTOMATIC_H_ */
