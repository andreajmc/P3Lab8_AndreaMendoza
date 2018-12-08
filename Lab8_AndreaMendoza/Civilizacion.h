//
// Created by andrea on 12/7/18.
//

#ifndef LAB8_ANDREAMENDOZA_CIVILIZACION_H
#define LAB8_ANDREAMENDOZA_CIVILIZACION_H

#include <string>
using std::string;

class Civilizacion {
private:
   string name;
   string planet;
   string leader;
   int age;

public:
    Civilizacion(const string &name, const string &planet, const string &leader, int age);

    virtual string Decode(string) = 0;
    virtual string Code(string) = 0;


    const string &getName() const;

    void setName(const string &name);

    const string &getPlanet() const;

    void setPlanet(const string &planet);

    const string &getLeader() const;

    void setLeader(const string &leader);

    int getAge() const;

    void setAge(int age);

};


#endif //LAB8_ANDREAMENDOZA_CIVILIZACION_H
