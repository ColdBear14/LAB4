/*
 * control_7seg.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Hy
 */

#ifndef INC_CONTROL_7SEG_H_
#define INC_CONTROL_7SEG_H_

#include "main.h"

extern int buffer_indexA[2];
extern int buffer_indexB[2];

void update_switch();

void clearA();
void clearB();

extern void display7SEGA(int index);
extern void display7SEGB(int index);

extern void update_indexA(int index);
extern void update_indexB(int index);

extern void update_7seg_A();
extern void update_7seg_B();



#endif /* INC_CONTROL_7SEG_H_ */
