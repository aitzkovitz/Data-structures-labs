#include "DNA.h"
using std::endl;


DNA::~DNA()
{
}

void DNA::printInfo(ostream& os)
{
	os << "DNA:\t" << "Label: " << label <<'\t' << "ID: " << id << "\tSequence: " << sequence << "\tLength: " << length << "\tcDNAStartIndex: " << startIndex << endl << endl;
}
