//sequenceDatabase.h
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// The header file for the sequenceDatabase class. Includes the importEntries method which facilitates the parsing of the input file.
//
//

#ifndef SEQUENCE_DATABASE
#define SEQUENCE_DATABASE



#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;


class SequenceDatabase {
		
public:
	SequenceDatabase(string& newFile);
	void importEntries(string inputFile);
	~SequenceDatabase();

private:
	ofstream outfile;

};

#endif