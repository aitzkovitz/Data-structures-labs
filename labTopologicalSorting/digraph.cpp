// File Name: Digraph.cpp
// Programmer: Aaron Itzkovitz
// Desription: Contains implementation for Digraph class
// Methods to construct graph, sort graph, and return the number of vertices or edges
//

#include "digraph.h"
#include <fstream>
#include <iostream>
#include <assert.h>

//
Digraph::Digraph(string filename) : aList(0), labels(), vertices(0), edges(0), islands(0)
{
	std::ifstream inFile (filename);				
	// check file assertion
	assert(inFile);
	string prereq, course;
	bool prereqInList, courseInList, island;
	int prereqIndex, courseIndex;
	// read in prereq - course pairs from file
	while (inFile >> prereq >> course) {
		prereqInList = false;
		courseInList = false;
		island = false;
		// if course hase no prereqs, construct and add to island vector
		if (prereq == "NONE") {
			aList.emplace_back(1, course);
			islands.push_back(course);
			vertices++;
			island = true;
		}

		// determine whether the course and prereq already have their own adjacency lists
		for (int i = 0; i < aList.size(); i++) {
			// if prereq is the first element of any adjacency list
			if (aList[i].front() == prereq) {
				prereqInList = true;
				prereqIndex = i;
			}
			// if course is the first element of any adjacency list
			if (aList[i].front() == course) {
				courseInList = true;
				courseIndex = i;
			}
		}
		// four cases:
		// prereq doesnt have its own list and course doesnt have its own list
		// make list for both of them, add course to prereqs list
		if (!prereqInList && !courseInList) {
			aList.emplace_back(1, prereq);
			aList.back().push_back(course);
			aList.emplace_back(1, course);
			vertices += 2;
			edges++;
			labels.push_back(prereq);
			labels.push_back(course);
		}
		// prereq has its own list but course doesn have its own list
		// add course to prereqs list
		else if (prereqInList && !courseInList) {
			aList[prereqIndex].push_back(course);
			aList.emplace_back(1, course);
			vertices++;
			edges++;
			labels.push_back(course);
		}
		// prereq doesnt have its own list course has its own list
		// make adjacency list for prereq, add course to that list
		else if (!prereqInList && courseInList && !island) {
			aList.emplace_back(1, prereq);
			aList.back().push_back(course);
			vertices++;
			edges++;
			labels.push_back(prereq);
		}
		// prereq has its own list and course has its own list
		// add course to prereqs list
		else if (prereqInList && courseInList ){
			aList[prereqIndex].push_back(course);
			edges++;
		}
	}
	inFile.close();
}

// method to topologically sort
std::list<string> Digraph::getTopoSort()
{
	std::list<string> sorted;
	string vertexToAdd;
	// while there are still unsorted elements, keep finding and adding vertex with outdegree 0
	while (!labels.empty()){
		bool found = false;
		bool foundIsland = false;
		// outer loop goes through vector of labels, 
		for (vector<string>::iterator it1 = labels.begin(); it1 != labels.end(); it1++) {
			// inner loop finds that corresponding adjacency list and checks whether its outdegree is zero
			for (vector<std::list<string>>::iterator it = aList.begin(); it != aList.end(); it++){
				// if there are any islands, make vertexToAdd that vertex and stop looking, reset interators
				if (!islands.empty()) {	
					vertexToAdd = islands.front();													
					islands.pop_front();
					foundIsland = true;									
					it1 = labels.begin();
					it = aList.begin();
					break;

				}
				// if this adjacency list corresponds to the label in labels vector, 
				// and if size = 1 (meaining outdegree is 0), make it the vertextoadd and stop looking, reset iterators
				if ((*it).front() == (*it1) && (*it).size() == 1) {
					vertexToAdd = *it1;
					aList.erase(it);
					labels.erase(it1);
					it1 = labels.begin();
					it = aList.begin();
					found = true;
					break;
				}
				
			}
			// if found, break outer loop
			if (found || foundIsland)
				break;
		}
		// if it was an island, look through aLists and delete it's adjacency list
		for (vector<std::list<string>>::iterator it5 = aList.begin(); it5 != aList.end(); it5++) {
			if ((*it5).front() == vertexToAdd && (*it5).size() == 1 && foundIsland) {
				aList.erase(it5);
				break;
			}
		}
		
		// if it wasnt an island, go through every adjacency list and delete it from that lists
		for (vector<std::list<string>>::iterator it2 = aList.begin(); it2 != aList.end(); it2++) {
			for (std::list<string>::iterator it3 = (*it2).begin(); it3 != (*it2).end(); it3++) {
				if (*it3 == vertexToAdd) {
					it3 = (*it2).erase(it3);
					break;						// break because it wouldnt be in the same list twice
				}
			}
		}
		// add vertex to sorted list
		sorted.push_back(vertexToAdd);
		vertices--;
		// if its wasnt an island, also decrement edges
		if (!foundIsland)
			edges--;
	}
	// reverse the list
	sorted.reverse();
	return sorted;
}

// return num of vertices
int Digraph::getNumVertices() const
{
	return vertices;
}

// return num if edges
int Digraph::getNumEdges() const 
{
	return edges;
}

Digraph::~Digraph()
{
}


