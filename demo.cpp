#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "set.h"
#include <assert.h>


using namespace std;

// define your container here
typedef class my_set<int> tADT;

// define your value here		
typedef int tValue;


void addValue(tADT& adt, tValue value) {
	adt.add(value);
}

void removeValue(tADT& adt, tValue value) {
	adt.remove(value);
}

bool getValue(tADT& adt, tValue value) {
	return adt.get(value);
}

int getSize(tADT& adt) {
	return adt.get_size();
}
int getMaxSize(tADT& adt) {
	return adt.get_size();
}

void printADT(tADT& adt) {
	adt.print();
}

int main() {
	tADT adt;
	assert(getSize(adt) == 0);
	for (int i = 0; i < 10; ++i)
		addValue(adt, i);
	assert(getSize(adt) == 10);
	printADT(adt);
	assert(getValue(adt, 0));
	assert(!getValue(adt, -1));
	removeValue(adt, 0);
	assert(getSize(adt) == 9);
	printADT(adt);
	return 0;
}