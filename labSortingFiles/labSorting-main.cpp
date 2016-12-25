#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
#include <new>          // std::bad_alloc
#include <vector>
#include <string>
#include <algorithm>    // std::sort
#include <cstring>      // memcpy

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::ofstream;

#include "insertionSort.h"
#include "bubbleSort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

// callback function that takes arguments of an int* and an int.  For example, insertionSort(int* array, int count)
typedef double(*SortingFunction)(int*, int);

// Populate array with random values (using the same seed each time)
void setRandomValues(int array[], int size, time_t seed = time(NULL)) {

	/* initialize random seed: */
	srand((unsigned int)seed); // seed the random number generator

							   // cerr << "Unsorted array:\n";
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
		// cerr << array[i] << " ";
	}
	// cerr << endl;
}

// use a library sorting algorithm to sort array
void setAnswerKey(int array[], int size) {
	std::sort(array, array + size);
}


// compare the values in array and answers
void verifySort(int array[], int answers[], int size) {
	for (int i = 0; i < size; i++) {
		if (array[i] != answers[i]) {
			int r;
			cerr << "ERROR: Array not sorted at index " << i << ": (" << array[i] << " should've been " << answers[i] << ")!\n";
			cin >> r;
			exit(2);
		}
	}
}

const int DEFAULT_N = 1000;
const string DEFAULT_OUTPUT_FILENAME = "labSorting-outputA.txt";

int main(int argc, char* argv[]) {

	int maxN = -1;     // largest array size
	int* arrayOrig; // array of random elements
	int* array;     // array of random elements (copied from arrayOrig)
	int* answers;   // sorted array (used for verification)
	time_t seed;    // seed for random number generator

	vector< string> sortingFunctionNames;
	vector< SortingFunction > sortingFunctionCallbacks;

	string outputFilename;
	ofstream outfile;
	string inputLine;

	//sortingFunctionNames.push_back("Insert");
	//sortingFunctionNames.push_back("Bubble");
	sortingFunctionNames.push_back("Heap");
	sortingFunctionNames.push_back("Merge");
	sortingFunctionNames.push_back("Quick");

	//sortingFunctionCallbacks.push_back(insertionSort);
	//sortingFunctionCallbacks.push_back(bubbleSort);
	sortingFunctionCallbacks.push_back(heapsort);
	sortingFunctionCallbacks.push_back(mergesort);
	sortingFunctionCallbacks.push_back(quicksort);

	/*
	* get N from STDIN
	*/
	// If just a return ('\n') is entered, then use DEFAULT_N.
	// Otherwise, read N from STDIN.
	cout << "Please specify the largest array size: (or simply press return to use " << DEFAULT_N << ")\n";
	getline(cin, inputLine);
	if (inputLine == "") {
		maxN = DEFAULT_N;
	}
	else {
		maxN = atoi(inputLine.c_str());
	}

	/*
	* Get output filename
	*/
	// If just a return ('\n') is entered, then use DEFAULT_OUTPUT_FILENAME.
	// Otherwise, read in the output filename from STDIN.
	cout << "Please enter the output filename (or simply press return to use " << DEFAULT_OUTPUT_FILENAME << ")\n";
	getline(cin, outputFilename);
	if (outputFilename == "") {
		outputFilename = DEFAULT_OUTPUT_FILENAME;
	}

	outfile.open(outputFilename);

	// verify that the file opened correctly
	if (!outfile) {
		cerr << "ERROR: Opening output file \"" << outputFilename << "\"\n";
		exit(1);
	}

	/*
	* Get a seed (if specified)
	*/
	// If just a return ('\n') is entered, then use time(NULL).
	// Otherwise, read the seed from STDIN (for debugging purposes).
	cout << "Please specify the random number generator seed (or simply press return to use the current time)\n";
	getline(cin, inputLine);
	if (inputLine == "") {
		// default to the current time
		seed = time(NULL);
	}
	else {
		seed = atoi(inputLine.c_str());
	}

	outfile << "n";

	for (unsigned int sortI = 0; sortI < sortingFunctionNames.size(); sortI++) {
		outfile << "\t" << sortingFunctionNames[sortI];
	}
	outfile << endl;

	// use different values of n, starting at 100, and growing by 10x until the user specified limit is reached 
	for (int n = 100; n <= maxN; n *= 10) {

		try {
			// allocate memory
			arrayOrig = new int[n];
			array = new int[n];
			answers = new int[n];
		}
		catch (std::bad_alloc& ba) {
			cerr << "Memory allocation error: " << ba.what() << '\n';
			exit(1);
		}

		// populate the array with random values
		setRandomValues(arrayOrig, n, seed);

		//
		// Sort answers
		//
		// copy contents of arrayOrig into array
		memcpy(answers, arrayOrig, n * sizeof(int));
		setAnswerKey(answers, n);

		outfile << n;

		for (unsigned int sortI = 0; sortI < sortingFunctionCallbacks.size(); sortI++) {
			// copy contents of arrayOrig into array
			memcpy(array, arrayOrig, n * sizeof(int));

			// call the sorting function (using a function pointer)
			outfile << "\t" << sortingFunctionCallbacks[sortI](array, n);  // for example, will call insertionSort(array, n)

																		   // verify that all of the values are sorted
			verifySort(array, answers, n);
		}
		outfile << endl;

		// clean up memory
		delete[] arrayOrig;
		delete[] array;
	}

	outfile.close();

	return 0;
}
