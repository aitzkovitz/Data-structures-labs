//sequenceDatabase.cpp
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Contains the implementation for the sequenceDatabase class. 
// Parses the input file using the import entries method. 
//
//
//
//


#include "sequenceDatabase.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DNA.h"
#include "DNAList.h"
#include <cassert>
using std::string;
using std::endl;
using std::ifstream;
using std::cout;


// constructor opens output file
SequenceDatabase::SequenceDatabase(string& newFile) {
	outfile.open(newFile);
}

// processes input and prints appropriate output to output file depending on letter
void SequenceDatabase::importEntries(string inputFile) {
	ifstream infile;
	//DNAList CLASS INSTANTIATION 
	DNAList DNAEntries;
	// read input file
	infile.open(inputFile);
	assert(infile);
	// declare vars
	char c;
	string label, ID, sequence, word;
	int length, index, listSize;
	DNAPtr foundDNA;
	// BEGIN PARSING
	outfile << "Importing " << inputFile << " ..." << endl;
	while (infile.get(c))
	{
		// ADD CASE
		if (c == 'D') {
			// create pointer to allocated DNA object
			
			DNAPtr newEntryPtr = new DNA();
			//check allocation
			assert(newEntryPtr);
			// read into info to DNA object
			infile >> label
				>> ID
				>> sequence
				>> length
				>> index;
			newEntryPtr->setDNA(label, ID, sequence, length, index);
			outfile << "Adding " << ID << " ..." << endl << endl;
			DNAEntries.push_back(newEntryPtr);
		}
		// PRINT CASE
		else if (c == 'P') {
			infile >> ID;
			outfile << "Printing " << ID << " ..." << endl;
			// find based on ID in list
			foundDNA = DNAEntries.find(ID);
			if (foundDNA != nullptr) {
				// create DNA object for found DNA in order to print
				DNA printable = *(foundDNA);
				printable.print(outfile);
				outfile << endl;
			}
			else {
				outfile << "Can not find item (" << ID << ")!" << endl << endl;
			}
		}
		// OBLITERATE CASE
		else if (c == 'O') {
			infile >> ID;
			outfile << "Obliterating " << ID << " ..." << endl;
			// obliterate based on ID
			if (!DNAEntries.obliterate(ID)) {
				outfile << "Can not delete DNA (" << ID << "), NOT found!" << endl;
			}
			outfile << endl;
		}
		// GET SIZE CASE
		else if (c == 'S') {
			listSize = DNAEntries.size();
			outfile << "Entries: " << listSize << endl << endl;
		}
		else {
			cout << "Did not read from file correctly" << endl;
		}
		getline(infile, word);
	}
	infile.close();
}

// deconstructor to close file
SequenceDatabase::~SequenceDatabase() {
	outfile.close();
}