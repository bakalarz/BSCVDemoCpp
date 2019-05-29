// Copyright 2018 Cdric Lemaitre
#ifndef SRC_COMMON_PROCESS_PASSENGER_HPP_
#define SRC_COMMON_PROCESS_PASSENGER_HPP_

#include <vector>
#include <map>
#include <string>
#include "passenger_reader.hpp"
#include "passenger.hpp"

struct StatSurvived{
    int nb_survived;
    double percentage_survived;
};

class ProcessPassenger{
 public:
     explicit ProcessPassenger(const std::vector<Passenger> &);
     double p_mean_age();
     StatSurvived p_survived();
     std::map<std::string, int> p_hist_emabarked();
 private:
     std::vector<Passenger> data;
     std::map<std::string, int> hist_embarked;
     double mean_age;
     StatSurvived info_survived;
};



#endif  // SRC_COMMON_PROCESS_PASSENGER_HPP_
