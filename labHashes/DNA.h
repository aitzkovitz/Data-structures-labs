/*
File Name: DNA.h
Author: Aaron Itzkovitz
Description:
Header file for DNA class; represents a DNA sequence. File contains constructors, destructor, print method, and start index data member.

*/

#ifndef DNA_H
#define DNA_H
#include <string>
#include "Sequence.h"
using std::string;

/*
Class represent a DNA object, derived from base class Sequence.
*/

class DNA : public Sequence
{
public:
	// default constructor calls base class constructor 
	DNA()
		: Sequence() {};
	// default destructor
	~DNA();
	// value constructor calls base class value construct and initializes data unique to this class
	DNA(string newLabel, int newId, string newSequence, int newLength, int newStartIndex)
		: Sequence(newLabel, newId, newSequence, newLength), startIndex(newStartIndex) {};
	// function overrudes base class print function
	void printInfo(ostream& os);
private:
	int startIndex;				// data unique to DNA
};
#endif 