//DNA.h
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Header file for the DNA class. DNA class represents a DNA Entry. Each object has 5
// attributes. Objects are used in sequenceDatabase class with linked list.
//
//
//
//

#ifndef DNA_H
#define DNA_H
#include "sequenceDatabase.h"
#include <string>
using std::string;

class DNA {

public:

	DNA();
	void print(ofstream& output);
	void setDNA(string newLabel, string newID, string newSeq, int newLength, int newIndex);
	string getID();

private:

	string label;
	string accID;
	string seq;
	int seqLength;
	int index;
};






#endif
