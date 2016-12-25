#ifndef TREENODE_H
#define TREENODE_H
#include <stddef.h>
#include "Sequence.h"

typedef Sequence* treeItemType;

/*
Class represents each treeNode
*/

class TreeNode 
{
private:
	// value constructor
	TreeNode(Sequence* dataItem, TreeNode* left = NULL, TreeNode* right = NULL) :
		sequenceObject(dataItem), leftChildPtr(left), rightChildPtr(right) {};
	TreeNode() : leftChildPtr(NULL), rightChildPtr(NULL) {};
	

	// left and right nodes
	TreeNode* leftChildPtr;
	TreeNode* rightChildPtr;
	treeItemType sequenceObject;
	friend class BST;

};
#endif TREENODE_H
