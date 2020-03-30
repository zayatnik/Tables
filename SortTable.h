#include "Table.h"

#pragma once

class SortTable : public Table {
	int size;
	elem* mas;
	elem* end;
	int maxkey;
	int power;
public:
	SortTable() {
		mas = new elem[1];
		size = 1;
		power = 0;
		maxkey = 0;
		end = mas;
		mas[0].key = -1;
	}

	SortTable(int size1) {
		mas = new elem[size1];
		size = size1;
		power = 0;
		maxkey = 0;
		end = mas;
		for (int i = 0; i < size1; i++)
			mas[i].key = -1;
	}

	SortTable(Polynom mas1[], int size1) {
		mas = new elem[size1];
		for (int i = 0; i < size1; i++) {
			mas[i].val = mas1[i];
			mas[i].key = i + 1;
		}
		size = size1;
		power = size1;
		maxkey = size1;
		*end = mas[size - 1];
		end = &mas[size - 1];
	}

	~SortTable() {
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
			for (int j = i; j < size - 1; j++) {
				mas[j].val = mas[j + 1].val;
				mas[j].key = mas[j + 1].key;
			}
			mas[size - 1].val = x;
			mas[size - 1].key = maxkey + 1;
		}
		maxkey++;
		power++;
	}

	void remove(int key1) {
		int l = 0;
		int r = size;
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
		elem* tmp = new elem[size];
		for (int j = 0; j < mid; j++) {
			tmp[j].val = mas[j].val;
			tmp[j].key = mas[j].key;
		}
		for (int j = mid + 1; j < size; j++) {
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
		if (mid == size - 1) {
			size--;
			*end = mas[size - 1];
			end = &mas[size - 1];
		}
		power--;
	}

	elem search(int key1) {
		int l = 0;
		int r = size;
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
		return mas[mid];
	}

	bool issorted() {
		bool flag = 1;
		int i = 0;
		while (i < size - 1) {
			i++;
			if (mas[i - 1].key > mas[i].key)
				flag = 0;
		}
		return flag;
	}
};
