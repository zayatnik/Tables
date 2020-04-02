#include "Table.h"

#pragma once

class SortTable : public Table {
public:
	SortTable() {
	}

	SortTable(int size1):Table(size1) {
	}

	SortTable(Polynom mas1[], int size1):Table(mas1, size1) {
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
		int mid = numsearch(x.key);
		if (ind.key = -1) {
			if (isfull)
				this->repack;
			while ((mas[mid].key < x.key) && (mas[mid + 1].key < x.key))
				mid++;
			while ((mas[mid].key > x.key) && (mas[mid + 1].key > x.key))
				mid--;
			for (int i = csize - 1; i > mid; i--)
				mas[i] = mas[i - 1];
			mas[mid] = x;
		}
		else
			cout << "error" << endl;
		power++;
	}

	void remove(int key1) {
		elem ind = search(key1);
		int mid = numsearch(key1);
		if (ind.key = -1) {
			elem* tmp = new elem[csize];
			for (int j = 0; j < mid; j++) {
				tmp[j] = mas[j];
			}
			for (int j = mid + 1; j < csize; j++) {
				tmp[j] = mas[j];
			}
			delete[] mas;
			elem* mas = new elem[csize - 1];
			for (int i = 0; i < csize - 2; i++) {
				mas[i] = tmp[i];
			}
			delete[] tmp;
			}
			power--;
		}
	}

	elem search(int key1) {
		int l = 0;
		int r = csize;
		int mid;
		bool flag = 0;
		while ((l <= r) && (flag != 1)) {
			mid = (l + r) / 2;
			if (mas[mid].key == key1)
				flag = true;
			if (mas[mid].key > key1)
				r = mid - 1;
			else l = mid + 1;
		}
		elem err;
		err.key = -1;
		if (mas[mid].key = key1)
			return mas[mid];
		else
			return err;
	}

	int numsearch(int key1) {
		int l = 0;
		int r = csize;
		int mid;
		bool flag = 0;
		while ((l <= r) && (flag != 1)) {
			mid = (l + r) / 2;
			if (mas[mid].key == key1)
				flag = true;
			if (mas[mid].key > key1)
				r = mid - 1;
			else l = mid + 1;
		}
		int err;
		err = -1;
		if (mas[mid].key = key1)
			return mid;
		else
			return err;
	}

	bool issorted() {
		bool flag = 1;
		int i = 0;
		while (i < csize - 1) {
			i++;
			if (mas[i - 1].key > mas[i].key)
				flag = 0;
		}
		return flag;
	}
};
