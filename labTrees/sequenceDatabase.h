#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H
#include "Sequence.h"
#include <fstream>
#include <string>

class sequenceDatabase
{
public:
	void importEntries(std::string inputFile);		// method used for parsing through input file
	sequenceDatabase(string newFile);				// constructor builds object with input file name
	~sequenceDatabase();							// destructor implicitly closes the output file
private:
	std::ofstream outfile;							// file to be written to
	
};













#endif SEQUENCEDATABASE_H
