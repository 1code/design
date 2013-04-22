//AbstractionImp.cpp

#include "AbstractionImp.h"
#include <iostream>

using namespace std;

WindowImp::WindowImp() {

};

WindowImp::~WindowImp() {

};

void WindowImp::DrawText() {

};

void WindowImp::DrawLine() {

};

XWindowImp::XWindowImp() {

};

XWindowImp::~XWindowImp() {

};

void XWindowImp::DrawText() {
	cout << "XWindowImp DrawText" << endl;
};

void XWindowImp::DrawLine() {
	cout << "XWindowImp DrawLine" << endl;
};

PMWindowImp::PMWindowImp() {

};

PMWindowImp::~PMWindowImp() {

};

void PMWindowImp::DrawText() {
	cout << "PMWindowImp DrawText" << endl;
};

void PMWindowImp::DrawLine() {
	cout << "PMWindowImp DrawLine" << endl;
};

