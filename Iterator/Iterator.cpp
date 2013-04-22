//Subject.cpp

#include "Aggregate.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

Iterator::Iterator() {

};


Iterator::~Iterator() {

};

VectorIterator::VectorIterator(Vector* v) {
	cout << "VectorIterator Constructor" << endl;
	_v = v;
};

VectorIterator::~VectorIterator() { 
	cout << "VectorIterator Destructor" << endl;
};

void VectorIterator::First() {
	_idx = 0; 
};

void VectorIterator::Next() {
	if (_idx < _v->GetSize()) _idx++;
};

bool VectorIterator::IsDone() {
	return (_idx == _v->GetSize()); 
};

Object VectorIterator::CurrentItem() {
	return _v->GetItem(_idx);	
};

