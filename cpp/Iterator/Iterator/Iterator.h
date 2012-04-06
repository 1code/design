//Iterator.h

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

using namespace std;

class Container;

class Vector;

typedef int Object;

class Iterator {
	public:
		virtual ~Iterator();
		virtual void First() = 0;
		virtual void Next() = 0;
		virtual bool IsDone() = 0;
		virtual Object CurrentItem() = 0;
	protected:
		Iterator();
};

class VectorIterator : public Iterator {
	public:
		VectorIterator(Vector* v);
		~VectorIterator();
		void First();
		void Next();
		bool IsDone();
		Object CurrentItem();
	private:
		Vector* _v;
		int _idx;
};

#endif //~_ITERATOR_H_
