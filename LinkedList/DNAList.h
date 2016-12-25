//DNAList.h
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Header file for DNAList class (Linked List).
// Creates a node struct to represent each part of the list. 
// Offers methods to add to list, find in list, delete from list, and return length.
// Constructor and destructor to deallocate and free memory.
//
//
//
#ifndef DNALIST_H
#define DNALIST_H
#include "DNA.h" 

typedef DNA* DNAPtr;

struct Node {
	DNAPtr DNAObject;
	Node* next;
};
typedef Node* NodePtr;

class DNAList {
private:
	NodePtr head;
	int length;
public:
	//constructor
	DNAList();

	//add method
	void push_back(DNAPtr newDNA);

	//find DNA and return pointer
	DNAPtr find(string id);

	//obliterate method
	bool obliterate(string id);

	//get list length
	int size() const;

	// destructor 
	~DNAList();
};
#endif
