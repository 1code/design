//
//  main.cpp
//  Set
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Set.h"

void intSetTest () {
	cout << "intSetSTLTest" << endl;
	unsigned int maxElem = 10;
	int maxVal = 100;
	SetSTL<int> ss(maxElem, maxVal);
	while (ss.size() < maxElem)
		ss.insert(rand() % maxVal);
	ss.print();
    
	SetArray<int> sa(maxElem, maxVal);
	while (sa.size() < maxElem)
		sa.insert(rand() % maxVal);
	sa.print();
	
	SetList<int> sl(maxElem, maxVal);
	while (sl.size() < maxElem)
		sl.insert(rand() % maxVal);
	sl.print();
    
	SetBST<int> st(maxElem, maxVal);
	while (st.size() < maxElem)
		st.insert(rand() % maxVal);
	st.print();
    
	SetBitVec<int> sv(maxElem, maxVal);
	while (sv.size() < maxElem)
		sv.insert(rand() % maxVal);
	sv.print();
    
	SetBin<int> sb(maxElem, maxVal);
	while (sb.size() < maxElem)
		sb.insert(rand() % maxVal);
	sb.print();
    
};

int main(int argc, const char * argv[])
{
    intSetTest();
    return 0;
}

