
#ifndef PIZZERIA_FUNGHI_PORCINI_H
#define PIZZERIA_FUNGHI_PORCINI_H


#include "Ingredient.h"

using namespace std;


class Funghi_Porcini: public Ingredient {

public:
        int getCost() override;
        int getingredientid() override;

    };



#endif //PIZZERIA_FUNGHI_PORCINI_H
