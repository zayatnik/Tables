#include "Table.h"

#pragma once

class UnSortTable : public Table {
public:
	UnSortTable() {
	}

	UnSortTable(int size1) :Table(size1) {
	}

	UnSortTable(Polynom mas1[], int size1) :Table(mas1, size1) {
	}

	bool isempty() {
		if (power == 0)
			return 1;
		else
			return 0;
	}

	bool isfull() {
		if (power == csize)
			return 1;
		else
			return 0;
	}

	int size() {
		return csize;
	}

	void insert(elem x) {
		elem ind = mas[search(x.key)];
		if (ind.key == -1) {
			if (isfull){
				this->repack;
				mas[csize / 2] = x;
			}
			else
				mas[power] = x;
			power++;
		}
		else
			cout << "error" << endl;
	}

	void remove(int key1) {
		int i = search(key1);
		elem ind = mas[i];
		if (ind.key > -1) {
			elem tmp = mas[i];
			mas[i] = mas[power-1];
			mas[power - 1] = tmp;
			power--;
		}
	}

	int search(int key1) {
		int i = 0;
		elem err;
		err.key = -1;
		while (mas[i].key != key1)
			i++;
		if (i < csize)
			return i;
		else
			return i;
	}
};
