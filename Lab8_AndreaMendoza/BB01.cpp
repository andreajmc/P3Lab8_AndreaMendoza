//
// Created by andrea on 12/7/18.
//

#include "BB01.h"

BB01::BB01(const string &name, const string &planet, const string &leader, int age) : Civilizacion(name, planet, leader,
                                                                                                   age) {}

string BB01::Decode(string ogstring) {
    string newtext;
    int bin = 0;

    for (int i = 0; i < ogstring.size(); ++i) {
        char caracter = ogstring.at(i);
        int num = caracter;
        int a[7];
        int j = 0;
        while (num > 0) {
            bin = num % 2;
            newtext += std::to_string(bin);
            num /= 2;
        }
        newtext += '-';
    }
    return newtext;
}

string BB01::Code(string ogstring) {
    ogstring += '-';
    string newtext;
    string temp;
    for (int i = 0; i < ogstring.size(); ++i) {
        if (ogstring.at(i) != '-') {
            temp += ogstring.at(i);
        } else if (ogstring.at(i) == '-') {
            int x = atoi(temp.c_str());
            int decNum = 0;
            int i = 1;
            int rem = 0;
            while (x != 0) {
                rem = x % 10;
                decNum = decNum + rem * i;
                i *= 2;
                x /= 10;
            }
            char blah = static_cast<char>(decNum);
            newtext += blah;
            temp.clear();
        }
    }
    return newtext;
}
