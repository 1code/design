#include "stdafx.h"

Cook::Cook() : pizzaBuilder_(nullptr)
{
}

Cook::~Cook() {
    if (pizzaBuilder_)
    {
        delete pizzaBuilder_;
    }
}

void Cook::pizzaBuilder(PizzaBuilder* pizzaBuilder) {
    if (pizzaBuilder_)
        delete pizzaBuilder_;

    pizzaBuilder_ = pizzaBuilder;
}

const Pizza& Cook::getPizza() {
    return pizzaBuilder_->pizza();
}

void Cook::constructPizza() {
    pizzaBuilder_->buildDough();
    pizzaBuilder_->buildSauce();
    pizzaBuilder_->buildTopping();
}
