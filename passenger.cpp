// Ahmed Essam 20236012   
// sherif abdulmagid 20236051
#include "passenger.h"
#include "flight.h"
#include<iostream>
using namespace std;

int Passenger::numOfPass = 0;



Passenger::Passenger() {
    numOfPass++;
}

Passenger::Passenger(string name, int id) {
    PassName = name;
    PassID = id;
    numOfPass++;
}

void Passenger::display_details()
{
    cout << "Passenger name: " << PassName << "\nPassenger ID: " << PassID << endl;
}

int Passenger::getCount()
{
    return numOfPass;
}

string Passenger::getName() {
    return PassName;
}

istream& operator>>(istream& is, Passenger& ps)
{
    cout << "\nplease enter the passenger name : ";
    is >> ps.PassName;
    cout << "\nplease enter the passenger id : ";
    is >> ps.PassID;
    cout << endl;
    return is;
}

Passenger::~Passenger()
{
    numOfPass--;
    cout << "\nthe passenger left the flight\n";
}