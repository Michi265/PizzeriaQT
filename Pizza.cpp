#include "Pizza.h"

int Pizza::cost() {
    int basecost=4;

    return basecost;
}

int Pizza::getpizzaid() {
    return pizzaname;
}

int Pizza::getBasecost() const
{
    return basecost;
}

void Pizza::setBasecost(int value)
{
    basecost = value;
}

