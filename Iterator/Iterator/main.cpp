//main.cpp

#include "Aggregate.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]) {
    Vector v;
    Iterator* vi = v.CreateIterator();
    vi->First();
    vi->Next();
    cout << vi->IsDone() << endl;
    cout << vi->CurrentItem() << endl;
    delete vi;
    return 0;
}

