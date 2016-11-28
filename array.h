//------------------------------------------------------//
//														//
//	Reachability From a Source Vertex :: array.h		//
//	Created by: Viktor Dahbura							//
//	Date: 11/13/2016									//
//														//
//------------------------------------------------------//

#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

struct Entry {
	int row;
	int col;
	float value;
};

class ArrayList {
public:
	//CONSTRUCTORS/DESTRUCTORS
	ArrayList(int size);
	ArrayList();
	~ArrayList();

	//ARRAY FUNCTIONALITY
	int listSize() const;
	int maxListSize() const;
	void fill(int loc, int row, int col, float value);
	void print();
	void printTemp();
	void printAnswer();
	void printSource();
	void printFinalAnswer();
	void printDfsAnswer();
	int maxRow();
	int minRow();
	int maxCol();
	int minCol();
	int getRow(int loc);
	int getCol(int loc);
	float getValue(int loc);
	void readFile(string filename);
	void checkEmptryMatrix(string filename);
	void compareSizes(ArrayList& listB, string filename);
	void dotProductNonSorted(ArrayList& listB, ArrayList& listC);
	void dotProductSorted(ArrayList& listB, ArrayList& listC);
	void moveToC(ArrayList& listA, ArrayList& listB, ArrayList& listC);
	void removeAt(int loc);
	void removeZeros();
	bool compareVal(int n, int m);
	int getLineLoc(int n, int m);
	void sendToOutput(string filename);
	void checkSourceExists(string filename, int source);
	void vectorMatrixMult(int s, int k);
	void reachOutput(string filename);
	void dfsAnswerPrep();
	void dfs(int counter, int source, int s, int k);
	void dfsToAnswerList(int n);
	void dfsOutput(string filename);
	

	//SORTING RELATED
	bool checkIfSorted();												//FUNCTION DEFINITION ON arraysort.h
	int sort();															//SUPPLEMENTARY SORT FUNCTION (NOT USED IN FINAL VERSION OF PROGRAM)
	int nsquared();														//RETURNS ALGORTIHM FOR nsquared
	double nlogn();														//RETURNS ALGORITHM FOR nlogn
	int bubbleSort();													//BUBBLE SORT bigO(n^2), FUNCTION DEFINITION ON arraysort.h	
	int merge(ArrayList& array, int low, int high, int mid, int size);	//MERGE SORT bigO(nlogn), FUNCTION DEFINITION ON arraysort.h
	int mergeSort(ArrayList& array, int low, int high);					//MERGE SORT bigO(nlogn), FUNCTION DEFINITION ON arraysort.h

	//SEARCH RELATED
	int seqSearch(int n, int m);										//FUNCTION DEFINITION ON arraysearch.h
	int binSearch(int n, int m);										//FUNCTION DEFINITION ON arraysearch.h
	bool binSearch2(int n);												//FUNCTION DEFINITION ON arraysearch.h
	bool seqSearch2(int n);

	//VARIABLES
	Entry *list;
	int *tempList;		//	USED FOR VECTOR-MATRIX MULTIPLICATION
	int *sourceList;	//	|
	int *updateList;	//	|
	int *tempList2;		//	|
	int *answerList;	//	v
	int length;
	int maxSize;
	int mergeCounter = 0;
};

ArrayList::ArrayList(int size)
{
	maxSize = size;
	length = 0;
	list = new Entry[maxSize];
	assert(list != NULL);
}

ArrayList::~ArrayList() {
	delete[] list;
}

int ArrayList::listSize() const {
	return length;
}

int ArrayList::maxListSize() const {
	return maxSize;
}

void ArrayList::fill(int loc, int row, int col, float value) {
	list[loc].row = row;
	list[loc].col = col;
	list[loc].value = value;
	length++;
}

void ArrayList::print() {
	for (int i = 0; i < length; i++) {
		cout << list[i].row << " " << list[i].col << " " << setprecision(2) << fixed << list[i].value << endl;
	}
}

