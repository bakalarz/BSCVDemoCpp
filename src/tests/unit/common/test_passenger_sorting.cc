#include <gtest/gtest.h>

#include <string>
#include <common/passenger_reader.hpp>

// This function will take two arguments:
// * The test case name
// * The test name
TEST(TestPassengerReader, sorting) {
    //  first line in csv file
    //  0,3,male,22.0,1,0,7.25,S,Third,man,True,,Southampton,no,False
    std::string f_name = "../data/titanic.csv";
    PassengerReader my_passenger_reader(f_name);
    my_passenger_reader.sorting("age");
    ASSERT_EQ(my_passenger_reader.list_of_passengers.front().age, -1);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.at(10).age, -1);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.at(17).age, -1);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.back().age, 80);
    my_passenger_reader.sorting("fare");
    ASSERT_EQ(my_passenger_reader.list_of_passengers.front().fare, 0);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.at(10).fare, 0);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.at(17).fare, 6);
    ASSERT_EQ(my_passenger_reader.list_of_passengers.back().fare, 512);
    

}