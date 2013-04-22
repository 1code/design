//Adapter.h

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

using namespace std;

class Shape {
	public:
		Shape();
		virtual ~Shape();
		virtual void BoundingBox();
};

class TextView {
	public:
		TextView();
		virtual ~TextView();
		virtual void Extend();
};

class TextShape: public Shape {
	public:
		TextShape(TextView* tv);
		~TextShape();
		virtual void BoundingBox();
	private:
		TextView* _tv;
};

#endif //~_ADAPTER_H_
