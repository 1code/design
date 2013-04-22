#include "Pizza.h"

// "Abstract Builder"
class PizzaBuilder {
public:
    const Pizza & pizza();
    virtual ~PizzaBuilder();
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

protected:
    Pizza pizza_;
};

//----------------------------------------------------------------

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    ~HawaiianPizzaBuilder();
    void buildDough();
    void buildSauce();
    void buildTopping();
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    ~SpicyPizzaBuilder();
    void buildDough();
    void buildSauce();
    void buildTopping();
};
