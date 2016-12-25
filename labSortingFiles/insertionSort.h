/*
File Name: insertionSort.h
Author: Aaron Itzkovitz
Description: File contains the implementation for insertionSort. 
The two functions in the file are the main function, insertionSortMain which actually executes the algorithm. 
THe other function is called by main, calls the sorting algorithm, and returns the time it took.


*/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <time.h>
#include <utility>
#include <iostream>
#include "diffClocks.h"

// main insertion sort function
void insertionSortMain(int array[], int size)
{
	// outer loop takes care of inserts
	for (int i = 1; i < size; i++)						
	{
		int itemToInsert = array[i];
		int j = i;
		// inner loop takes care of shifts
		while (j > 0 && array[j - 1] > itemToInsert) {		
			array[j] = array[j-1];
			j--;
		}
		array[j] = itemToInsert;
	}
}

// insertion sort called by main
double insertionSort(int array[], int size)
{
	clock_t begin, end;
	begin = clock();
	insertionSortMain(array, size);
	end = clock();
	return diffClocks(end, begin);
}

#endif