#include "BST.h"
#include <iostream>

#include <string>
using std::string;
using std::cerr;


BST::BST() : root(NULL), size(0)
{
}

// determine if tree is empty
bool BST::isEmpty() const {
	return (root == NULL);
}

int BST::getSize() const
{
	return size;
}

void BST::treeInsert(const treeItemType& toInsert)
{
	insertItem(root, toInsert);
	size++;
}

void BST::insertItem(TreeNode *& nodePtr, const treeItemType& toAdd)
{
	// tree is empty, make new Node
	if (nodePtr == NULL)
	{
		nodePtr = new TreeNode(toAdd, NULL, NULL);
	}
	// toAdd is less than curent Node
	else if (toAdd->getID() < nodePtr -> sequenceObject -> getID()) {
		insertItem(nodePtr->leftChildPtr, toAdd);
	}
	// toadd is greater than current Node
	else {
		insertItem(nodePtr->rightChildPtr, toAdd);
	}
}

void BST::treeRetrieve(const int& searchId, treeItemType& toPopulate, bool& success) const
{
	retrieveItem(root, toPopulate, searchId, success);
}



void BST::retrieveItem(TreeNode* node, treeItemType& toPopulate, const int& id, bool& success) const
{
	if (node == NULL)
		success = false;
	else if (id == node->sequenceObject->getID()){
		toPopulate = node -> sequenceObject; // pointer to sequence object is put in toPopulate

	}
	else if (id < node->sequenceObject->getID()) {
		retrieveItem(node->leftChildPtr, toPopulate, id, success);
	}
	else 
	{
		retrieveItem(node->rightChildPtr, toPopulate, id, success);
	}
}

void BST::treeDelete(const int& id, bool& success)
{
	deleteItem(root, id, success);
}

void BST::deleteItem(TreeNode*& node, const int& id, bool& success)
{
	if (node == NULL)
		success = false;
	else if (node->sequenceObject->getID() == id)
	{
		deleteNodeItem(node);
	}
	else if (node->sequenceObject->getID() < id)
	{
		deleteItem(node->rightChildPtr, id, success);
	}
	else {
		deleteItem(node->leftChildPtr, id, success);
	}
}

void BST::deleteNodeItem(TreeNode *& treeItem)
{
	size--;
	TreeNode* deletePtr;
	treeItemType replacement;
	// if item is a leaf
	if (treeItem->leftChildPtr == NULL && treeItem->rightChildPtr == NULL)
	{
		delete treeItem;
		treeItem = NULL;
	}
	// if item has no left child
	else if (treeItem -> leftChildPtr == NULL) {
		deletePtr = treeItem;
		treeItem = treeItem->rightChildPtr;
		deletePtr->rightChildPtr = NULL;
		delete deletePtr;
	}
	// no right child
	else if (treeItem->rightChildPtr == NULL) {
		deletePtr = treeItem;
		treeItem = treeItem->leftChildPtr;
		deletePtr->rightChildPtr = NULL;
		delete deletePtr;
	}
	// if item has two children
	else {
		findSuccessor(treeItem -> rightChildPtr, replacement);
		treeItem->sequenceObject = replacement;
	}
}

void BST::findSuccessor(TreeNode *& treeNode, treeItemType& treeItem)
{
	if (treeNode->leftChildPtr == NULL)
	{
		treeItem = treeNode->sequenceObject;
		TreeNode* deletePtr = treeNode;
		treeNode = treeNode->rightChildPtr;
		deletePtr->rightChildPtr = NULL; 
		delete deletePtr;
	}
	else
		findSuccessor(treeNode->leftChildPtr, treeItem);
}

void BST::deleteBST(TreeNode *& deleteNode)
{
	if (deleteNode != NULL)
	{
		deleteBST(deleteNode->leftChildPtr);
		deleteBST(deleteNode->rightChildPtr);
		delete deleteNode;
		deleteNode = NULL;
	}
}
BST::~BST()
{
	deleteBST(root);
	// cerr << "BST destroyed";
}
