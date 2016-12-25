/*
File Name:
Author: Aaron Itzkovitz
Description:

*/

#include "sequenceDatabase.h"
#include "RNA.h"
#include "DNA.h"
#include "AA.h"
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

using std::string;
using std::ifstream;
using std::cin;
using std::cerr;
using std::endl;

// prototypes 
bool isPrime(unsigned int num);
int findPrime(const int& origSize);

// construct new output file based on given string
SequenceDatabase::SequenceDatabase(string newFile)
{

	outfile.open(newFile);
}

// method to parse through file calling appropriate BST operations
void SequenceDatabase::importEntries(string inputFile)
{
	// instantiate ifstream object to read from
	ifstream infile;
	infile.open(inputFile);
	// check assertation
	assert(infile);
	// vars
	char c;
	int id, length, ORF, index, tableSize;
	string label, sequence, dummy, rnaType;
	infile >> c;
	tableSize = c - '0';
	hashTablePtr = new HashTable<SequencePtr>(tableSize);
	getline(infile, dummy);

	// loop for parsing file
	while (infile.get(c))
	{
		if (hashTablePtr->getLoad() == 1.0) {
			int newSize = findPrime(hashTablePtr->getSize());
			HashTable<SequencePtr>* swapPtr = hashTablePtr;
			hashTablePtr = new HashTable<SequencePtr>(newSize);
			hashTablePtr -> rehash(swapPtr);
			swapPtr -> ~HashTable();
			
		}
		// if P is read, print given ID
		if (c == 'P') {
			infile >> label;
			outfile << "Printing " << label << " ...\n";
			SequencePtr findPtr = hashTablePtr -> retrieve(label);
			if (findPtr != NULL)
				findPtr->printInfo(outfile);
			else
				outfile << "Can not find item (" << label << "), NOT found!\n\n";
		}

		// of O is read from file
		else if (c == 'O') {
			infile >> label;
			outfile << "Obliterating " << label << " ...\n";
			// delete object from tree
			if (hashTablePtr->obliterate(label))
				outfile << "Load factor: " << hashTablePtr->getLoad() << endl << "Hash table size: " << hashTablePtr->getSize() << endl << endl;
			else 
				outfile << "Can not delete item (" << label << "), NOT found!\n\n";
		}

		// if S is read from file, print the size of the list
		else if (c == 'S') {
			outfile << "Entries: " << hashTablePtr->getUsed() << endl << endl;
		}

		// if D is read from file, add DNA object 
		else if (c == 'D') {
			infile >> label >> id >> sequence >> length >> index;
			outfile << "Adding " << label << " ...\n";
			SequencePtr newDNAPtr = new DNA(label, id, sequence, length, index);
			hashTablePtr -> addSequence(label, newDNAPtr);
			outfile << "Load factor: " << hashTablePtr->getLoad() << endl << "Hash table size: " << hashTablePtr->getSize() << endl << endl;
			
		}

		// if R is read, add an RNA object
		else if (c == 'R') {
			// add RNA object
			infile >> label >> id >> sequence >> length >> rnaType;
			RNA* newRNAPtr = new RNA(label, id, sequence, length);
			outfile << "Adding " << label << " ...\n";
			newRNAPtr->setRNAtype(rnaType);
			SequencePtr newRNA = newRNAPtr;
			hashTablePtr -> addSequence(label, newRNA);
			outfile << "Load factor: " << hashTablePtr->getLoad() << endl << "Hash table size: " << hashTablePtr->getSize() << endl << endl;

		}
		// if A read from file, add amino acid object from file
		else if (c == 'A') {
			infile >> label >> id >> sequence >> length >> ORF;
			outfile << "Adding " << label << " ...\n";
			SequencePtr newAAPtr = new AA(ORF, label, id, sequence, length);
			hashTablePtr -> addSequence(label, newAAPtr);
			outfile << "Load factor: " << hashTablePtr->getLoad() << endl << "Hash table size: " << hashTablePtr->getSize() << endl << endl;
		}
		else {
			cerr << "File did not read correctly\n";
		}
		getline(infile, dummy);
	}
	// deconstructor
	hashTablePtr -> ~HashTable();
	// close input file
	infile.close();
}
// close output file
SequenceDatabase::~SequenceDatabase()
{
	delete hashTablePtr;
	hashTablePtr = NULL;
	outfile.close();
}
// function determines whether a number is prime
bool isPrime(unsigned int num) {
	int i = 2;
	while (i < num) {
		if (num % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

// function finds the prime number after twice the original size
int findPrime(const int& origSize)
{
	int newSize = (2 * origSize) + 1;
	while (!isPrime(newSize)) {
		newSize++;
	}
	return newSize;
}
