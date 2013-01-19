//
//  main.cpp
//  ArrayList
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ArrayList.h"

int main(int argc, const char * argv[])
{
    ArrayList<int> a(10);
	a.print();
	ArrayList<int> b(2);
	b = a;
	b.print();
	ArrayList<int> c(2);
	c = c;
	c = b;
	c.print();
    return 0;
}

