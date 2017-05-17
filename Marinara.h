
#ifndef PIZZERIA_MARINARA_H
#define PIZZERIA_MARINARA_H


#include "string"
#include "Pizza.h"
using namespace std;

class Marinara : public Pizza {

    public:

        int cost() override;
        int getpizzaid() override;


       Marinara(){}


    };



#endif //PIZZERIA_MARINARA_H
