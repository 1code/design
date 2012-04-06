//Subject.h

#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <list>

using namespace std;

typedef unsigned int Time;

class Clock;

class Timer {
	public:
		virtual ~Timer();
		virtual void Attach(Clock* clc);
		virtual void Detach(Clock* clc);
		virtual void Notify();
		virtual Time GetTime() = 0;
		virtual void SetTime(const Time& t) = 0;
	protected:
		Timer();
	private:
		list<Clock* >* _clocks;
};

class ClockTimer : public Timer {
	public:
	 	ClockTimer();
		~ClockTimer();
		Time GetTime();
		void SetTime(const Time& t);
	private:
		Time _time;
};

class AtomTimer : public Timer {
	public:
	 	AtomTimer();
		~AtomTimer();
		Time GetTime();
		void SetTime(const Time& t);
	private:
		Time _time;
};

#endif //~_SUBJECT_H_
