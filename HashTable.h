#include "Table.h"

#pragma once

#define N 100

struct elem {
	Polynom val;
	int key;
};

struct el {
	elem val;
	bool stat;
};

class HashTable : public Table {
protected:
	int csize;
	el* mas;
	int power;
public:
	HashTable() {
		mas = new el[N];
		csize = N;
		power = 0;
		for (int i = 0; i < csize; i++) {
			mas[i].val.key = -1;
			mas[i].stat = false;
		}
	}

	HashTable(int size1) {
		mas = new el[size1 - (size1%N) + N];
		csize = size1 - (size1 % N) + N;
		power = 0;
		for (int i = 0; i < csize; i++) {
			mas[i].val.key = -1;
			mas[i].stat = false;
		}
	}

	bool isempty() {
		return power == 0;
	}

	bool isfull() {
		if (power == csize)
			return 1;
		else
			return 0;
	}

	int size() {
		return power;
	}

	int hash(int key1) {
		return key1 % csize;
	}

	int search(int key1) {
		int i = hash(key1);
		bool flag = false;
		while ((flag == false) && (i < csize)) {
			if ((mas[i].val.key == key1) && (mas[i].stat == false))
				flag = true;
			else
				i++;
		}
		if (flag == false) {
			int j = 0;
			while ((flag == false) && (i < hash(key1)))
				if ((mas[j].val.key == key1) && (mas[j].stat == false)) {
					flag = true;
					i = j;
				}
				else j++;
		}
		return i;
	}

	void insert(elem x) {
		int i = hash(x.key);
		while ((mas[i].val.key != -1) && (mas[i].stat == false) && (i != hash(x.key) - 1))
			i = (i + 1) % csize;
		if ((i < hash(x.key) - 1) || (i >= hash(x.key))) {
			mas[i].val = x;
			mas[i].stat = false;
		}
		if (i == hash(x.key) - 1) {
			if ((mas[i].val.key == -1) || (mas[i].stat == true)) {
				mas[i].val = x;
				mas[i].stat = false;
			}
			else {
				el* tmp = new el[2 * csize];
				for (int i = 0; i < csize; i++) {
					tmp[i] = mas[i];
				}
				delete[] mas;
				mas = tmp;
				csize = csize * 2;
				mas[csize / 2].val = x;
				power = csize / 2;
			}
		}
	}

	void remove(int key1) {
		if (search(key1) < csize) {
			mas[search(key1)].val.key = -1;
			mas[search(key1)].stat = true;
		}
	}
};
