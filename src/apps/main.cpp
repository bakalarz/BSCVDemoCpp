// Copyright 2016 Guillaume Lemaitre, Cedric Lemaitre

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../common/passenger_reader.hpp"
#include "../common/passenger.hpp"


int main() {

    std::string f_name = "../data/titanic.csv";
    PassengerReader my_passenger_reader(f_name); //reads a file

    //prints the objects that were stored in the vector list_of_passengers
    for(std::vector<int>::size_type i = 0, size = my_passenger_reader.list_of_passengers.size() ; i < size; i++)
    {   
        Passenger p(my_passenger_reader.list_of_passengers.at(i));
        std::cout << p << std::endl;
    }

    //my_passenger_reader.sorting();
    my_passenger_reader.sorting("age");

    std::cout << "-----------------------" << std::endl;

    //display the sorted data
    // for(std::vector<int>::size_type i = 0, size = my_passenger_reader.list_of_passengers.size() ; i < size; i++)
    // {   
    //     Passenger p(my_passenger_reader.list_of_passengers.at(i));
    //     std::cout << p << std::endl;
    // }

    Passenger first(my_passenger_reader.list_of_passengers.at(0));
    std::cout << first << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger tenth(my_passenger_reader.list_of_passengers.at(10));
    std::cout << tenth << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger seventeenth(my_passenger_reader.list_of_passengers.at(17));
    std::cout << seventeenth << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger back(my_passenger_reader.list_of_passengers.back());
    std::cout <<back << std::endl;
    std::cout << "-----------------------" << std::endl;

    my_passenger_reader.sorting("fare");
    Passenger fare1(my_passenger_reader.list_of_passengers.at(0));
    std::cout << fare1 << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger fare2(my_passenger_reader.list_of_passengers.at(10));
    std::cout << fare2 << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger fare3(my_passenger_reader.list_of_passengers.at(17));
    std::cout << fare3 << std::endl;
    std::cout << "-----------------------" << std::endl;
    Passenger fare4(my_passenger_reader.list_of_passengers.back());
    std::cout << fare4 << std::endl;
    std::cout << "-----------------------" << std::endl;
    return 0;
}
