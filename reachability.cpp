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
#include "ArgumentManager.h"
using namespace std;

int getNumRows(string filename);					// FUNCTION DECLATARION FOR getNumRows

int main(int argc, char *argv[])
{
	//VARIABLE DECLARATIONS
	ifstream inStreamA;
	ifstream inStreamB;
	ofstream outStream;
	string line;
	int numRowsA;
	int s;
	int k;

	//ARGUMENT MANAGER 
	ArgumentManager am(argc, argv);
	string stringS = am.get("source");
	string stringK = am.get("k");
	string dfs = am.get("dfs");
	string a = am.get("E"); 
	string b = am.get("labels");
	string c = am.get("result");
	
	//CONVERTS stringS AND stringK INTO DATA TYPE int
	stringstream convertS(stringS);
	convertS >> s;
	stringstream convertK(stringK);
	convertK >> k;
	

	//GETTING THE NUMBER OF ROWS OF INPUT MATRIX
	numRowsA = getNumRows(a.c_str());

	//CREATING THE MATRIX BASED ON NUMBER OF ROWS
	ArrayList listA(numRowsA);

	//FILLING MATRICES listA AND listB
	listA.readFile(a.c_str());

	//CHECK FOR EMPTY MATRICES										
	listA.checkEmptryMatrix(a.c_str());

	//REMOVES ZEROS FROM MATRICES IF ANY
	listA.removeZeros();

	//SORTS LIST
	listA.sort();
	
	//CHECKS IF SOURCE EXISTS
	listA.checkSourceExists(c.c_str(), s);
	
	if(dfs == "recursive" || dfs == "iterative") {
	//SETS answerList = ZERO FOR DFT
	listA.dfsAnswerPrep();

	// DFS
	listA.dfs(0, s, s, k); 
	
	//SEND REACHABLE VERTICIES TO OUTPUT
	listA.dfsOutput(c.c_str());
	}
	
	else { 
	// VECTOR-MATRIX MULTIPLICATION
	listA.vectorMatrixMult(s, k);
	
	// SEND REACHABLE VERTICES TO OUTPUT 
	listA.reachOutput(c.c_str());
	}
	
	

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


