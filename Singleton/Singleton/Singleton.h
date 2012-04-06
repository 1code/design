//Singleton.h

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>
#include <pthread.h>

using namespace std;

class Singleton
{
	public:
		static Singleton* instance();
		static void destroy();
	private:
		Singleton();
		~Singleton();
		
		static Singleton* _instance;
		static pthread_mutex_t _mutex;
};

#endif//~_SINGLETON_H_
