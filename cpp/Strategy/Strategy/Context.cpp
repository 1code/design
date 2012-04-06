//Context.cpp

#include "Context.h"
#include "Strategy.h"
#include <iostream>

using namespace std;

Composition::Composition(Compositor* com) {
	_com = com;
};

Composition::~Composition() {
	if (NULL != _com)
		delete _com;
};

void Composition::Repair() {
	_com->Compose();
};
