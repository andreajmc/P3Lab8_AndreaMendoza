//
// Created by andrea on 12/7/18.
//

#ifndef LAB8_ANDREAMENDOZA_BB01_H
#define LAB8_ANDREAMENDOZA_BB01_H


#include "Civilizacion.h"

class BB01 : public Civilizacion {
public:
    BB01(const string &name, const string &planet, const string &leader, int age);

    virtual string Decode(string string1);

    virtual string Code(string string1);

};


#endif //LAB8_ANDREAMENDOZA_BB01_H
