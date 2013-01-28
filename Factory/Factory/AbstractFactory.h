//AbstractFactory.h

#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

class Table;

class Chair;

class Furniture {
	public:
		virtual ~Furniture();
		virtual Table* CreateTable() = 0;
		virtual Chair* CreateChair() = 0;
	protected:
		Furniture();
};

class IronFurniture : public Furniture {
	public:
		IronFurniture();
		~IronFurniture();
		Table* CreateTable();
		Chair* CreateChair();
};

class WoodenFurniture : public Furniture {
	public:
		WoodenFurniture();
		~WoodenFurniture();
		Table* CreateTable();
		Chair* CreateChair();
};

#endif
