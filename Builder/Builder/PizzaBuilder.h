#pragma once
#include "stdafx.h"

// "Abstract Builder"
class PizzaBuilder {
public:
    const Pizza & pizza();
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

protected:
    Pizza pizza_;
};

//----------------------------------------------------------------

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough();
    void buildSauce();
    void buildTopping();
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough();
    void buildSauce();
    void buildTopping();
};