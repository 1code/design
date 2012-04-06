//main.cpp

#include "Adapter.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]) {
    TextView* tv = new TextView();
    TextShape* ts = new TextShape(tv);
    ts->BoundingBox();
    if (tv != NULL)
        delete tv;
    if (ts != NULL)
        delete ts;
    return 0;
}

