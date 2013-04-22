//Strategy.cpp

#include "Strategy.h"
#include <iostream>

using namespace std;

Compositor::Compositor() {

};

Compositor::~Compositor() {

};

void Compositor::Compose() {

};

SimpleCompositor::SimpleCompositor() {
	cout << "SimpleCompositor Constructor" << endl;
};

SimpleCompositor::~SimpleCompositor() {
	cout << "SimpleCompositor Destructor" << endl;
};

void SimpleCompositor::Compose() {
	cout << "SimpleCompositor Compose" << endl;
};

TexCompositor::TexCompositor() {
	cout << "TexCompositor Constructor" << endl;
};

TexCompositor::~TexCompositor() {
	cout << "TexCompositor Destructor" << endl;
};

void TexCompositor::Compose() {
	cout << "TexCompositor Compose" <<endl;
};

ArrayCompositor::ArrayCompositor() {
	cout << "ArrayCompositor Constructor" << endl;
};

ArrayCompositor::~ArrayCompositor() {
	cout << "ArrayCompositor Destructor" << endl;
};

void ArrayCompositor::Compose() {
	cout << "ArrayCompositor Compose" <<endl;
};

