//------------------------------------------------------//
//														//
//	Reachability From a Source Vertex :: main.cpp		//
//	Created by: Viktor Dahbura							//
//	Date: 11/13/2016									//
//														//
//------------------------------------------------------//

#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "array.h"
#include "arraysort.h"
#include "arraysearch.h"
#include "linkedlist.h"
using namespace std;

int getNumRows(string filename);										// FUNCTION DECLATARION FOR getNumRows

int main()
{
	ifstream inStreamA;
	ifstream inStreamB;
	ofstream outStream;
	string line;
	int s = 12;
	int k = 3;
	int numRowsA;
	int numRowsB;
	int numRowsC;


	//GETTING THE NUMBER OF ROWS OF INPUT MATRIX
	numRowsA = getNumRows("A.txt");

	//NUMBER OF POSSIBLE ENTRIES FOR listC
	numRowsC = numRowsA;

	//CREATING THE MATRIX BASED ON NUMBER OF ROWS
	ArrayList listA(numRowsA);

	//FILLING MATRICES listA AND listB
	listA.readFile("A.txt");

	//CHECK FOR EMPTY MATRICES										
	listA.checkEmptryMatrix("C.txt");

	//REMOVES ZEROS FROM MATRICES IF ANY
	listA.removeZeros();

	//SORTS LIST
	listA.sort();

	//CHECKS IF SOURCE EXISTS
	listA.checkSourceExists("C.txt", s);

	// VECTOR-MATRIX MULTIPLICATION
	//listA.vectorMatrixMult(s, k);
	
	//SETS answerList = ZERO FOR DFT
	listA.dfsAnswerPrep();

	// DFT
	listA.dfs(0, s, s, k); 

	// SEND REACHABLE VERTICES TO OUTPUT 
	//listA.reachOutput("C.txt");

	listA.dfsOutput("C.txt");


	//TESTING
	cout << numRowsA << " <--- number of rows A" << endl;
	cout << listA.maxRow() << " <--- maxRow " << endl;
	cout << listA.maxCol() << " <--- maxCol " << endl << endl;
	listA.print();
	cout << endl << endl;
	cout << s << ", " << k << " <--- s & k ";
	cout << endl << endl;
	//listA.printSource();
	cout << " <--- source row vector ";
	cout << endl << endl;
	//listA.printTemp();
	cout << " <--- last row vector multiplied ";
	cout << endl << endl;
	listA.printAnswer();
	cout << " <--- answer for vector-matrix mult" << endl << endl;
	listA.printFinalAnswer();
	cout << " <--- reachable vertices " << endl << endl;
	listA.printDfsAnswer();
	cout << " <--- dfs reachable vertices " << endl << endl;

	system("pause");
	return 0;
}

//getNumRows FUNCTION DEFINITION
int getNumRows(string filename) {
	ifstream inStream;
	string line;
	int numRows = 0;
	int temp;
	inStream.open(filename);
	while (getline(inStream, line)) {
		if (line[0] == '#' || line.length() == 0) continue;
		istringstream fn(line);
		fn >> temp;
		numRows++;
	}
	inStream.close();
	return numRows++;
}


