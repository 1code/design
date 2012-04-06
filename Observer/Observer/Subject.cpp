//Subject.cpp

#include "Subject.h"
#include "Observer.h"
#include <iostream>

using namespace std;

Timer::Timer() {
	_clocks = new list<Clock*>;
};


Timer::~Timer() {
	//if (_clocks.empty())
		delete _clocks;
};

void Timer::Attach(Clock* clc) {
	_clocks->push_back(clc);
};

void Timer::Detach(Clock* clc) {
	if (clc != NULL) _clocks->remove(clc);
};

void Timer::Notify() {
	for (list<Clock*>::iterator it=_clocks->begin(); it != _clocks->end();it++)
		(*it)->Update(this);
};

ClockTimer::ClockTimer() {
	cout << "ClockTimer Constructor" << endl;
	_time = 0;
};

ClockTimer::~ClockTimer() { 
	cout << "ClockTimer Destructor" << endl;
};

Time ClockTimer::GetTime() {
	return _time;
};

void ClockTimer::SetTime(const Time& t) {
	_time = t;
};

AtomTimer::AtomTimer() {
	cout << "AtomTimer Constructor" << endl;
	_time = 0;
};

AtomTimer::~AtomTimer() { 
	cout << "AtomTimer Destructor" << endl;
};

Time AtomTimer::GetTime() {
	return _time;
};

void AtomTimer::SetTime(const Time& t) {
	_time = t;
};

