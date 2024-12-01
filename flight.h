// Ahmed Essam 20236012   
// sherif abdulmagid 20236051
#ifndef CPP_FLIGHT_H
#define CPP_FLIGHT_H
#pragma once
#include <iostream>
#include "passenger.h"
using namespace std;
class Flight
{
private:
    int flight_ID;//the flight number
    string flightDist;// the flight destination
    string depTime = "04:00";// the departure time
    string timeZone = "GMT";// the flight time zone
    int capacity;// the capacity of the flight
    int booked_seats = 0;// the number of booked seats
    bool** seating_plan;// the 2d array 3 columns
    string* passName;// the array of passengers name
    int row;// the number of rows per each column


public:
    Flight(int c, string dis, int id);// the constructor of a flight recieving the capacity, the destination and the flight number
    
    Flight( Flight& f);// a copy constructor
    
    void displayList(); // the function to display the list of passengers in this plane
   
    void displayInfo();// a function to display the flight information    
    
    void display_plan(); // the function to display the seating plan as a 2d array

    int searchPass(string name); // the function to search for the passenger in the flight by his name
    // returns his number in the flight if found and -1 if not found

    string searchSeat(string seat);//th function to search for a seat to find either it is bookedd or not

    void addPass(int num, Passenger p[]);//a function to enter a passenger in the first empty place

    void removePass(Passenger passenger);// a function to remove a specific passenger

    Flight& operator ++ ();// an operation to add a row at the end of the plane

    Flight& operator += (Passenger& passenger);// an operator to easily add a passsenger in the first empty place

    Flight& operator -= (int number);// an operator to remove a number of passengers

    Flight& operator --(int);// an operattor to remove the last passenger entered
    
   friend ostream& operator<<(ostream& output, Flight& obj);// an out put operator that display all the info, the passengers list and the seating plan

    ~Flight(); // a destractor freeing allocated pointers from the memorey
};


#endif //CPP_FLIGHT_H