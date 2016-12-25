/*
File Name:quicksort.h
Author: Aaron Itzkovitz
Description: This file contains the implementation for quicksort.
The file contains four different function. The quicksort function is called my main, 
calls the algorithm, then returns the time. The quicksortMain function is the crux of the algorithm
and it recursively splits the array range it is passed around the sorted median. It acheives this via 
the partition function which splits the array into two portions and puts the sorted pivot in the middle.
THis is achieved by calling the median function on the first middle and last vales of the array range.
*/

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <utility>
#include <time.h>
#include <iostream>
#include "diffClocks.h"
// prototypes
int partition(int array[], int first, int last);
int median(int array[], int first, int last);

void quickSortMain(int array[], int first, int last) {
	if (first < last) {
		// choose pivot p, and separate values into {<P} P {>P}
		int pivotIndex = partition(array, first, last);

		// recursively sort each partition
		quickSortMain(array, first, pivotIndex - 1);
		quickSortMain(array, pivotIndex + 1, last);
	}
}

// method partitions array and returns pivotIndex for use in subsequent recursive calls
int partition(int array[], int first, int last)
{
	// pivotIndex = median of array
	int pivotIndex = median(array, first, last);
	// value of pivotIndex for comparison
	int pivot = array[pivotIndex];
	// marker for division between sets
	int partitionDivide = first;
	// get pivot out of the way
	std::swap(array[first], array[pivotIndex]);

	// move items out of unknown section
	for (int firstUnknown = first;  firstUnknown <= last; ++firstUnknown) {
		if (array[firstUnknown] < pivot) {
			partitionDivide++;
			std::swap(array[firstUnknown], array[partitionDivide]);
		}
	}
	
	// move swap into sorted position
	std::swap(array[first], array[partitionDivide]);
	return partitionDivide;
}

// method called by main
double quicksort(int array[], int size)
{
	clock_t begin, end;
	begin = clock();
	quickSortMain(array, 0, size - 1);
	end = clock();
	return diffClocks(end, begin);
}

// brings median pivot it index 0
int median(int array[], int first, int last)
{
	int mid = ((first + last) / 2);
	if ((array[first] - array[mid]) * (array[last] - array[first]) >= 0) {
		return first;
	}
	else if ((array[mid] - array[first]) * (array[last] - array[mid]) >= 0) {
		return mid;
	}
	else {
		return last;
	}
}

#endif // !QUICK_SORT_H

