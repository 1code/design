//Singleton.cpp

#include "Singleton.h"

unique_ptr<Singleton> Singleton::_instance = nullptr;
mutex Singleton::_mutex;

Singleton::Singleton() {
	cout << "Singleton Constructor" << endl;
}

Singleton::~Singleton() {
	cout << "Singleton Deconstructor" << endl;
}

Singleton & Singleton::instance(){
	if(nullptr == _instance) {
        lock_guard<mutex> guard(_mutex);
        cout << "Singleton locked" << endl;
        if (nullptr == _instance) {
            _instance = unique_ptr<Singleton>(new Singleton());
        }

        cout << "Singleton unlocked" << endl;
	}
	return *_instance; 
}
