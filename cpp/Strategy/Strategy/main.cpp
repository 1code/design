//main.cpp

#include "Context.h"
#include "Strategy.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]) {
    Composition* quick = new Composition(new SimpleCompositor);
    Composition* slick = new Composition(new TexCompositor);
    Composition* iconic = new Composition(new ArrayCompositor);
    
    quick->Repair();
    slick->Repair();
    iconic->Repair();
    if (NULL != quick)
        delete quick;
    if (NULL != slick)
        delete slick;
    if (NULL != iconic)
        delete iconic;
    return 0;
}
