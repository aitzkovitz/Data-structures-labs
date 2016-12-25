#include <iostream>
#include <string>
#include "nQueens.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;

const int DEFAULT_N = 4;
const string DEFAULT_OUTPUT_FILENAME = "labBacktracking.txt";

int main( /*int argc, char* argv[] */) {

	cout << "Please enter the number of queens (or simply press return to use " << DEFAULT_N << ")\n";

	int n = DEFAULT_N;
	// Attempt to read in the number of queens.
	// If just a return ('\n') was entered, use DEFAULT_N.  
	if (cin.peek() != '\n') {  // verify the next character is not a newline
		if (!(cin >> n)) {     // check for invalid input
			cerr << "Invalid input for number of queens!\n";
			return 0;
		}
	}

	cin.ignore(); // clear out the '\n'

				  // If just a return ('\n') is entered, then use DEFAULT_OUTPUT_FILENAME.
				  // Otherwise, read in the output filename from STDIN.
	string outputFilename;
	cout << "Please enter the output filename (or simply press return to use " << DEFAULT_OUTPUT_FILENAME << ")\n";
	getline(cin, outputFilename);
	if (outputFilename == "") {
		outputFilename = DEFAULT_OUTPUT_FILENAME;
	}

	printNQueensSolution(n, outputFilename);

	return 0;
}