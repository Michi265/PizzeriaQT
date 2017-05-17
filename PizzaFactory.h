#ifndef PIZZERIA_PIZZAFACTORY_H
#define PIZZERIA_PIZZAFACTORY_H

#include "Pizza.h"


class PizzaFactory {

public:
    PizzaFactory(int c) : choice(c)  { }
    Pizza* CreatePizza();

private:
    int choice;
    Pizza* pizza;
};


#endif //PIZZERIA_PIZZAFACTORY_H
