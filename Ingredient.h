#ifndef PIZZERIA_PIZZA_H
#define PIZZERIA_PIZZA_H

#include <vector>
#include "string"
using namespace std;

class Ingredient {
public:

    virtual int getCost();
    virtual int getingredientid();

    Ingredient(){}

    virtual ~Ingredient() { }
    int ingredientid;

private:

    int basecost;
    string name;

};


#endif //PIZZERIA_PIZZA_H
