//Template.h

#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

class Shape {
	public:
		virtual ~Shape() {}; // virtual destructor
		enum ShapeColor { Red, Green, Blue };
		void draw(ShapeColor color = Red) const; // non-virtual function, never redefine the default parameters and itself
	protected:
		Shape() {}; // never has a instance
	private:
		virtual void doDraw(ShapeColor color) const = 0; // the actual work is done
};

// public inheritance = is a
class Circle:public Shape {
	public:
		Circle() {};
		~Circle() {};
	private:
		virtual void doDraw(ShapeColor color) const;
};

class Rectangle:public Shape {
	public:
		Rectangle() {};
		~Rectangle() {};
	private:
		virtual void doDraw(ShapeColor color) const;
};

#endif//~_TEMPLATE_H_