void ArrayList::printTemp() {
	for (int i = 0; i < maxRow(); i++) {
		cout << tempList[i] << " ";
	}
}

void ArrayList::printAnswer() {
	for (int i = 0; i < maxRow(); i++) {
		cout << answerList[i] << " ";
	}
}

void ArrayList::printSource() {
	for (int i = 0; i < maxRow(); i++) {
		cout << sourceList[i] << " ";
	}
}

void ArrayList::printFinalAnswer() {
	for (int i = 0; i < maxRow(); i++) {
		if (answerList[i] == 1)
			cout << i + 1 << " ";
	}
}

void ArrayList::printDfsAnswer() {
	for (int i = 0; i < maxCol(); i++) {
		if (answerList[i] > 0)
			cout << answerList[i] << " ";
	}
}

int ArrayList::maxRow() {
	int maxRow = getRow(0);
	for (int i = 0; i < listSize(); i++) {
		if (getRow(i) > maxRow)
			maxRow = getRow(i);
		else
			continue;
	}
	return maxRow;
}

int ArrayList::minRow() {
	int minRow = getRow(0);
	for (int i = 0; i < listSize(); i++) {
		if (getRow(i) < minRow)
			minRow = getRow(i);
		else
			continue;
	}
	return minRow;
}

int ArrayList::maxCol() {
	int maxCol = getCol(0);
	for (int i = 0; i < listSize(); i++) {
		if (getCol(i) > maxCol)
			maxCol = getCol(i);
		else
			continue;
	}
	return maxCol;
}

int ArrayList::minCol() {
	int minCol = getCol(0);
	for (int i = 0; i < listSize(); i++) {
		if (getCol(i) < minCol)
			minCol = getCol(i);
		else
			continue;
	}
	return minCol;
}

int ArrayList::getRow(int loc) {
	return list[loc].row;
}

int ArrayList::getCol(int loc) {
	return list[loc].col;
}

float ArrayList::getValue(int loc) {
	return list[loc].value;
}

void ArrayList::readFile(string filename) {
	int row, col;
	int n = 0;
	float value;
	string line;
	ifstream inStream;
	inStream.open(filename);
	while (getline(inStream, line)) {
		if (line[0] == '#' || line.length() == 0) continue;
		istringstream fn(line);
		fn >> row >> col >> value;
		if (row > 0 && col > 0) {
			fill(n, row, col, value);
			n++;
		}
	}
	inStream.close();
}

void ArrayList::checkEmptryMatrix(string filename) {
	ofstream outStream;
	if (maxListSize() == 0) {
		cout << "Empty Matrix " << endl;
		cout << "Terminating Program... " << endl;
		outStream.open(filename);
		outStream.close();

		system("pause");
		exit(1);
	}
}

void ArrayList::compareSizes(ArrayList& listB, string filename) {
	ofstream outStream;
	if (maxCol() != listB.maxRow()) {
		cout << maxRow() << " " << maxCol() << " <- list A's max Row and max Col" << endl;
		cout << listB.maxRow() << " " << listB.maxCol() << " <- list B's max Row and max Col" << endl;
		cout << "Sparse matrices are not compatible for multiplication." << endl;
		cout << "Generating empty output File..." << endl;
		outStream.open(filename);
		outStream.close();

		system("pause");
		exit(1);
	}
}

void ArrayList::moveToC(ArrayList& listA, ArrayList& listB, ArrayList& listC) {
	int i;
	int j = 0;
	for (i = 0; i < listC.maxListSize() && i < listA.listSize(); i++) {
		listC.fill(i, listA.getRow(i), listA.getCol(i), listA.getValue(i));
	}
}

void ArrayList::removeZeros() {
	for (int i = 0; i < length - 1; i++) {
		if (list[i].value == 0) {
			removeAt(i);
			i--;
		}
		else
			continue;
	}
}

