/*
File Name: RNA.h
Author: Aaron Itzkovitz
Description:
Header file for RNA class. Contains enum for RNA tpye and constructors and destructor as well as print method.


*/

#ifndef RNA_H
#define RNA_H
#include "Sequence.h"

// enum to represent field unique to RNA class 
enum type { mRNA, rRNA, tRNA };

/*
Class represent an RNA entry

*/
class RNA : public Sequence
{
public:
	// default constructor calls base class constructor 
	RNA()
		: Sequence() {};
	// default destructor
	~RNA();
	// value constructor calls base class value construct and initializes data unique to this class
	RNA(string newLabel, int newId, string newSequence, int newLength)
		: Sequence(newLabel, newId, newSequence, newLength) {};
	// function overrudes base class print function
	void printInfo(ostream& os);
	// sets TypeRNA data member based on string read in from file
	void setRNAtype(string type);
private:
	type TypeRNA;
};
#endif
