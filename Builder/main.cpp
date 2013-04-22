#include "Cook.h"

int main()
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

