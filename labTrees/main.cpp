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

const string DEFAULT_INPUT_FILENAME = "labTrees-inputA.tab";
const string DEFAULT_OUTPUT_FILENAME = "labTrees-outputA.txt";

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

	sequenceDatabase entries(outputFilename);
	entries.importEntries(inputFilename);

	return 0;
}
