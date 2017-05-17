#include "IngredientsFactory.h"
#include "Olio_Tartufato.h"
#include "Bufala.h"
#include "Funghi_Porcini.h"
#include "Ingredient.h"

Ingredient *IngredientsFactory::CreateIngredients() {
    switch (choice) {
        case 1:
           return ingredient = new Olio_Tartufato();

        case 2 :
           return ingredient = new Bufala();

        case 3 :
           return ingredient = new Funghi_Porcini();
    }
    return 0;
}
