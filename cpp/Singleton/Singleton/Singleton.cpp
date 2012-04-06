//Singleton.cpp

#include "Singleton.h"

pthread_mutex_t Singleton::_mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton* Singleton::_instance = NULL;

Singleton::Singleton() {
	cout << "Singleton Constructor" << endl;
};

Singleton::~Singleton() {
	cout << "Singleton Deconstructor" << endl;
};

Singleton* Singleton::instance(){
	if(NULL == _instance) {
		pthread_mutex_lock(&_mutex);
		cout << "Singleton locked" << endl;
		_instance = new Singleton();	
		pthread_mutex_unlock(&_mutex);
		cout << "Singleton unlocked" << endl;
	}
	return _instance; 
};

void Singleton::destroy(){
	if (_instance) {
		pthread_mutex_lock(&_mutex);
		cout << "Singleton locked" << endl;
		delete _instance;
		_instance = NULL;
		pthread_mutex_unlock(&_mutex);
		cout << "Singleton unlocked" << endl;
	}
};
