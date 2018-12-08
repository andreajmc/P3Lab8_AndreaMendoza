//
// Created by andrea on 12/7/18.
//

#ifndef LAB8_ANDREAMENDOZA_CC10_H
#define LAB8_ANDREAMENDOZA_CC10_H

#include "Civilizacion.h"

class CC10: public Civilizacion {
public:
    CC10(const string &name, const string &planet, const string &leader, int age);


    virtual string Decode(string string1);

    virtual string Code(string string1);

public:

};


#endif //LAB8_ANDREAMENDOZA_CC10_H
