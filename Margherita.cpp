#include "Margherita.h"
#include <iostream>
#include "stdio.h"
#include <string>

int Margherita::getCost_tot() const
{
    return cost_tot;
}

void Margherita::setCost_tot(int value)
{
    cost_tot = value;
}

int Margherita::cost() {

    int basecost=4;

    return basecost;
}

int Margherita::getpizzaid() {

    return pizzaname;
}
