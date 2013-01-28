//
//  ArrayList.cpp
//  ArrayList
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifdef ArrayList_ArrayList_h

template <typename T>
ArrayList<T>::ArrayList(unsigned int arraySize):data(0),size(arraySize),count(new unsigned int) {
	if (0 < size)
		data = new T[size];
	*count = 1;
};

template <typename T>
ArrayList<T>::ArrayList() {
	--(*count);
	if(0 == *count) {
		if (NULL != data) {
			delete[] data;
			data = NULL;
		}
		delete count;
		count = NULL;
	}
};

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copy):data(copy.data),size(copy.size),count(copy.count) {
	++(*count);
};

template <typename T>
ArrayList<T>& ArrayList<T>::operator =(ArrayList<T>& copy) {
	// exception safe
	if (this != &copy) {
		T* orig = data;
		data = copy.data;
		size = copy.size;
		count = copy.count;
		++(*count);
		delete[] orig;
	}
	return *this;
};

template <typename T>
void ArrayList<T>::setValue(unsigned int index, const T& value) {
	if (index < size)
		data[index] = value;
};

template <typename T> 
T ArrayList<T>::getValue(unsigned int index) const {
	if (index < size)
		return data[index];
	else
		return T();
};

template <typename T>
void ArrayList<T>::print() const {
	for (unsigned int index = 0; index < size; index++) 
		cout << data[index] << " ";
	cout << endl;
	cout << "referece counting: " << *count << endl;
};

#endif
