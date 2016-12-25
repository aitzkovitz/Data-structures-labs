//DNA.cpp
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Implementation for DNA class. 
// Contains method to set attributes, method to print object info, and a constructor.
//
//

#include "DNA.h"
#include "sequenceDatabase.h"
#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

// constructor for each DNA object
DNA::DNA() {
	string label;
	string accID;
	string seq;
	int seqLength;
	int index;
}


// print each DNA objects info; takes in an ofstream object
void DNA::print(ofstream& output) {
	output << "DNA:\t" << "Label: " << label << "  ID: " << accID << "\tSequence: " << seq << "\tLength: " << seqLength << "\tcDNAStartIndex: " << index << endl;

}

// set attributes of DNA object
void DNA::setDNA(string newLabel, string newID, string newSeq, int newLength, int newIndex){
	label = newLabel;
	accID = newID;
	seq = newSeq;
	seqLength = newLength;
	index = newIndex;
}

// returns the ID of a DNA object
string DNA::getID() {
	return accID;
}