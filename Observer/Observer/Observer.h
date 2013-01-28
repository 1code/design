//Observer.h

#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "Subject.h"

using namespace std;

typedef unsigned int Time;

class Clock {
	public:
		virtual ~Clock();
		virtual void Update(Timer* timer) = 0;
		virtual void PrintTime() = 0;
	protected:
		Clock();
		Time _time;
};

class DigitalClock : public Clock {
	public:
		virtual Timer* GetTimer();
		DigitalClock(Timer* timer);
		virtual ~DigitalClock();
		virtual void Update(Timer* timer);
		void PrintTime();
	private:
		Timer* _timer;
};

class AnalogClock : public Clock {
	public:
		virtual Timer* GetTimer();
		AnalogClock(Timer* timer);
		virtual ~AnalogClock();
		void Update(Timer* timer);
		void PrintTime();
	private:
		Timer* _timer;
};

#endif //~_OBSERVER_H_
