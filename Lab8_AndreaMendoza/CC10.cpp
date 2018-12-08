//
// Created by andrea on 12/7/18.
//

#include "CC10.h"

CC10::CC10(const string &name, const string &planet, const string &leader, int age) : Civilizacion(name, planet, leader,
                                                                                                   age) {}

string CC10::Decode(string ogtext) {
    string newtext;
    for (int i = 0; i < ogtext.size(); ++i) {
        char whatever = ogtext.at(i);
        if (whatever != ' ') {
            int x = whatever;
            if (x >= 65 && x <= 90) {
                if (x < 82) {
                    x = x - 17 + 91 - 65;
                } else {
                    x -= 17;
                }
            } else {
                if (x < 114) {
                    x = x - 17 + 91 - 65;
                } else {
                    x -= 17;
                }
            }
            char whatevs = x;
            newtext += whatevs;
        } else {
            newtext += ' ';
        }
    }
    return newtext;
}

string CC10::Code(string ogtext) {
    string newtext;
    for (int i = 0; i < ogtext.size(); ++i) {
        char whatever = ogtext.at(i);
        if (whatever != ' ') {
            int x = whatever;
            if (x >= 65 && x <= 90) {
                if (x >= 74) {
                    x = x + 16 - 122 + 97;
                } else {
                    x += 17;
                }
            } else {
                if (x >= 106) {
                    x = x + 16 - 122 + 97;
                } else {
                    x += 17;
                }
            }
            char whatevs = x;
            newtext += whatevs;
        } else {
            newtext += ' ';
        }
    }
    return newtext;
}
