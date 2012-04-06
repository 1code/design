//main.cpp

#include "Decorator.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    View* view = new TextView();
    Decorator* dec = new BorderDecorator(new ScrollDecorator(view));
    dec->Draw();
    delete dec;
    
    return 0;
}