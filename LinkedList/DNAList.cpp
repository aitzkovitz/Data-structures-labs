//DNAList.cpp
//Aaron Itzkovitz
//CSCI 3110
//2/10/16

//Description:
// Implementation of the linked list class.
// 
//



#include "DNAList.h"
#include "sequenceDatabase.h"
using std::cout;

//constructor creates pointer for head
DNAList::DNAList()
{
	head = nullptr;
	length = 0;
}

//add method for adding a new DNA object to the end of the list.
void DNAList::push_back(DNAPtr newDNA) {
	// create Node with ptr to new DNA object
	NodePtr newNode = new Node;
	newNode->DNAObject = newDNA;
	newNode->next = nullptr;
	NodePtr curr = head;
	// If the list is empty, the head becomes the new node
	if (curr == nullptr) {
		head = newNode;
	}
	// if list has one item
	else if (curr -> next == nullptr) {
		head->next = newNode;
	}
	// if the list has more than one item, go to the end
	else {
		while (curr -> next != nullptr) {
			curr = curr->next;
		}
		curr -> next = newNode;
	}
	length++;
}

// method to find the Node with the given ID and return pointer to the corresponding DNA object
DNAPtr DNAList::find(string id) {
	NodePtr curr = head;
	
	// empty list case
	if (head == nullptr){
		return nullptr;
	}
	// corresponding DNA pointer is in head or middle Node
	else {
		while (curr != nullptr && (curr -> DNAObject -> getID()) != id) {
			curr = curr->next;
		}
		// loop stopped because ID found
		if (curr != nullptr) {
			return curr -> DNAObject;
		}

		// reached end of list w/o success
		else {
			return nullptr;
		}
	}
}

// method to delete Node from the list
bool DNAList::obliterate(string id) {
	NodePtr curr = head;
	NodePtr prev = head;
	// if list is empty
	if (head == nullptr)
	{
		return false;
	}
	else if (head -> next == nullptr) {
		if (head->DNAObject->getID() == id) {
			delete head;
			head = nullptr;
			curr = nullptr;
			prev = nullptr;
			length--;
			return true;
		}
		else {
			return false;
		}

	}
	
	// list has more than one node
	else {
		if (head->DNAObject->getID() == id) {
			head = curr->next;
			delete curr;
			curr = nullptr;
			length--;
			return true;
		}
		else {
			// iterate through until end or corresponding node is found
			while (curr != nullptr && curr->DNAObject->getID() != id) {
				prev = curr;
				curr = curr->next;
			}
			// SUPER IMPORTANT: SET HEAD TO NULL (3HOUR MISTAKE)
			if (curr != nullptr) {
				prev->next = curr->next;
				delete curr;
				curr = nullptr;
				// head = nullptr;
				length--;
				return true;
			}
			else {
				return false;
			}

		}
	}
}

// returns the lists length
int DNAList::size() const {
	return length;
}

// deletes and deallocates memory from linked list
DNAList::~DNAList() {
	NodePtr curr = head;
	NodePtr temp;
	while (curr != nullptr)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	
}
