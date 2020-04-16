#include "Table.h"

#pragma once

class HashTable : public Table {
public:
	HashTable() {
		mas = new elem[100];
		csize = 100;
		power = 0;
		for (int i = 0; i < csize; i++)
			mas[i].key = -1;
	}

	HashTable(int size1) {
		mas = new elem[size1-(size1%100)+100];
		csize = size1 - (size1 % 100) + 100;
		power = 0;
		for (int i = 0; i < csize; i++)
			mas[i].key = -1;
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

	int hash(int key1) {
		return key1%100;
	}

	int search(int key1) {
		int i = hash(key1);
		while ((mas[i].key != key1)&&(i < csize))
			i = i + 100;
		return i;
	}

	void insert(elem x) {
		int i = hash(x.key);
		bool flag = 0;
		while (i < csize) {
			if (mas[i].key != (-1)) {
				mas[i] = x;
				flag = 1;
				if (i > power)
					power = i;
			}
			i = i + 100;
		}
		if (flag == 0) {
			this->repack;
			mas[csize - 100 + hash(x.key)] = x;
			power = csize - 100 + hash(x.key);
		}
	}

	void remove(int key1) {
		if (search(key1) < csize) {
			mas[search(key1)].key = -1;
			if (search(key1) == power) {
				bool flag = 0;
				int i = power - 1;
				while (flag == 0) {
					if (mas[i].key > -1) {
						power = i;
						flag = 1;
					}
					i--;
				}
			}
		}
		else
			cout << "error";
	}
};
