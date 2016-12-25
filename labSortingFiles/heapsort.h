/*
File Name: heapsort.h
Author: Aaron Itzkovitz
Description: This file contains the implementation for the heapsort algorithm. 
It contains three functions. The heapsort function is called by main, calls the heapSortMain function, and returns the execution time to main. 
The heapSortMain function is the crux of the algorithm. It first heapifies the array, then continuosly takes the highest priority item, swaps
it with the last item, then fixes the heap via the bubbleDown function.

*/





#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <utility>
#include <time.h>
#include "diffClocks.h"
// bubble down method fixes heap after heap is topped
void bubbleDown( int index, int size, int array[])
{
	int child = (index * 2) + 1;
	// while child marker is in array
	while (child < size) {
		// right child is correct child if right child is in array and its value is greater than left child
		if ((child + 1 < size) && (array[child + 1] > array[child])) {
			child++;
		}
		if (array[index] < array[child]) {
			std::swap(array[index], array[child]);
		}
		else {
			break;
		}
		// update child and index to continue bubbledown
		index = child;
		child = (index * 2) + 1;
	}
}

// main heapsort function
void heapSortMain(int array[], int size)
{
	// heapify the array
	for (int i = (size / 2); i >= 0; i--) {
		bubbleDown(i, size, array);
	}

	// continuously take the highest value the fix the heap
	for (int i = size - 1; i >= 0; i--) {
		std::swap(array[0], array[i]);
		bubbleDown(0, i, array);
	}
}
// heapsort called by main whcih measures time
double heapsort(int array[], int size)
{
	clock_t begin, end;
	begin = clock();
	heapSortMain(array, size);
	end = clock();
	return diffClocks(end, begin);
}




#endif
