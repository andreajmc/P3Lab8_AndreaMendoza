//
// Created by andrea on 12/7/18.
//

#include "Civilizacion.h"

Civilizacion::Civilizacion(const string &name, const string &planet, const string &leader, int age) : name(name),
                                                                                                      planet(planet),
                                                                                                      leader(leader),
                                                                                                      age(age) {}

const string &Civilizacion::getName() const {
    return name;
}

void Civilizacion::setName(const string &name) {
    Civilizacion::name = name;
}

const string &Civilizacion::getPlanet() const {
    return planet;
}

void Civilizacion::setPlanet(const string &planet) {
    Civilizacion::planet = planet;
}

const string &Civilizacion::getLeader() const {
    return leader;
}

void Civilizacion::setLeader(const string &leader) {
    Civilizacion::leader = leader;
}

int Civilizacion::getAge() const {
    return age;
}

void Civilizacion::setAge(int age) {
    Civilizacion::age = age;
}
