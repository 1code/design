#include "PizzaBuilder.h"

PizzaBuilder::~PizzaBuilder() {

}

const Pizza & PizzaBuilder::pizza() {
    return pizza_;
}

HawaiianPizzaBuilder::~HawaiianPizzaBuilder() {
}

void HawaiianPizzaBuilder::buildDough() {
    pizza_.dough("cross");
}

void HawaiianPizzaBuilder::buildSauce() {
    pizza_.sauce("mild");
}

void HawaiianPizzaBuilder::buildTopping() {
    pizza_.topping("ham+pineapple");
}

SpicyPizzaBuilder::~SpicyPizzaBuilder() {
}

void SpicyPizzaBuilder::buildDough() {
    pizza_.dough("pan baked");
}

void SpicyPizzaBuilder::buildSauce() {
    pizza_.sauce("hot");
}

void SpicyPizzaBuilder::buildTopping() {
    pizza_.topping("pepperoni+salami");
}
