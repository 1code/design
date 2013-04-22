#include "Decorator.h"
#include <iostream>

using namespace std;

View::View() {
    cout << "View Constructor" << endl;
}

View::~View() {
    cout << "View Destructor" << endl;
}

void View::Draw() {
    cout << "View Draw" << endl;
}

TextView::TextView() {
    cout << "TextView Constructor" << endl;
}

TextView::~TextView() {
    cout << "TextView Destructor" << endl;
}

void TextView::Draw() {
    cout << "TextView Draw" << endl;
}

Decorator::Decorator(View & view) : _view(view) {
    cout << "Decorator Constructor" << endl;
}

Decorator::~Decorator() {
    cout << "Decorator Destructor" << endl;
}

void Decorator::Draw() {
    cout << "Decorator Draw" << endl;
    _view.Draw();
}

ScrollDecorator::ScrollDecorator(View & view) : Decorator(view) {
    cout << "ScrollDecorator Constructor" << endl;
}

ScrollDecorator::~ScrollDecorator() {
    cout << "ScrollDecorator Destructor" << endl;
}

void ScrollDecorator::Draw() {
    cout << "ScrollDecorator Draw" << endl;
    Decorator::Draw();
    this->ScrollTo();
}

void ScrollDecorator::ScrollTo() {
    cout << "ScrollDecorator ScrollTo" << endl;
}

BorderDecorator::BorderDecorator(View & view) : Decorator(view) {
    cout << "BorderDecorator Constructor" << endl;
}

BorderDecorator::~BorderDecorator() {
    cout << "BorderDecorator Destructor" << endl;
}

void BorderDecorator::Draw() {
    cout << "BorderDecorator Draw" << endl;
    Decorator::Draw();
    this->SketchBorder();
}

void BorderDecorator::SketchBorder() {
    cout << "BorderDecorator SketchBorder" << endl;
}
