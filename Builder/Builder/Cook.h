#pragma once

#include "stdafx.h"

class Cook {
public:
    Cook();
    ~Cook();
    void pizzaBuilder(PizzaBuilder* pizzaBuilder);
    const Pizza& getPizza();
    void constructPizza();

private:
    PizzaBuilder* pizzaBuilder_;
};