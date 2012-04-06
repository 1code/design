//Abstraction.cpp

#include "Abstraction.h"
#include "AbstractionImp.h"

#include <iostream>

using namespace std;

Window::Window() {

};

Window::~Window() {

};

IconWindow::IconWindow(WindowImp *imp) {
	cout << "IconWindow Contructor" << endl;
	_imp = imp;
}

IconWindow::~IconWindow() {
	cout << "IconWindow Destructor" << endl;
	delete _imp;
};

void IconWindow::DrawContents() {
	_imp->DrawText();
	_imp->DrawLine();
};

TransientWindow::TransientWindow(WindowImp *imp) {
	cout << "TransientWindow Contructor" << endl;
	_imp = imp;
}

TransientWindow::~TransientWindow() {
	cout << "TransientWindow Contructor" << endl;
	delete _imp;
};

void TransientWindow::DrawContents() {
	_imp->DrawText();
	_imp->DrawLine();
};
