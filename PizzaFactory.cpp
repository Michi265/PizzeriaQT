#include "PizzaFactory.h"
#include "Margherita.h"
#include "Marinara.h"
#include "Napoli.h"

Pizza *PizzaFactory::CreatePizza() {
    switch (choice) {
        case 1:
           return pizza = new Margherita();

        case 2 :
           return pizza = new Marinara();

        case 3 :
           return pizza = new Napoli();

    }
    return 0;
}
