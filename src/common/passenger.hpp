// Copyright 2018 Cedric Lemaitre

#ifndef SRC_COMMON_PASSENGER_HPP_
#define SRC_COMMON_PASSENGER_HPP_

#include <string>

/// class Passengerwhich data for a passenger
// only a constructor and data (private)
class Passenger {
 public:
     /// Constructor with in parameter all data which should affected to the
     // menber variables
     Passenger(bool,
             int,
             bool,
             int,
             int,
             int,
             int,
             std::string,
             std::string,
             std::string,
             bool,
             std::string,
             std::string,
             bool,
             bool);
    friend std::ostream &operator<<(std::ostream &out, const Passenger &p);
// private:
    bool survived;  ///< survived or not
    int pclass;  ///< range class
    bool sex;  ///< male true, female 0
    int age;
    int slbsp;  ///< see owner for wahit for
    int parch;  ///< see owner for wahit for
    int fare;
    std::string embarked;
    std::string type_class;
    std::string who;
    bool adult_male;
    std::string deck;
    std::string embark_town;
    bool alive;
    bool alone;
    //sorting
    bool operator< (const Passenger &p) const {
        return age < p.age;
    }
};
#endif  //  SRC_COMMON_PASSENGER_HPP_

