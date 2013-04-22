//Template.cpp

#include "Template.h"
#include <iostream>

using namespace std;

void Shape::draw(ShapeColor color) const {
	this->doDraw(color);
};


void Circle::doDraw(ShapeColor color) const {
	cout << "Draw a circle: " << color << endl;
};

void Rectangle::doDraw(ShapeColor color) const {
	cout << "Draw a Rectangle: " << color << endl;
};


