/*
File Name: RNA.cpp
Author: Aaron Itzkovitz
Description:
Implementation file for RNA class. Contains methods to set enum and to print object.

*/

#include "RNA.h"
using std::endl;


void RNA::printInfo(ostream& os)
{
	if (TypeRNA == 0)
		os << "RNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tType: " << "mRNA" << endl << endl;
	else if (TypeRNA == 1)
		os << "RNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tType: " << "rRNA" << endl << endl;
	else
		os << "RNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tType: " << "tRNA" << endl << endl;
}

void RNA::setRNAtype(string type)
{
	if (type == "mRNA")
		TypeRNA = mRNA;
	else if (type == "rRNA")
		TypeRNA = rRNA;
	else
		TypeRNA = tRNA;
}
RNA::~RNA()
{
}
