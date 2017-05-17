#ifndef PIZZERIA_NAPOLI_H
#define PIZZERIA_NAPOLI_H


#include "string"
#include "Pizza.h"
using namespace std;

class Napoli : public Pizza {

    public:

        int cost() override;
        int getpizzaid() override;

        Napoli(){}


    };



#endif //PIZZERIA_NAPOLI_H
