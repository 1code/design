//AbstractFactory.cpp

#include "AbstractFactory.h"
#include "Product.h"
#include <iostream>

using namespace std;

Furniture::Furniture() {

};

Furniture::~Furniture() {

};

IronFurniture::IronFurniture() {

};

IronFurniture::~IronFurniture() {

};

Table* IronFurniture::CreateTable() {
	return new IronTable();
};

Chair* IronFurniture::CreateChair() {
	return new IronChair();
};

WoodenFurniture::WoodenFurniture() {

};

WoodenFurniture::~WoodenFurniture() {

};

Table* WoodenFurniture::CreateTable() {
	return new WoodenTable();
};

Chair* WoodenFurniture::CreateChair() {
	return new WoodenChair();
};


