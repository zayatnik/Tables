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
		elem ind = search(x.key);
		if (ind.key = -1) {
			this->repack;
			mas[csize / 2] = x;
			this->newend;
			power++;
		}
		else
			cout << "error" << endl;
	}

	void remove(int key1) {
		elem ind = search(key1);
		if (ind.key > -1) {
			int i = 0;
			while (mas[i].key != key1)
				i++;
			elem* tmp = new elem[csize];
			for (int j = 0; j < i; j++) {
				tmp[j] = mas[j];
			}
			for (int j = i + 1; j < csize; j++) {
				tmp[j] = mas[j];
			}
			delete[] mas;
			elem* mas = new elem[csize - 1];
			for (int i = 0; i < csize - 2; i++) {
				mas[i] = tmp[i];
			}
			delete[] tmp;
			if (i == csize - 1) {
				csize--;
				this->newend;
			}
			power--;
		}
	}

	elem search(int key1) {
		int i = 0;
		elem err;
		err.key = -1;
		while (mas[i].key != key1)
			i++;
		if (i < csize)
			return mas[i];
		else
			return err;
	}
};
