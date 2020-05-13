#include "pch.h"
#include "HashTable.h"

TEST(TestHashTable, isfull) {
	HashTable a;
	elem x;
	x.key = 0;
	x.val = 1;
	for (int i = 0; i < N; i++)
		a.insert(x);
	EXPECT_EQ(1, a.isfull());
}

TEST(TestHashTable, isnotfull) {
	HashTable a;
	elem x;
	x.key = 0;
	x.val = 1;
	a.insert(x);
	EXPECT_EQ(0, a.isfull());
}

TEST(TestHashTable, caninsertandsearchifcollisionbutnotcircle1) {
	HashTable a;
	elem x;
	x.key = 5;
	x.val = 1;
	elem y;
	y.key = 5;
	y.val = 1;
	a.insert(x);
	a.insert(y);
	a.remove(5);
	EXPECT_EQ(6, a.search(5));
}

TEST(TestHashTable, caninsertandsearchifcollisionbutnotcircle2) {
	HashTable a;
	elem x;
	x.key = 99;
	x.val = 1;
	elem y;
	y.key = 99;
	y.val = 1;
	a.insert(x);
	a.insert(y);
	a.remove(99);
	EXPECT_EQ(0, a.search(99));
}

TEST(TestHashTable, fullinsertwithcollisions) {
	HashTable a;
	elem x;
	x.key = 10;
	x.val = 1;
	for (int i = 0; i < N; i++)
		a.insert(x);
	int b = (a.ielem(9)).val.val;
	EXPECT_EQ(1, b);
}

TEST(TestHashTable, overflowwithcollisions) {
	HashTable a;
	elem x;
	x.key = 10;
	x.val = 1;
	for (int i = 0; i < N+1; i++)
		a.insert(x);
	int b = (a.ielem(100)).val.val;
	EXPECT_EQ(1, b);
}
