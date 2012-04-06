//Adapter.cpp

#include "Adapter.h"
#include <iostream>

using namespace std;

Shape::Shape() {

};

Shape::~Shape() {

};

void Shape::BoundingBox() {

};

TextView::TextView() {
	cout << "TextView Constructor" << endl;
};

TextView::~TextView() {
	cout << "TextView Destructor" << endl;
};

void TextView::Extend() {
	cout << "TextView Extend" << endl;
};

TextShape::TextShape(TextView* tv) {
	cout << "TextShape Constructor" << endl;
	_tv = tv;
};

TextShape::~TextShape() {
	cout << "TextShape Destructor" << endl;
};

void TextShape::BoundingBox() {
	cout << "TextShape BoundingBox" << endl;
		_tv->Extend();
};
