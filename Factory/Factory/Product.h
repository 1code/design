//Product.h

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Table {
	public:
		virtual ~Table();
	protected:
		Table();
};

class Chair {
	public:
		virtual ~Chair();
	protected:
		Chair();
};

class IronTable: public Table {
	public:
		IronTable();
		~IronTable();
};

class WoodenTable: public Table {
	public:
		WoodenTable();
		~WoodenTable();
};

class IronChair: public Chair {
	public:
		IronChair();
		~IronChair();
};

class WoodenChair: public Chair {
	public:
		WoodenChair();
		~WoodenChair();
};

#endif//~_PRODUCT_H_ECT_H
