//Aggregate.cpp

#include "Aggregate.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

Container::Container() {
};

Container::~Container() {

};

Vector::Vector() {
	cout << "Vector Constructor" << endl;
	for (int i = 0; i < SIZE; i++)
		_objs[i] = 0;
};

Vector::~Vector() {
	cout << "Vector Destructor" << endl;
};

Iterator* Vector::CreateIterator() {
	return new VectorIterator(this);
}

Object Vector::GetItem(int idx) {
	if (idx < this->GetSize ())
		return _objs[idx];
	return -1;
}

int Vector::GetSize() {
	return SIZE;
}
