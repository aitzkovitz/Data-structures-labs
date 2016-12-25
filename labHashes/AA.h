/*
File Name: AA.h
Author: Aaron Itzkovitz
Description:
Header file for AA class, which represent an AA sequence. Contains constructors, destructor, print method, and ORF data member.

*/

#ifndef AA_H
#define AA_H
#include "Sequence.h"

/*
Class represent an amino object, derived from Sequence base class.
*/

class AA : public Sequence
{
public:
	// amino acid default constructor calls base class sequence default contructor
	AA()
		: Sequence() {};
	// amino acid value constructo calls sequence value constructor and initializes unique data
	AA(int newORF, string newLabel, int newId, string newSequence, int newLength)
		: Sequence(newLabel, newId, newSequence, newLength), ORF(newORF) {};
	// printInfo overrides base's virtual method 
	void printInfo(ostream& os);
	~AA();
private:
	int ORF;			// data unique to Amino Acid entries
};
#endif
