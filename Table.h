#include "Polynom.h"

#pragma once

struct elem {
	Polynom val;
	int key;
};

class Table{
protected:
	int csize;
	elem* mas;
	elem* end;
	int power;
public:
	Table() {
		mas = new elem[1];
		csize = 1;
		power = 0;
		end = mas;
		mas[0].key = -1;
	}

	Table(int size1) {
		mas = new elem[size1];
		csize = size1;
		power = 0;
		end = mas;
		for (int i = 0; i < size1; i++)
			mas[i].key = -1;
	}

	Table(Polynom mas1[], int size1) {
		mas = new elem[size1];
		for (int i = 0; i < size1; i++) {
			mas[i].val = mas1[i];
			mas[i].key = i + 1;
		}
		csize = size1;
		power = size1;
		this->newendisthelast;
	}

	virtual ~Table() {
		delete[] mas;
	}

	void newendisthelast() {
		*end = mas[csize];
		end = &mas[csize];
	}

	void repack() {
		elem* tmp = new elem[2 * csize];
		for (int i = 0; i < csize; i++) {
			tmp[i] = mas[i];
		}
		delete[] mas;
		mas = tmp;
		csize = csize * 2;
	}

	virtual bool isempty() {
	}
	virtual bool isfull() {
	}
	virtual int size() {
	}
	virtual void insert(elem x) {
	}
	virtual void remove(int key1) {
	}
	virtual int search(int key1) {
	}
};