void ArrayList::removeAt(int loc) {
	for (int i = loc; i < length - 1; i++)
		list[i] = list[i + 1];
	length--;
}

bool ArrayList::compareVal(int n, int m) {
	bool found = false;
	for (int i = 0; i < listSize(); i++) {
		if (n == getRow(i) && m == getCol(i)) {
			found = true;
		}
		else
			continue;
	}
	return found;
}

int ArrayList::getLineLoc(int n, int m) {
	for (int i = 0; i < listSize(); i++) {
		if (n == getRow(i) && m == getCol(i)) {
			return i;
		}
		else
			continue;
	}
	return 0;
}

void ArrayList::sendToOutput(string filename) {
	ofstream outStream;
	outStream.open(filename);
	outStream << "#Matrix C=A+B" << endl;
	for (int i = 0; i < listSize(); i++) {
		outStream << getRow(i) << " " << getCol(i) << " " << setprecision(2) << fixed << getValue(i) << endl;
	}
	outStream.close();
}

void ArrayList::dotProductNonSorted(ArrayList& listB, ArrayList& listC) {
	float valA;
	float valB;
	float mult = 0;
	float addMult;
	int searchA;
	int searchB;
	int n = 0;
	int actualMaxRow = maxRow();
	int actualMaxCol = maxCol();

	if (actualMaxRow < listB.maxRow())
		actualMaxRow = listB.maxRow();
	if (actualMaxCol < listB.maxCol())
		actualMaxCol = listB.maxCol();

	for (int i = 1; i <= maxRow(); i++) {
		for (int count = 1; count <= listB.maxCol(); count++) {
			addMult = 0;
			for (int j = 1; j <= maxCol(); j++) {
				searchA = seqSearch(i, j);
				if (searchA != -1)
					valA = getValue(searchA);
				else
					continue;
				searchB = listB.seqSearch(j, count);
				if (searchB != -1) {
					valB = listB.getValue(searchB);
					addMult += (valA * valB);
				}
				else
					continue;
			}
			if (addMult != 0) {
				listC.fill(n, i, count, addMult);
				n++;
			}
			else if (i == actualMaxRow && count == actualMaxCol) {
				listC.fill(n, i, count, addMult);
				n++;
			}
			if (listC.listSize() == 0)
				listC.fill(0, minRow(), minCol(), 0);
		}
	}
}

void ArrayList::dotProductSorted(ArrayList& listB, ArrayList& listC) {
	float valA;
	float valB;
	float mult = 0;
	float addMult;
	int searchA;
	int searchB;
	int n = 0;
	int actualMaxRow = maxRow();
	int actualMaxCol = maxCol();
	int p = 0;

	if (actualMaxRow < listB.maxRow())
		actualMaxRow = listB.maxRow();
	if (actualMaxCol < listB.maxCol())
		actualMaxCol = listB.maxCol();

	for (int i = 1; i <= maxRow(); i++) {
		for (int count = 1; count <= listB.maxCol(); count++) {
			addMult = 0;
			for (int j = 1; j <= maxCol(); j++) {
				searchA = binSearch(i, j);
				if (searchA != -1)
					valA = getValue(searchA);
				else
					continue;
				searchB = listB.binSearch(j, count);
				if (searchB != -1) {
					valB = listB.getValue(searchB);
					addMult += (valA * valB);
				}
				else
					continue;
			}
			if (addMult != 0) {
				listC.fill(n, i, count, addMult);
				n++;
			}
			else if (i == actualMaxRow && count == actualMaxCol) {
				listC.fill(n, i, count, addMult);
				n++;
			}
			if (listC.listSize() == 0)
				listC.fill(0, minRow(), minCol(), 0);
		}
	}
}

