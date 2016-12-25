#include "AA.h"
using std::endl;

// printInfo method unique to AA class, takes in ostream object 
void AA::printInfo(ostream& os)
{
	os << "AA:\t" << "Label: " << label <<'\t'<< "ID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tORF: " << ORF << endl << endl;
}

AA::~AA()
{
}
