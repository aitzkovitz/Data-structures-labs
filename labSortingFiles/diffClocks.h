/*
File Name: duffClocks.h
Author: Aaron Itzkovitz
Description: This file contains a function used for measuring the time an algorithm takes. 
It subtracts the ending time from the starting time.
*/

#ifndef DIFF_CLOCKS_H
#define DIFF_CLOCKS_H
#include <time.h>

// function for measuring time of algorithm
double diffClocks(clock_t clock1, clock_t clock2) {
	double diffticks = clock1 - clock2;
	double diffsecs = diffticks / CLOCKS_PER_SEC;
	return diffsecs;
}

#endif