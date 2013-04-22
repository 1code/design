#include "Template.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    Shape* circle = new Circle;
    Shape* rectangle = new Rectangle;
    circle->draw();
    rectangle->draw();
    return 0;
}
