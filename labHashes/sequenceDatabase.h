/*
File Name:
Author: Aaron Itzkovitz
Description:

Header file for SequenceDatabase class. Holds the hashtable object and ofstream object. Contains main method for parsing through file.

*/

#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H
#include "HashTable.h"
#include "Sequence.h"
#include <fstream>
#include <string>

typedef Sequence* SequencePtr;
class SequenceDatabase
{
public:
	void importEntries(std::string inputFile);		// method used for parsing through input file
	SequenceDatabase(string newFile);				// constructor builds object with input file name
	~SequenceDatabase();							// destructor implicitly closes the output file
private:
	std::ofstream outfile;							// file to be written to
	HashTable<Sequence*>* hashTablePtr;

};

#endif SEQUENCEDATABASE_H

