//Singleton.h

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

class Singleton {
	public:
        static Singleton & instance();
        ~Singleton();

	private:
		Singleton();
		
		static unique_ptr<Singleton> _instance;
        static mutex _mutex;
};

#endif//~_SINGLETON_H_