void ArrayList::vectorMatrixMult(int s, int k) {
	int n = maxCol();
	tempList = new int[n];			// CREATES AND HOLDS THE ITERATIVE ARRAY 1 X n
	tempList2 = new int[n];
	sourceList = new int[n];
	updateList = new int[n];
	answerList = new int[n];		// CREATES THE ANSWER ARRAY 1 x n (ROW VECTOR)
	int m = 0;
	int d = 0;
	int search;
	int addMult;
	tempList[s - 1] = 1;


	// FIRST ROW VECTOR BASED ON s, INITIAL VALUES FOR tempList
	for (int i = 0; i < n; i++) {
		if (tempList[i] == 1)
			continue;
		else
			tempList[i] = 0;
	}
	// CREATING SOURCE LIST AND PREPPING ANSWER LIST WITH SOURCE VERTEX
	for (int i = 0; i < n; i++) {
		if (tempList[i] == 1) {
			sourceList[i] = 1;
			answerList[i] = 1;
		}
		else {
			sourceList[i] = 0;
			answerList[i] = 0;
		}
	}
	// SETTING tempList2 AND updateList EQUAL TO ZERO
	for (int i = 0; i < n; i++) {
		tempList2[i] = 0;
		updateList[i] = 0;
	}

	while (d < k) {											// ITERATIONS CONDITION
		for (int count = 1; count <= maxCol(); count++) {
			for (int i = 1; i <= maxRow(); i++) {
				addMult = 0;
				search = binSearch(i, count);
				if (search != -1)							// IF FOUND, MULTIPLY VALUES
					addMult += (tempList[i - 1] * getValue(search));
				else
					continue;
				if (addMult != 0)
					updateList[count - 1] = addMult;		// ADD THE addMult TO THE updateList TO LATER MOVE TO answerList
			}
		}
		for (int i = 0; i < maxCol(); i++) {				// UPDATING answerList WITH THE NEW VALUES OF updateList
			if (updateList[i] == 1)
				answerList[i] = 1;
			if (updateList[i] == 1)							// SETTING tempList TO updateList FOR NEXT ITERATION 
				tempList[i] = 1;
			else
				tempList[i] = 0;
		}
		for (int i = 0; i < maxCol(); i++) {				// RESETTING updateList TO ZERO VALUES FOR NEXT ITERATION
			updateList[i] = 0;
		}
		d++;
	}

}

void ArrayList::reachOutput(string filename) {
	ofstream outStream;
	outStream.open(filename);
	for (int i = 0; i < maxRow(); i++) {
		if (answerList[i] == 1)
			outStream << i + 1 << endl;
	}
	outStream.close();
}

void ArrayList::dfsAnswerPrep() {
	answerList = new int[maxCol()];
	for (int i = 0; i < maxCol(); i++) {
		answerList[i] = 0;
	}

}

void ArrayList::dfs(int counter, int source, int v, int k) {
	counter++;
	if (counter > k)
		return;
	int w;
	int search = -1;
	
	for (int i = 1; i <= maxCol(); i++) {
		search = binSearch(v, i);
		if (search != -1) {
			w = getCol(search);
			if(w != source)
				dfsToAnswerList(w);
		}
		else
			continue;
		dfs(counter, source, w, k);
	}
}

void ArrayList::dfsToAnswerList(int n) {
	for (int i = 0; i < maxCol(); i++) {
		if (answerList[i] == 0 && seqSearch2(n) == false)   {
			answerList[i] = n;
			return;
		}
		else
			continue;
	}
}

void ArrayList::dfsOutput(string filename) {
	ofstream outStream;
	outStream.open(filename);
	for (int i = 0; i < maxRow(); i++) {
		if (answerList[i] > 0)
			outStream << answerList[i] << endl;
	}
	outStream.close();
}

void ArrayList::checkSourceExists(string filename, int source) {
	ofstream outStream;
	if (binSearch2(source) == false) {
		cout << "Source does not have any possible connecting paths..." << endl;
		cout << "Sending source id to result file..." << endl;
		outStream.open(filename);
		outStream << source << endl;
		outStream.close();

		system("pause");
		exit(1);
	}
}
