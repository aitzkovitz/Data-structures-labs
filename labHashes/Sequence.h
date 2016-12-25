/*
File Name:
Author: Aaron Itzkovitz
Description:

Abstract base class which encompasses similarites and overlap between different sequence objects.

*/

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include <fstream>
using std::string;
using std::ostream;

class Sequence
{
public:
	// default constructor
	Sequence();
	// default destructor
	~Sequence();
	// value constructor
	Sequence(string newLabel, int newId, string newSequence, int newLength)
		: label(newLabel), id(newId), sequence(newSequence), length(newLength) {};
	// returns the sequence id for use in BST operations
	string getKey() { return label; }
	// abtract function to be implemented by each derived class
	virtual void printInfo(ostream& os) = 0;
protected:
	// properties shared by all sequence objects
	string label;
	int id;
	string sequence;
	int length;
};

#endif