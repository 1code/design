//Receiver.cpp

#include "Receiver.h"
#include <iostream>

using namespace std;

Document::Document() {
	cout << "Document Constructor" << endl;
};

Document::~Document() { 
	cout << "Document Destructor" << endl;
};

void Document::Open() {
	cout << "Document Open" << endl;
};

void Document::Paste() {
	cout << "Document Paste" << endl;
};


