#pragma once
#include "array.h"

int ArrayList::seqSearch(int n, int m) {
	int loc;
	bool found = false;
	for (loc = 0; loc < listSize(); loc++) {
		if (list[loc].row == n && list[loc].col == m) {
			found = true;
			break;
		}
	}
	if (found)
		return loc;
	else
		return -1;
}

int ArrayList::binSearch(int n, int m) {
	int first = 0;
	int last = listSize() - 1;
	int mid;
	bool found = false;

	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (getRow(mid) == n && getCol(mid) == m)
			found = true;
		else if (getRow(mid) > n || (getRow(mid) == n && getCol(mid) > m))
			last = mid - 1;
		else if (getRow(mid) < n || (getRow(mid) == n && getCol(mid) < m))
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}

bool ArrayList::binSearch2(int n) {
	int first = 0;
	int last = listSize() - 1;
	int mid;
	bool found = false;

	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (getRow(mid) == n)
			found = true;
		else if (getRow(mid) > n)
			last = mid - 1;
		else if (getRow(mid) < n)
			first = mid + 1;
	}
	return found;
}

bool ArrayList::seqSearch2(int n) {
	bool found = false;
	for (int i = 0; i < maxCol(); i++) {
		if (answerList[i] == n) {
			found = true;
			break;
		}
	}
	return found;
}
