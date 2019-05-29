//  Copyright Cedric Lemaitre 2018

#ifndef SRC_COMMON_PASSENGER_READER_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "passenger.hpp"

///   Class PassengerReader wich allows to read and store data from CSV file
///   titanic.sv
class PassengerReader {
 public:
    explicit PassengerReader(const std::string &);
    //  private:
    std::string filename;
    std::vector<Passenger> get_data();
    void parse_line(std::string);
    int nb_col_csv;
    std::vector<Passenger> list_of_passengers;

    void sorting(const std::string &property);

};

#define SRC_COMMON_PASSENGER_READER_HPP_
#endif  //  SRC_COMMON_PASSENGER_READER_HPP_
