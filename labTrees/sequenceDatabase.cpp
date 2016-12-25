#include "sequenceDatabase.h"
#include "RNA.h"
#include "DNA.h"
#include "AA.h"
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include "BST.h"
using std::string;
using std::ifstream;
using std::cin;
using std::cerr;
using std::endl;

// construct new output file based on given string
sequenceDatabase::sequenceDatabase(string newFile)
{
	outfile.open(newFile);
}

// method to parse through file calling appropriate BST operations
void sequenceDatabase::importEntries(string inputFile) 
{
	outfile << "Importing " << inputFile << " ...\n";
	// instantiate ifstream object to read from
	ifstream infile;
	infile.open(inputFile);
	// check assertation
	assert(infile);							
	// vars
	char c;
	bool success;
	int id, length, ORF, index;
	string label, sequence, dummy, rnaType;
	// instantiate BST
	BST* sequenceTree = new BST();
	// loop for parsing file
	while (infile.get(c))
	{
		success = true;
		// if P is read, print given ID
		if (c == 'P') {
			infile >> id;
			outfile << "Printing " << id << " ...\n";
			treeItemType foundPtr = new DNA;
			// retrieve object from tree and print it
			sequenceTree -> treeRetrieve(id, foundPtr, success);
			if (success) {
				foundPtr->printInfo(outfile);
			}
			else
				outfile << "Can not find item (" << id << ")!\n\n";
		}
		// of O is read from file
		else if (c == 'O') {
			infile >> id; 
			outfile << "Obliterating " << id << " ...\n";
			// delete object from tree
			sequenceTree -> treeDelete(id, success);
			if (success)
				outfile << endl;
			if (!success)
				outfile << "Can not delete item (" << id << "), NOT found!\n\n";
		}
		// if S is read from file, print the size of the list
		else if (c == 'S') {
			outfile << "Entries: " << sequenceTree -> getSize() << " total" << endl << endl;
		}
		// if D is read from file, add DNA object 
		else if (c == 'D') {
			infile >> label >> id >> sequence >> length >> index;
			outfile << "Adding " << id << " ...\n\n";
			treeItemType newDNAPtr = new DNA(label, id, sequence, length, index);
			sequenceTree -> treeInsert(newDNAPtr);
		}
		// if R is read, add an RNA object
		else if (c == 'R') {
			// add RNA object
			infile >> label >> id >> sequence >> length >> rnaType;
			RNA* newRNAPtr = new RNA(label, id, sequence, length);
			outfile << "Adding " << id << " ...\n\n";
			newRNAPtr->setRNAtype(rnaType);
			treeItemType ptr = new RNA();
			ptr = newRNAPtr;
			sequenceTree -> treeInsert(ptr);
		}
		// if A read from file, add amino acid object from file
		else if (c == 'A') {
			infile >> label >> id >> sequence >> length >> ORF;
			outfile << "Adding " << id << " ...\n\n";
			treeItemType newAAPtr = new AA(ORF, label, id, sequence, length);
			sequenceTree -> treeInsert(newAAPtr);
		}
		else {
			cerr << "Did not read file correctly.\n";
		}
		getline(infile, dummy); 
	}
	// deconstructor
	sequenceTree -> ~BST();
	// close input file
	infile.close();
}
// close output file
sequenceDatabase::~sequenceDatabase()
{
	outfile.close();
}
