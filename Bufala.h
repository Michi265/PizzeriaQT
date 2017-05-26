
#ifndef PIZZERIA_BUFALA_H
#define PIZZERIA_BUFALA_H

#include "Ingredient.h"


using namespace std;

class Bufala : public Ingredient {

public:

    int getCost() override ;
    int getingredientid() override;

};



#endif //PIZZERIA_BUFALA_H
