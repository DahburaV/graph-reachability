#pragma once
#include "array.h"

bool ArrayList::checkIfSorted() {
	bool sorted = true;
	for (int i = 0; i < listSize() - 1; i++) {
		if (list[i].row > list[i + 1].row) {
			sorted = false;
			break;
		}
		else if (list[i].row == list[i + 1].row && list[i].col > list[i + 1].col) {
			sorted = false;
			break;
		}
		else
			sorted = true;
	}
	return sorted;
}

int ArrayList::nsquared() {
	int algo = ((listSize() * (listSize() - 1)) / 2) * 3;
	return algo;
}

double ArrayList::nlogn() {
	double algo = ((listSize() * log2(listSize())) - exp2(log2(listSize())) + 1);
	return ceil(algo);
}

int ArrayList::sort() {			//BUBBLE SORT
	bool swap;
	int count = 0;
	Entry temp;
	do {
		swap = false;
		for (int i = 0; i < listSize() - 1; i++) {
			if (list[i].row > list[i + 1].row) {
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swap = true;
				count++;
			}
			else if (list[i].row == list[i + 1].row && list[i].col > list[i + 1].col) {
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swap = true;
				count++;
			}
		}
	} while (swap);
	return count;
}

int ArrayList::bubbleSort() {
	int count = 0;
	Entry temp;
	for (int i = 0; i < listSize(); i++) {
		for (int j = 0; j < listSize() - 1; j++) {
			if (list[j].row > list[j + 1].row || (list[j].row == list[j + 1].row && list[j].col > list[j + 1].col)) {
				temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
				count++;
			}
			count++;
		}
	}
	return count;
}

int ArrayList::merge(ArrayList& array, int low, int high, int mid, int size) {
	int count = 0;
	int nLow = low;
	int nMid = mid + 1;
	int p = low;
	ArrayList temp(size);
	while (nLow <= mid && nMid <= high) {
		if (array.list[nLow].row < array.list[nMid].row) {
			temp.list[p] = array.list[nLow];
			p++;
			nLow++;
		}
		else if (array.list[nLow].row == array.list[nMid].row && array.list[nLow].col < array.list[nMid].col) {
			temp.list[p] = array.list[nLow];
			p++;
			nLow++;

		}
		else {
			temp.list[p] = array.list[nMid];
			p++;
			nMid++;
		}
		mergeCounter += 3;
	}
	while (nLow <= mid) {
		temp.list[p] = array.list[nLow];
		p++;
		nLow++;

	}
	while (nMid <= high) {
		temp.list[p] = array.list[nMid];
		p++;
		nMid++;

	}
	for (nLow = low; nLow < p; nLow++) {
		array.list[nLow] = temp.list[nLow];
	}
	return count;
}

int ArrayList::mergeSort(ArrayList& array, int low, int high) {
	int mid;
	int size = array.listSize();
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, high, mid, size);
	}
	return mergeCounter;
}

