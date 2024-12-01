// Ahmed Essam 20236012   
// sherif abdulmagid 20236051

#include "passenger.h"
#include "flight.h"
#include<iostream>
using namespace std;

Flight::Flight(int c, string dis, int id)
{
    capacity = c;
    flightDist = dis;
    flight_ID = id;
    row = c / 4;
    seating_plan = new  bool* [row];
    passName = new string[capacity];
    for (int i = 0; i < row; i++) {
        seating_plan[i] = new bool[4];
        for (int j = 0; j < 4; j++) {
            seating_plan[i][j] = 0;//initialization of the seats plan
        }
    }
    for (int i = 0; i < c; i++) passName[i] = "";
}

Flight::Flight( Flight& f) {
    capacity = f.capacity;
    flightDist = f.flightDist;
    flight_ID = f.flight_ID;
    row = f.row;
    booked_seats = f.booked_seats; 
    // Allocate and copy the seating_plan array
    seating_plan = new bool*[row];
    for (int i = 0; i < row; i++) {
        seating_plan[i] = new bool[4];
        for (int j = 0; j < 4; j++) {
            seating_plan[i][j] = f.seating_plan[i][j];
        }
    }
    // Allocate and copy the passName array
    passName = new string[capacity];
    for (int i = 0; i < capacity; i++) {
        passName[i] = f.passName[i];
    }
}

void Flight::displayInfo() {
    cout << "flight id : " << flight_ID << '\n';
    cout << "departure time : " << depTime << '\n';
    cout << "flight destination : " << flightDist << endl;
    cout << "time zone is : " << timeZone << endl;
    cout << "the capacity : " << capacity << endl;
    cout << "booked seats : " << booked_seats << endl;
    cout << "the list of passengers : \n";
    for (int i = 0; i < booked_seats; i++) {
        cout << i + 1 << " : " << passName[i] << endl;
    }
    cout << endl;
    cout << "seating plan : \n";
    for (int i = 0; i < row; i++) {
        cout << "| ";
        for (int j = 0; j < 4; j++) {
            cout << (seating_plan[i][j] ? " booked  " : "notBooked") << " | ";
        }
        cout << endl;
        cout << "--------------------------------------------------\n";
    }
    cout << endl;
}

void Flight::displayList() {
    for (int i = 0; i < booked_seats; i++) {
        cout << i + 1 << " : " << passName[i] << endl;
    }
}

void Flight::display_plan()
{
    for (int i = 0; i < row; i++) {
        cout << "| ";
        for (int j = 0; j < 4; j++) {
            cout << (seating_plan[i][j] ? "booked" : "notBooked") << " | ";
        }
        cout << endl;
        cout << "--------------------------------------------------\n";
    }
    cout << endl;
}

void Flight::addPass(int num, Passenger p[]) {
    for(int lol=0;lol<num;lol++) {
        if (booked_seats == capacity) {
            capacity += 4;
            bool** temp = new bool* [row + 1];
            string* stemp = new string[capacity];
            for (int i = 0; i < capacity - 4; i++) {
                stemp[i] = passName[i];
            }
            delete[] passName;
            passName = new string[capacity];
            for (int i = 0; i < capacity; i++) {
                passName[i] = stemp[i];
            }
            delete[] stemp;
            for (int i = 0; i < row; i++) {
                temp[i] = new bool[4];
                for (int j = 0; j < 4; j++) {
                    temp[i][j] = seating_plan[i][j];
                }
                delete seating_plan[i];
            }
            temp[row++] = new bool[4];

            delete[] seating_plan;
            seating_plan = new bool* [row];
            for (int i = 0; i < row; i++) {
                seating_plan[i] = new bool[4];
                for (int j = 0; j < 4; j++) {
                    seating_plan[i][j] = temp[i][j];
                    if (i == row - 1) seating_plan[i][j] = false;
                }
                delete temp[i];
            }
            delete[] temp;
        }
        booked_seats++;
        for (int i = 0; i < capacity; i++) {
            if (passName[i].empty()) {
                passName[i] = p[lol].getName();
                break;
            }
        }
        bool flag = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < 4; j++) {
                if (!seating_plan[i][j]) {
                    seating_plan[i][j] = true;
                    flag=0;
                    break;
                }
            }
            if (!flag)break;
        }

    }
}

int Flight::searchPass(string name) {
    for (int i = 0; i < capacity; i++) {
        if (name == passName[i]) return 1;
    }
    return -1;
}

string Flight::searchSeat(string seat) {
    int y = seat[0] - 'A', x = seat[1] - '0';
    if(y>=row || x>= 4) return "not on the plane\n";
    return (seating_plan[y][x]? "Booked" : "notBooked");
}

void Flight::removePass(Passenger passenger) {
    int ind = searchPass(passenger.getName()) + 1;
    if(ind ==0){
        cout<<"passenger not found\n";
        return;
    }
    passName[ind - 1].clear();
    booked_seats--;
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 4; j++) {
            if (seating_plan[i][j]) cnt++;
            if (cnt == ind) {
                seating_plan[i][j] = false;
                return;
            }
        }
    }
}

ostream& operator<<(ostream& output, Flight& obj) {
    obj.displayInfo();
    return output;
}

Flight& Flight::operator++() {
    capacity += 4;
    bool** temp = new bool* [row + 1];
    string* stemp = new string[capacity];
    for (int i = 0; i < capacity - 4; i++) {
        stemp[i] = passName[i];
    }
    delete[] passName;
    passName = new string[capacity];
    for (int i = 0; i < capacity; i++) {
        passName[i] = stemp[i];
    }
    delete[] stemp;
    for (int i = 0; i < row; i++) {
        temp[i] = new bool[4];
        for (int j = 0; j < 4; j++) {
            temp[i][j] = seating_plan[i][j];
        }
        delete seating_plan[i];
    }
    temp[row++] = new bool[4];

    delete[] seating_plan;
    seating_plan = new bool* [row];
    for (int i = 0; i < row; i++) {
        seating_plan[i] = new bool[4];
        for (int j = 0; j < 4; j++) {
            seating_plan[i][j] = temp[i][j];
            if (i == row - 1) seating_plan[i][j] = false;
        }
        delete temp[i];
    }
    delete[] temp;
    return *this;
}

Flight& Flight::operator+=(Passenger& passenger) {
    if (booked_seats == capacity) {
        cout << "\nno place for this passenger\n ";
        return *this;
    }
    booked_seats++;
    for (int i = 0; i < capacity; i++) {
        if (passName[i].empty()) {
            passName[i] = passenger.getName();
            break;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 4; j++) {
            if (!seating_plan[i][j]) {
                seating_plan[i][j] = true;
                return *this;
            }
        }
    }
    return *this;
}

Flight& Flight::operator--(int) {
    int ind = booked_seats > 0 ? --booked_seats : 0;
    passName[ind].clear();
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (seating_plan[i][j]) {
                seating_plan[i][j] = false;
                return *this;
            }
        }
    }
    return *this;
}

Flight& Flight::operator-=(int number) {
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (seating_plan[i][j]) {
                number--;
                seating_plan[i][j] = false;
                passName[--booked_seats].clear();
            }
            if(booked_seats==0) return *this;
            if (number == 0) return *this;
        }
    }
    return *this;
}

Flight::~Flight()
{
    for (int i = 0; i < row; i++) {
        delete[]seating_plan[i];
    }
    delete[]seating_plan;
    delete[]passName;
}