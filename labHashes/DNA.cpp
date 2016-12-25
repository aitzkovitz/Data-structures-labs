/*
File Name: DNA.cpp
Author: Aaron Itzkovitz


*/

#include "DNA.h"
using std::endl;


DNA::~DNA()
{
}

void DNA::printInfo(ostream& os)
{
	os << "DNA:\t" << "Label: " << label << "\tID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tcDNAStartIndex: " << startIndex << endl << endl;
}
