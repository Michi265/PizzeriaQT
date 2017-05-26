
#ifndef PIZZERIA_MARINARA_H
#define PIZZERIA_MARINARA_H


#include <string>
#include "Pizza.h"
using namespace std;

class Marinara : public Pizza {
int cost_tot;
    public:

        int cost() override;
        int getpizzaid() override;


       Marinara(){}

       int getCost_tot() const;
       void setCost_tot(int value);


    };



#endif //PIZZERIA_MARINARA_H
