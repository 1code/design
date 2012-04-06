//Aggregate.h

#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_
#include "Iterator.h"

using namespace std;

class Iterator;

typedef int Object;

class Container {
	public:
		virtual ~Container();
		virtual Iterator* CreateIterator() = 0;
		virtual Object GetItem(int idx) = 0;
	protected:
		Container();	
};

class Vector : public Container {
	public:
		enum { SIZE = 3 };
		Vector();
		~Vector();
		Iterator* CreateIterator();
		Object GetItem(int idx);
		int GetSize();
	private:
		Object _objs[SIZE];
};

#endif //~_AGGREGATE_H_
