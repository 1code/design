#pragma once

#include <string>
#include <iostream>
using namespace std;

class Pizza
{
public:
	void dough(const string& dough);
	void sauce(const string& sauce);
	void topping(const string& topping);
	void open() const;

private:
	string dough_;
	string sauce_;
	string topping_;
};