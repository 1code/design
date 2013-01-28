//main.cpp

#include "Subject.h"
#include "Observer.h"

using namespace std;
int main(int argc, const char * argv[])
{
    Timer* timer = new ClockTimer();
	Clock* dc = new DigitalClock(timer);
	Clock* ac = new AnalogClock(timer);
	timer->SetTime(11);
	timer->Notify();
	timer->SetTime(12);
	timer->Notify();
	delete dc;
	delete ac;
	delete timer;
	timer = new AtomTimer();
	dc = new DigitalClock(timer);
	ac = new AnalogClock(timer);
	timer->SetTime(10);
	timer->Notify();
	delete dc;
	delete ac;
	delete timer;
	return 0;

}

