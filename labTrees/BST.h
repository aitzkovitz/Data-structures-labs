#ifndef BST_H
#define BST_H
#include "TreeNode.h"

/*
BST Class houses all implementation for Binary Search tree operations used in this project.
*/

class BST
{
public:
	// default destructor and constructor
	BST();
	~BST();
	// method returns whether the BST is empty or not
	bool isEmpty() const;
	// method returns the current size if the BST Object
	int getSize() const;
	// treeInsert serves as public interface for insert function which uses implementation specific details
	// and finds correct location using the sequence ID as a search key and creates a new treeNode with null pointers.
	void treeInsert(const treeItemType& newData);
	// serves as public interface for retrieve function to hide implementation specific details and
	// finds treeNode based on given ID and populates treeNode that was passed in
	void treeRetrieve(const int& searchId, treeItemType& treeItem, bool& success) const;
	// serves as public interface to hide implementation specific details and deletes a node with the given ID or outputs an error
	void treeDelete(const int& searchId, bool& success);

private:
	// finds correct location based on id and creates new node with null pointers for children
	void insertItem(TreeNode *& root, const treeItemType& toAdd);
	// finds node based on given ID and root and populates reference with its data
	void retrieveItem(TreeNode* root, treeItemType& toPopulate, const int& id, bool& success) const;
	// deletes node with given ID by handling cases: the ID doesn't exist in the treem the Node has a left child, 
	// node has a right child, and it has two children. If two children calls a functions to find inorder successor 
	// which it then puts in the delete Node
	void deleteItem(TreeNode*& root, const int& id, bool& success);
	// handles different delete cases, calls findSuccessor if deleteNode has two children
	void deleteNodeItem(TreeNode *& treeItem);
	// finds inorder successor of given node by finding the leftmost node of the right subtree of the given node
	void findSuccessor(TreeNode *& nodePtr, treeItemType& treeItem);
	// if the tree isn't emtpy, delete each node, called in destrocutor
	void deleteBST(TreeNode *& deleteNode);
	TreeNode* root;						// root of tree
	int size;							// size of tree


};
#endif BST_H
