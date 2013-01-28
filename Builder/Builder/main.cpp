// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Cook cook;
    cook.pizzaBuilder(new HawaiianPizzaBuilder);
    cook.constructPizza();

    Pizza hawaiian = cook.getPizza();
    hawaiian.open();

    cook.pizzaBuilder(new SpicyPizzaBuilder);
    cook.constructPizza();

    Pizza spicy = cook.getPizza();
    spicy.open();
    return 0;
}

