// Author: Aaron Itzkovitz
// File: nQueens.h
// Description: This file contains the main recursive solving algorithm and other
// utility functions. The main solving algorithm goes through each column and tries to place a Queen.
// If it successfully places the queen, it recurses with the next column. If not, it backtracks and
// takes away that Queen.

#ifndef N_QUEENS_H
#define N_QUEENS_H
#include <string>
#include <fstream>
#include <vector>

typedef std::vector < std::vector<char> > vec2D;

// Prototypes //
bool solveQueens(vec2D& cBoard, int cols);
bool safeSpace(const vec2D& cBoard, int rows, int cols);
void printBoard(const std::string& outfile, const vec2D& toPrint);

// function calls main solving function
void printNQueensSolution(int n, std::string outFile)
{
	// create chess board
	vec2D cBoard = vec2D(n, std::vector<char>(n, '-'));		
	// if a solution exists, print it
	if (solveQueens(cBoard, 0)) {
		printBoard(outFile, cBoard);
		return;
	}
	// if not, print no solution
	else {
		std::ofstream of(outFile);
		of << "No solution possible for N queens!";
		of.close();
	}

	
}

// recursive backtracking algorithm
bool solveQueens(vec2D& cBoard, int cols ) {
	// base case, if on the last column, done
	if (cols >= cBoard.size())
		return true;
	// goes through each row of the column that is passed in 
	for (int i = 0; i < cBoard.size(); i++) {
		// if this space works
		if (safeSpace(cBoard, i, cols)) {
			cBoard[i][cols] = 'Q';
			if (solveQueens(cBoard, cols + 1)) {
				return true;
			}
			// backtrack because, we didnt get true, space is not part of the solution
			cBoard[i][cols] = '-';				 /*** BACKTRACKING HERE ***/
		}
	}
	return false;
}

// function to print board
void printBoard(const std::string& outfile, const vec2D& toPrint)
{
	std::ofstream of(outfile);
	int i, j;
	for (i = 0; i < toPrint.size(); i++) {
		for (j = 0; j < toPrint.size(); j++) {
			of << toPrint[i][j] << ' ';
		}
		of << '\n';
	}
	of.close();
}

// function to determine whether a space on the gameboard is safe
bool safeSpace(const vec2D& cBoard, int rows, int cols)
{
	int i, j;
	// is everything to the left on this row safe
	for (i = 0; i < cols; i++) {
		if (cBoard[rows][i] == 'Q') {
			return false;
		}
	}

	// check diagnol to bottom left
	for (i = rows, j = cols; i >= 0 && j >= 0; i--, j--) {
		if (cBoard[i][j] == 'Q') {
			return false;
		}
	}
	
	// check diagnol to top left
	for (i = rows, j = cols; i >= 0 && j >= 0 && i < cBoard.size(); i++, j--) {
		if (cBoard[i][j] == 'Q') {
			return false;
		}
	}

	// this location is safe from other queens
	return true;
}

#endif
