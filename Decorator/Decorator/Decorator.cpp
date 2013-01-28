//Decorator.cpp

#include "Decorator.h"
#include <iostream>

using namespace std;

View::View() {

};

View::~View() {

};

void View::Draw() {

};

TextView::TextView() {
	cout << "Text View Constructor" << endl;
};

TextView::~TextView() {
	cout << "Text View Destructor" << endl;
};

void TextView::Draw() {
	cout << "TextView Draw" << endl;
};

Decorator::Decorator(View *view) {
	this->_view = view;
};

Decorator::~Decorator() {
	if (_view != NULL)
		delete _view;
};

void Decorator::Draw() {
	cout << "Decorator Draw" << endl;	
	_view->Draw();
};

ScrollDecorator::ScrollDecorator(View *view) : Decorator(view) {
	cout << "ScrollDecorator Constructor" << endl;
};

ScrollDecorator::~ScrollDecorator() {
	cout <<  "ScrollDecorator Destructor" << endl;
};

void ScrollDecorator::ScrollTo() {
	cout << "ScrollDecorator ScrollTo" << endl;
};

void ScrollDecorator::Draw() {
	cout << "ScrollDecorator Draw" << endl;
	Decorator::Draw();
	this->ScrollTo();
};

BorderDecorator::BorderDecorator(View *view) : Decorator(view) {
	cout << "BorderDecorator Constructor" << endl;
};

BorderDecorator::~BorderDecorator() {
	cout <<  "BorderDecorator Destructor" << endl;
};

void BorderDecorator::DrawBorder() {
	cout << "BorderDecorator DrawBorder" << endl;
};

void BorderDecorator::Draw() {
	cout << "BorderDecorator Draw" << endl;
	Decorator::Draw();
	this->DrawBorder();
};
