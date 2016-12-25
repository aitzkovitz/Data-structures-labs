/*
File Name: mergesort.h
Author: Aaron Itzkovitz
Description: This file contains the implementation for the mergeSort algorithm.
The file contains three main functions. The merge function takes to sorted halves within an array,
creates a new array in which the two halfs are merged together, and copies that array into the original array.
The quickSortMain function divides the array into two halves recursively until it reaches the base case
where it can finally merge the two halves. The mergesort function is called by main, calls the algorithm, and returns the time.
*/

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <vector>
#include <utility>
#include <time.h>
#include "diffClocks.h"
// merge two halves
void merge(int array[], int first, int last)
{
	int size = (last - first) + 1;
	int firstMarker = first;
	int lastMarker = ((first + last) / 2) + 1;
	int lastMarkerOrig = ((first + last) / 2) + 1;
	std::vector<int> temp(size);
	int j = 0;  

	// merge arrays together while both are still unfinised 
	while (firstMarker < lastMarkerOrig && lastMarker <= last) {

		if (array[firstMarker] <= array[lastMarker]) {
			temp[j] = array[firstMarker];
			firstMarker++;
		}
		else if (array[lastMarker] < array[firstMarker]) {
			temp[j] = array[lastMarker];
			lastMarker++;
		}
		j++;

	}

	// if last half finished before first half
	while (firstMarker < lastMarkerOrig) {
		temp[j] = array[firstMarker];
		firstMarker++;
		j++;
	}

	// if first half finished before last half
	while (lastMarker <= last) {
		temp[j] = array[lastMarker];
		lastMarker++;
		j++;
	}

	// move contents of temp into original array
	int k = 0;
	for (int i = first; i <= last; i++)
	{
		array[i] = temp[k];
		k++;
	}
}

// main mergeSort function
void mergeSortMain(int array[], int first, int last)
{
	// base case, protect against half only having one element
	if (first < last) {
		int midIndex = (first + last) / 2;
		// sort left
		mergeSortMain(array, first, midIndex);
		// sort right
		mergeSortMain(array, midIndex + 1, last);
		// merge halves
		merge(array, first, last);
	}
}

// mergesort method called by main
double mergesort(int array[], int size)
{
	clock_t begin, end;
	begin = clock();
	mergeSortMain(array, 0, size - 1);
	end = clock();
	return diffClocks(end, begin);
}
#endif // !MERGE_SORT_H

