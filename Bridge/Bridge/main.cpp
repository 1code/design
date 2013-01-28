//main.cpp

#include "Abstraction.h"
#include "AbstractionImp.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Window* win = new IconWindow(new XWindowImp());
    win->DrawContents();
    delete win;
    win = new TransientWindow(new PMWindowImp());
    win->DrawContents();
    delete win;
    return 0;
}

