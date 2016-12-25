//main.cpp
//Aaron Itzkovitz
//CSCI 3110
// main.cpp 
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Program acts as interface for use of DNAList, sequenceDatabase, and DNA classes.
// Program asks user for the name of the input file to parse through and interact with.
// 
//
//
//
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;

// NOTE: The first letter is a lower case "s" (and not an uppercase "S")
//       ranger is case sensitive! 
#include "sequenceDatabase.h"

const string DEFAULT_INPUT_FILENAME = "labParser-testA.tab";
const string DEFAULT_OUTPUT_FILENAME = "labParser-stdout_stderrA.txt";

int main( /*int argc, char* argv[] */) {

	// If just a return ('\n') is entered, then use DEFAULT_INPUT_FILENAME.
	// Otherwise, read in the input filename from STDIN.
	string inputFilename;
	cout << "Please enter the input filename (or simply press return to use " << DEFAULT_INPUT_FILENAME << ")\n";
	getline(cin, inputFilename);
	if (inputFilename == "") {
		inputFilename = DEFAULT_INPUT_FILENAME;
	}

	// If just a return ('\n') is entered, then use DEFAULT_OUTPUT_FILENAME.
	// Otherwise, read in the output filename from STDIN.
	string outputFilename;
	cout << "Please enter the output filename (or simply press return to use " << DEFAULT_OUTPUT_FILENAME << ")\n";
	getline(cin, outputFilename);
	if (outputFilename == "") {
		outputFilename = DEFAULT_OUTPUT_FILENAME;
	}

	SequenceDatabase entries(outputFilename);
	entries.importEntries(inputFilename);
	int number;
	cin >> number;
	return 0;
}