#ifndef PIZZERIA_INGREDIENTSFACTORY_H
#define PIZZERIA_INGREDIENTSFACTORY_H

#include "Ingredient.h"
class IngredientsFactory {

    public:
        IngredientsFactory(int c) : choice(c)  { }
        Ingredient* CreateIngredients();

    private:
        int choice;
        Ingredient* ingredient;
    };



#endif //PIZZERIA_INGREDIENTSFACTORY_H
