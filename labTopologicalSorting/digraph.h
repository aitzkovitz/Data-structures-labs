// File Name: Digraph.h
// Programmer: Aaron Itzkovitz 
// Desription: File contains header for Digraph class. 
// Contains constructor to build graph based on input file.
//
//
#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <vector>
#include <string>
#include <list>
using std::vector;
using std::string;

class Digraph
{
public:
	Digraph(string filename);						// constructor to build graph based on input file
	std::list<string> getTopoSort();				// topological sort method returns a list
	int getNumVertices() const;						// returns the number of vertices in the graph
	int getNumEdges() const;						// returns the number of edges in the graph
	~Digraph();										// default deconstructor
private: 
	vector<std::list<string>> aList;				// vector of string lists to represent adjacency lists, first element is the list's vertex
	vector<string> labels;							// vector of every label in graph
	std::list<string> islands;						// vector of islands, to be added to sorted list first
	int vertices;									// number of vertices
	int edges;										// number of edges
};

#endif