
#ifndef PIZZERIA_FUNGHI_PORCINI_H
#define PIZZERIA_FUNGHI_PORCINI_H

#include "string"

#include "Ingredient.h"

using namespace std;


    class Funghi_Porcini: public Ingredient {

public:
        virtual int getCost();
        int getingredientid();

        Funghi_Porcini(){}


    };



#endif //PIZZERIA_FUNGHI_PORCINI_H
