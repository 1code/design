//Invoker.h

#ifndef _INVOKER_H_
#define _INVOKER_H_

class Command;

class Application {
	public:
		Application();
		~Application();
		void Add(Command* cmd);
		void Excute();
	private:
		Command* _cmd;
};

#endif //~_INVOKER_H_
