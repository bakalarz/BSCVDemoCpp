//  Copyright Cedric Lemaitre 2018

#include "passenger_reader.hpp"
#include <iostream>
#include <algorithm>

PassengerReader::PassengerReader(const std::string &file_name)
{
    nb_col_csv = 15;
    filename = file_name;
    std::ifstream if_file(file_name);
    if (if_file.is_open()) {
        std::string val_line;
        while (if_file.good()) {
            getline(if_file, val_line);
            parse_line(val_line);
        }  //  while if_file.good()
    } else {
        std::cout << "Can't open file";
    }  // if open file
}  // end PassengerReader

void PassengerReader::parse_line(std::string line)
{
    bool survived;
    int pclass;
    bool sex;
    int age;
    int slbsp;
    int parch;
    int fare;
    std::string embarked;
    std::string type_class;
    std::string who;
    bool adult_male;
    std::string deck;
    std::string embark_town;
    bool alive;
    bool alone;
    std::stringstream line_stream(line);
    std::string cell;
    int count = 0;
    while (std::getline(line_stream, cell, ',')) {
        switch (count) {
            case 0:
                if (cell == "1")
                    survived = true;
                else
                   survived = false;
                count++;
                break;
            case 1:
                pclass = atoi(cell.c_str());
                count++;
                break;
            case 2:
                if (cell == "male")
                    sex = true;
                else
                    sex = false;
                count++;
                break;
            case 3:
                if (cell == "")
                    age = -1;
                else
                    age = atoi(cell.c_str());
                count++;
                break;
            case 4:
                slbsp = atoi(cell.c_str());
                count++;
                break;
            case 5:
                parch = atoi(cell.c_str());
                count++;
                break;
            case 6:
                fare = atoi(cell.c_str());
                count++;
                break;
            case 7:
                embarked = cell;
                count++;
                break;
            case 8:
                type_class = cell;
                count++;
                break;
            case 9:
                who = cell;
                count++;
                break;
            case 10:
                if (cell == "True")
                    adult_male = true;
                else
                    adult_male = false;
                count++;
                break;
            case 11:
                deck = cell;
                count++;
                break;
            case 12:
                embark_town = cell;
                count++;
                break;
            case 13:
                if (cell == "yes")
                    alive = true;
                else
                    alive = false;
                count++;
                break;
            case 14:
                if (cell == "True" || cell == "true")
                    alone = true;
                else
                    alone = false;
                count++;
                break;
            default:
                std::cout << "Warning : value of count in [0, 14]\n";
        }  //  switch case
    }  //  while end line
    Passenger temp_passenger(survived, pclass, sex, age, slbsp, parch, fare,
            embarked, type_class, who, adult_male, deck, embark_town, alive,
            alone);
    list_of_passengers.push_back(temp_passenger);
}

void PassengerReader::sorting(const std::string &property)
{
    auto sortRuleLambda = [property] (const Passenger& p1, const Passenger& p2) -> bool
    {
        if(property == "age")
            return p1.age < p2.age;
        else
            return p1.fare < p2.fare;
    };

std::sort(list_of_passengers.begin(), list_of_passengers.end(), sortRuleLambda);
}

  
