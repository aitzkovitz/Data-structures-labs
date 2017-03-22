/*
File Name: HashTable.h
Author: Aaron Itzkovitz
Description:
Contains header and implementation for templated HashTable class.
Contains appropriate methods for using a hashtable. Implements the 
table as a vector of lists.

*/


#ifndef HASH_TABLE
#define HASH_TABLE
#include "Sequence.h"
#include <list>
#include <vector>
using std::list;
using std::vector;

template <class T>
class HashTable
{
public:
	
	HashTable(const int& tableSize);					// value constructor; takes size of hashtable
	~HashTable();								// destructor
	void addSequence(const string& label, T dataPointer);			// method to add sequence to table
	T retrieve(string label);						// interface method to retrieve a sequence object
	int getSize() const;							// method returns size
	double getLoad();							// method returns load factor
	bool obliterate(const string& label);					// method deletes object from table based on label
	void rehash(HashTable<T> *& oldHashTable);				// method rehashes table when load is over 1
	int getUsed();								// returns the amount of objects in the table in total
private:
	vector<list<T>> bucketChain;						// bucketChain is a vector of lists
	unsigned int hash( string label) const;					// hash function
	int size;								// number of lists in total
	int numOfFullBuckets;							// number of entries in table
	double loadFactor;							// average length of lists
	T find(const string& label);						// returns the objects stored in the table
	bool deleteSequence(const string& label);				// deletes a sequence given the label
};

// value constructor
template<class T>
HashTable<T>::HashTable(const int& lists)
{
	size = lists;
	bucketChain.resize(lists);
	numOfFullBuckets = 0;
	loadFactor = double(numOfFullBuckets) / size;;
}


// destructor
template <class T>
HashTable<T>::~HashTable()
{

}

// adds element to hash table
template <class T>
void HashTable<T>::addSequence(const string& label, T dataPointer)
{
	// find location and push ptr onto corresponding list
	int location = hash(label);
	bucketChain[location].push_front(dataPointer);
	// update total number of objects in table
	numOfFullBuckets++;
	// reset load factor
	loadFactor = double(numOfFullBuckets) / size;
}


// retrieve from hashTable
template <class T>
T HashTable<T>::retrieve(string label) 
{
	T foundItem = find(label);
	// if find function doesn't return a null ptr, return what it returned
	if (foundItem != NULL)
		return foundItem;
	else
		return NULL;
}

// find and return to retrieve
template <class T>
T HashTable<T>::find(const string& label)
{

	// if the list number given by the hash function is an empty list, return Null ptr
	if (bucketChain[hash(label)].empty()) {
		return NULL;
	}
	// go through the list until correct label is found
	T seqPtr;
	for (typename list<T>::iterator it = (bucketChain[hash(label)]).begin(); it != (bucketChain[hash(label)]).end(); it++) {
		seqPtr = *it;
		if (seqPtr->getKey() == label) {
			T sequencePtr = *it;
			return sequencePtr;
		}
	}
	return NULL;

	int location = hash(label);
}

// function calls deletSequence
template <class T>
bool HashTable<T>::obliterate(const string& label)
{
	// if deleteSequence finds and deletes the sequence, return true
	if (deleteSequence(label))
		return true;
	else
		return false;
}
// function deletes Sequence
template <class T>
bool HashTable<T>::deleteSequence(const string& label)
{
	// hash the delete label to find list location
	int deleteLocation = hash(label);
	// look through list until label is found
	for (typename list<T>::iterator it = bucketChain[deleteLocation].begin(); it != bucketChain[deleteLocation].end(); it++)
	{
		T seqPtr = *it;
		if (seqPtr->getKey() == label) {
			bucketChain[deleteLocation].erase(it);
			numOfFullBuckets--;
			loadFactor = double(numOfFullBuckets) / bucketChain.size();
			return true;
		}
	}
	return false;
}

// get used size
template <class T>
int HashTable<T>::getUsed()
{
	return numOfFullBuckets;
}
// get load factor
template <class T>
double HashTable<T>::getLoad()
{
	return loadFactor;
}

// get size
template <class T>
int HashTable<T>::getSize() const
{ 
	return bucketChain.size();
}
// hash function
// if the length of the string is even, sum of each half then multiply the halves togther. Multiply that number and mod by table size.
template <class T>
unsigned int HashTable<T>::hash(string label) const
{
	unsigned int value1 = 1;
	unsigned int value2 = 1;
	if (label.length() % 2 == 0) {
		for (int i = 0; i < label.length()/2; i++) {
			value1 += label[i];
			value2 += label[i + label.length() / 2];
		}
	}
	else {
		unsigned int endChar = label.back();
		label.pop_back();
		for (int i = 0; i < label.length()/2; i++) {
			value1 += label[i];
			value2 += label[i + label.length() / 2];
		}
		value2 += endChar;
	}

	return (value1*value2 * 901) % size;
}

// rehash function
template <class T>
void HashTable<T>::rehash(HashTable<T> *& oldHashTable)
{
	int oldsize = oldHashTable->getSize();
	int i = 0;
	// iterate the length of the old list(vector)
	while (i != oldsize) {
		list<T> currList = oldHashTable->bucketChain[i];
		// for each list, if it's not empty, cycle through to find correct object
		if ((!currList.empty()) && currList.size() > 1) {
			for (typename list<T>::iterator it = currList.begin(); it != currList.end(); it++)
			{
				T sequencePtr = *it;
				string label = sequencePtr->getKey();
				T dataPtr = oldHashTable->find(label);
				addSequence(label, dataPtr);
			}
		}
		// if the list size is one, front() the object
		else if (currList.size() == 1)
		{
			T ptr = currList.front();
			string label = ptr->getKey();
			addSequence(label, ptr);
		}
		i++;
	}
}

#endif HASH_TABLE
