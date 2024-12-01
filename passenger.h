// Ahmed Essam 20236012   
// sherif abdulmagid 20236051
#ifndef CPP_PASSENGER_H
#define CPP_PASSENGER_H
#pragma once
#include <string>
#include<iostream>
using namespace std;
class Passenger
{
private:
    string PassName;// the name of the passenger
    int PassID;// the id of the passenger
    static int numOfPass;// a static variable storing the total number of passengers in the system


public:
    Passenger(); // an empty constructor for passengers with data yet to be taken as inputs

    Passenger(string name, int id); // a constructor with 2 arguments to set the passenger name and id
    // both constructors incriment the number of passengers by 1
    
    string getName();// a getter for the passenger name
    
    void display_details(); //a function to display the details of of each passenger

    static int getCount(); // a function that returns the total number passengers

    friend istream& operator>>(istream& is, Passenger& ps); // an input operator to input the data of the passenger easily

    ~Passenger(); // a destructor that decriment the number of passengers when the passenger leaves the system and display a massage
};


#endif //CPP_PASSENGER_H