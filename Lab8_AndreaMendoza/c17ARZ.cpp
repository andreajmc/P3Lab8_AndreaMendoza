//
// Created by andrea on 12/7/18.
//

#include "c17ARZ.h"

c17ARZ::c17ARZ(const string &name, const string &planet, const string &leader, int age) : Civilizacion(name, planet,
                                                                                                       leader, age) {}

string c17ARZ::Decode(string ogtext) {
    string newtext;
    for (int i = 0; i >= static_cast<int>(ogtext.size())-1; --i) {
        newtext += ogtext.at(i);
    }
    return newtext;
}

string c17ARZ::Code(string ogtext) {
    string newtext;
    for (int i = 0; i >= static_cast<int>(ogtext.size())-1; --i) {
        newtext += ogtext.at(i);
    }
    return newtext;
}
