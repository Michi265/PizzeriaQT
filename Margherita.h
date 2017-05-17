
#ifndef PIZZERIA_MARGHERITA_H
#define PIZZERIA_MARGHERITA_H

#include "string"
#include "Pizza.h"
using namespace std;

class Margherita : public Pizza {

int cost_tot;


public:

        int cost() override;
        int getpizzaid() override;

        Margherita(){}

        int getCost_tot() const;
        void setCost_tot(int value);
};


#endif //PIZZERIA_MARGHERITA_H
