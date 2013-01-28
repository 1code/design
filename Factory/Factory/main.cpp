//main.cpp

#include "AbstractFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
    Furniture* f1 = new IronFurniture();
    
    f1->CreateTable();
    f1->CreateChair();
    
    Furniture* f2 = new WoodenFurniture();
    
    f2->CreateTable();
    f2->CreateChair();
    delete f1;
    delete f2;
}
