//
//  ArrayList.h
//  ArrayList
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ArrayList_ArrayList_h
#define ArrayList_ArrayList_h

#include <iostream>

using namespace std;

template <typename T> 
class ArrayList {
public:
    ArrayList(unsigned int arraySize);
    ArrayList();
    ArrayList(const ArrayList<T>& copy);
    ArrayList<T>& operator =(ArrayList<T>& copy);
    void setValue(unsigned int index, const T& value);
    T getValue(unsigned int index) const;
    void print() const;
private:
    void swap();
    T* data;
    unsigned int size;
    unsigned int *count; // reference counting
};

#include "ArrayList.cpp"

#endif
