//Clock.cpp

#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <string>

using namespace std;

Clock::Clock() {
	_time = 0;
};

Clock::~Clock() {

};

DigitalClock::DigitalClock(Timer* timer) {
	cout << "Attach DigitalClock" << endl;
	_timer = timer;
	_timer->Attach(this);
};

DigitalClock::~DigitalClock() {
	cout << "Detach DigitalClock" << endl;
	_timer->Detach(this);
};

Timer* DigitalClock::GetTimer() {
	return _timer;
};

void DigitalClock::PrintTime() {
	cout<<"DigitalClock: " <<_timer->GetTime() << endl;
};

void DigitalClock::Update(Timer* timer) {
	cout << "Update DigitalClock" << endl;
	_time = timer->GetTime();
	PrintTime();
};

AnalogClock::AnalogClock(Timer* timer) {
	cout << "Attach AnalogClock" << endl;
	_timer = timer;
	_timer->Attach(this);
};

AnalogClock::~AnalogClock() {
	cout << "Detach AnalogClock" << endl;
	_timer->Detach(this);
};

Timer* AnalogClock::GetTimer() {
	return _timer;
};

void AnalogClock::PrintTime() {
	cout <<"AnalogClock Clock: " << _timer->GetTime() <<endl;
};

void AnalogClock::Update(Timer* timer) {
	cout << "Update AnalogClock" << endl;
	_time = timer->GetTime();
	PrintTime();
};

