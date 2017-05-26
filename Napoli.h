#ifndef PIZZERIA_NAPOLI_H
#define PIZZERIA_NAPOLI_H


#include "string"
#include "Pizza.h"
using namespace std;

class Napoli : public Pizza {
int cost_tot;
    public:

        int cost() override;
        int getpizzaid() override;

        Napoli(){}

        int getCost_tot() const;
        void setCost_tot(int value);


    };



#endif //PIZZERIA_NAPOLI_H
