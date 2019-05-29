// Copyright 2018 Cdric Lemaitre

#include <gtest/gtest.h>

#include <string>
#include <common/passenger_reader.hpp>
#include <common/process_passenger.hpp>

// Create our own test to check the different function of our class
// This function will take two arguments:
// * The test case name
// * The test name
TEST(TestProcessPassenger, Testp_mean_age) {
    std::string f_name = "../data/titanic.csv";
    PassengerReader my_passenger_reader(f_name);
    ProcessPassenger my_process_passenger(my_passenger_reader.list_of_passengers);
    double val_mean_from_xls = 29.6991176470588;
    ASSERT_NEAR(my_process_passenger.p_mean_age(), val_mean_from_xls, 0.2);
    //  ASSERT_FLOAT_EQ(my_process_passenger.p_mean_age(), val_mean_from_xls);
}
TEST(TestProcessPassenger, Testp_survived) {
    std::string f_name = "../data/titanic.csv";
    PassengerReader my_passenger_reader(f_name);
    ProcessPassenger my_process_passenger(my_passenger_reader.list_of_passengers);
    int nb_survived_xls = 342;
    double per_sur = static_cast<double>(nb_survived_xls) /
        static_cast<double>(891);
    StatSurvived survived = my_process_passenger.p_survived();
    ASSERT_EQ(survived.nb_survived, nb_survived_xls);
    ASSERT_NEAR(survived.percentage_survived, per_sur, 0.001);
    // ASSERT_FLOAT_EQ(survived.percentage_survived, per_sur);
}
TEST(TestProcessPassenger, Testp_hist_embarked) {
    std::string f_name = "../data/titanic.csv";
    PassengerReader my_passenger_reader(f_name);
    ProcessPassenger my_process_passenger(my_passenger_reader.list_of_passengers);
    int nb_class_hist = 4;
    std::map<std::string, int> hist = my_process_passenger.p_hist_emabarked();
    int nb_hist = hist.size();
    ASSERT_EQ(nb_hist, nb_class_hist);
    int Southampton = 644;
    int Cherbourg = 168;
    int Queenstown = 77;
    ASSERT_EQ(hist["Southampton"], Southampton);
    ASSERT_EQ(hist["Cherbourg"], Cherbourg);
    ASSERT_EQ(hist["Queenstown"], Queenstown);
    ASSERT_EQ(hist[""], 3);
}
