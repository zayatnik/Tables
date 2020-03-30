#include "Polynom.h"

#pragma once

struct elem {
	Polynom val;
	int key;
};

class Table{
public:
	virtual bool isempty() {
	}
	virtual bool isfull() {
	}
	virtual int size() {
	}
	virtual void insert(Polynom x) {
	}
	virtual void remove(int key1) {
	}
	virtual elem search(int key1) {
	}
};
