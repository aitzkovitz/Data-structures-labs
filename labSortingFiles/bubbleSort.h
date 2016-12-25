/*
File Name:bubbleSort.h
Author: Aaron Itzkovitz
Description: File contains implementation for the bubbleSort algorithm. 
The two functions in the file are the one called in main which return a time to main. The
other function, bubbleSortMain, performs the actual algorithm using nested loops.

*/

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <time.h>
#include <utility>
#include <iostream>
#include "diffClocks.h"
// main function for bubblesort
void bubbleSortMain(int array[], int size)
{
	// boolean to know whether any swaps were made and if we can stop
	bool noSwaps = true;
	// outer loop for each iteration swapping iteration through the list, decrements the loop size effectively making the sorted portion bigger
	for (int i = size -1; i > 0; i--) {
		// loops swaps two adjacent elements when out of order
		for (int j = 0; j < i; j++) {
			if (array[j + 1] < array[j]) {
				std::swap(array[j], array[j + 1]);
				noSwaps = false;
			}
		}
		// if the array is already sorted
		if (noSwaps)
			return;
	}
}
// bubblesort method called by main
double bubbleSort(int array[], int size)
{
	clock_t begin, end;
	begin = clock();
	bubbleSortMain(array, size);
	end = clock();
	return diffClocks(end, begin);
}

#endif