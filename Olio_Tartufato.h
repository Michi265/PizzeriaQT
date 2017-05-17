
#ifndef PIZZERIA_OLIO_TARTUFATO_H
#define PIZZERIA_OLIO_TARTUFATO_H


#include "string"
#include "Ingredient.h"

//using namespace std;

class Olio_Tartufato: public Ingredient {


 public:

         int getCost() override ;
         int getingredientid() override;

     };



#endif //PIZZERIA_OLIO_TARTUFATO_H
