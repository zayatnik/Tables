#include "Table.h"

#pragma once

class UnSortTable : public Table {
	int size;
	elem* mas;
	elem* end;
	int maxkey;
	int power;
public:
	UnSortTable() {
		mas = new elem[1];
		size = 1;
		power = 0;
		maxkey = 0;
		end = mas;
		mas[0].key = -1;
	}

	UnSortTable(int size1) {
		mas = new elem[size1];
		size = size1;
		power = 0;
		maxkey = 0;
		end = mas;
		for (int i = 0; i < size1; i++)
			mas[i].key = -1;
	}

	UnSortTable(Polynom mas1[], int size1) {
		mas = new elem[size1];
		for (int i = 0; i < size1; i++) {
			mas[i].val = mas1[i];
			mas[i].key = i + 1;
		}
		size = size1;
		power = size1;
		maxkey = size1;
		*end = mas[size - 1];
		end = &mas[size-1];
	}

	~UnSortTable(){
			delete[] mas;
	}

	bool isempty() {
		if (power == 0)
			return 1;
		else
			return 0;
	}

	bool isfull() {
		if (power == size)
			return 1;
		else
			return 0;
	}

	int size() {
		return size;
	}

	void insert(Polynom x) {
		if (power == size) {
			elem* tmp = new elem[size];
			for (int i = 0; i < size; i++) {
				tmp[i].val = mas[i].val;
				tmp[i].key = mas[i].key;
			}
			delete[] mas;
			elem* mas = new elem[size + 1];
			for (int i = 0; i < size; i++) {
				mas[i].val = tmp[i].val;
				mas[i].key = tmp[i].key;
			}
			delete[] tmp;
			mas[size].val = x;
			mas[size].key = maxkey + 1;
			size++;
			*end = mas[size - 1];
			end = &mas[size - 1];
		}
		else {
			int i = 0;
			while (mas[i].key > -1)
				i++;
			mas[i].val = x;
			mas[i].key = maxkey + 1;
		}
		maxkey++;
		power++;
	}

	void remove(int key1) {
		int i = 0;
		while (mas[i].key != key1)
			i++;
		elem* tmp = new elem[size];
		for (int j = 0; j < i; j++) {
			tmp[j].val = mas[j].val;
			tmp[j].key = mas[j].key;
		}
		for (int j = i+1; j < size; j++) {
			tmp[j].val = mas[j].val;
			tmp[j].key = mas[j].key;
		}
		delete[] mas;
		elem* mas = new elem[size - 1];
		for (int i = 0; i < size - 2; i++) {
			mas[i].val = tmp[i].val;
			mas[i].key = tmp[i].key;
		}
		delete[] tmp;
		if (i == size - 1) {
			size--;
			*end = mas[size - 1];
			end = &mas[size - 1];
		}
		power--;
	}

	elem search(int key1) {
		int i = 0;
		while (mas[i].key != key1)
			i++;
		return mas[i];
	}
};
