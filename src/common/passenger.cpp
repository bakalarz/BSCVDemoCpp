// Copyright 2018 Cedric Lemaitre


#include "passenger.hpp"
#include <iostream>



Passenger::Passenger(bool survived,
    int pclass,
    bool sex,
    int age,
    int slbsp,
    int parch,
    int fare,
    std::string embarked,
    std::string type_class,
    std::string who,
    bool adult_male,
    std::string deck,
    std::string embark_town,
    bool alive,
    bool alone) {
    this->survived = survived;
    this->pclass = pclass;
    this->sex = sex;
    this->age = age;
    this->slbsp = slbsp;
    this->parch = parch;
    this->fare = fare;
    this->embarked = embarked;
    this->type_class = type_class;
    this->who = who;
    this->adult_male = adult_male;
    this->deck = deck;
    this->embark_town = embark_town;
    this->alive = alive;
    this->alone = alone;
}

//friend of a class PassengerReader, overloads the " << " operator
std::ostream& operator<< (std::ostream &out, const Passenger &p)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "survived: " << p.survived << std::endl << "pclass: " << p.pclass << std::endl << "sex: " << p.sex << std::endl << "age: " << p.age << std::endl << "slbsp: " << p.slbsp << std::endl <<"parch: " << p.parch << std::endl << "fare: " << p.fare << std::endl << "embarked " << p.embarked << std::endl << "type class: " << p.type_class << std::endl << "who: " << p.who << std::endl << "adult male: " << p.adult_male << std::endl << "deck: " << p.embark_town << std::endl << "alive: " << p.alive << std::endl << "alone: " << p.alone << std::endl;
 
    return out;
}
