// Ahmed Essam 20236012   
// sherif abdulmagid 20236051
#include <iostream>
#include "flight.h"
#include "passenger.h"
using namespace std;

int main()
{
    cout << "welcome to the flight system\n";
    cout << "-------------------------------\n";

    string c1;
    while (c1 != "start") {
        cout << "to start the simulation of the first flight type start : ";
        cin >> c1;
    }
    int neg=0;
    Flight squad(8, "barcelona", 1899);
    Passenger manager("flick", 0);
    Passenger legend("messi", 10);
    Passenger coach("pep", 2009);
    Passenger club_president("laporte", 59);
    Passenger captain("puyol", 2006);
    cout << "flight initiated with the capacity of 8 going to barcelona\n";
    squad.displayInfo();
    cout << "to exit press zero : \nto continue press number "; int c2; cin >> c2;
    if (!c2){
        cout<<endl<<"\nthanks for using our simulation\n";
        return 0;
    }

    squad += manager;
    squad += legend;
    squad += coach;
    squad += club_president;
    squad += captain;
    cout << endl <<"now to add and display the details of the first 5 passengers\n"<<endl;
    manager.display_details(); cout << endl;
    legend.display_details(); cout << endl;
    coach.display_details(); cout << endl;
    club_president.display_details(); cout << endl;
    captain.display_details(); cout << endl;

    cout << "to exit press zero : \nto continue type any number :  "; cin >> c2;
    if (!c2){
        cout<<endl<<"\nthanks for using our simulation\n";
        return 0;
    }

    cout << endl << "\nnow to diplay the flight information after adding the first 5 passengers\n";
    squad.displayInfo();

    cout << "\nto exit press zero : \nto continue type any number :  "; cin >> c2;
    if (!c2){
        cout<<endl<<"\nthanks for using our simulation\n";
        return 0;
    }

    cout << endl << "\nnow it is your turn to add\n";
    cout << "enter the number of players from 1 to 20 to add them : "; int c3; cin >> c3;
    while (c3 < 1 || c3>20) {
        cout << "\nenter number between 1 and 20 : "; cin >> c3;
    }
    Passenger* player = new Passenger[c3];
    for (int i = 0; i < c3; i++)
    {
        cout << "player " << i + 1 << " data : ";
        cin >> player[i];
    }

    squad.addPass(c3,player);
    cout<<"\nthe flight info after adding the players you entered\n";
    cout<<squad;

    cout << "\nto exit press zero : \nto continue type any number :  "; cin >> c2;
    if (!c2){
        cout<<endl<<"\nthanks for using our simulation\n";
        return 0;
    }
    cout<<"\nnow your turn to create your flight\n";
    cout<<"to copy the current flight press 1 || to create your own press 2 : ";
    int c4=0; cin>>c4;
    while(c4!=1 && c4!=2){
        cout<<"enter 1 or 2 : ";cin>>c4;
    }
    Flight copy(squad);
    if(c4==1){
        cout<<"\n-----------------------\ncopied class initiated\n-----------------------\n";
        while(1){
            cout << "\nto exit press zero : \nto operate on the new copied flight press any number :  "; cin >> c2;
            if (!c2)break;
            cout<<"to display the old flight press 1\n";
            cout<<"to display the new flight press 2\n";
            cout<<"to add a row in the new flight press 3\n";
            cout<<"to remove the last passenger from the new flight press 4\n";
            cout<<"to search for a passenger by his name in the flight press 5\n";
            cout<<"to search for a seat if it is booked or not press 6\n";

            int c5=0 ; cin>>c5;
            while(c5<0 || c5>7){
                cout<<"enter number from 1 to 6 : ";cin>>c5;
            }
            if(c5==1){
                cout<<"\nthe old flight data :\n";
                cout<<squad;
            }
            else if(c5==2){
                cout<<"\nthe new flight data :\n";
                cout<<copy;
            }
            else if(c5==3){
                ++copy;
                cout<<"\nthe new seating plan of the new flight\n";
                copy.display_plan();
            }
            else if(c5==4){
                copy--;
                neg++;
                cout << "\nthe passenger left the flight\n";
                cout<<"\nthe new flight data :\n";
                cout<<copy;
            }
            else if(c5==5){
                cout<<"enter the passenger name :\n";
                string name; cin>>name;
                if(copy.searchPass(name)==-1)cout<<"this name is not on the plane\n";
                else cout<<"this name is on the plane\n";
            }

            else if(c5==6){
                cout<<"enter the seat number in form of a capital letter and a number ex. A2 : ";
                string seat; cin>>seat;
                cout<<copy.searchSeat(seat);
            }
        }
    }
    else if(c4==2){
        cout<<"create your own flight : \n";
        int cap, id;
        string dis;
        cout<<"please insert your capacity : "; cin>>cap;
        while(cap%4){
            cout<<"please enter a number that is divisible by 4 : "; cin>>cap;
        }
         cout<<"\nplease enter your destination : \n"; cin>>dis;
        cout<<"please enter your flight id : "; cin>>id;
        Flight created(cap,dis,id);
        cout<<"your flight is initiated : \n"<<created;
        cout<<"now add your passengers\n";
        int c34;
        cout<<"add the number of passengers you want passengers\n";
        while (c34 < 1 || c34>50) {
            cout << "\nenter number between 1 and 50 : "; cin >> c34;
        }
        Passenger* player = new Passenger[c34];
        for (int i = 0; i < c34; i++)
        {
            cout << "player " << i + 1 << " data : ";
            cin >> player[i];
        }
        created.addPass(c34,player);
        cout<<"the  total number of passengers across the whole system is : "<<coach.getCount();
        cout<<"to display your flight press anything";cin>>c2;
        cout<<"the data of your flight after adding passengers :\n"<<created;
    }
    cout<<"\n\n-------------------------------------------------------------------------------------------\n\n";
    cout<<"thanks for using our simulation \nand of course you are welcome to read the code"
          " \nand edit all you want to test the functions differently \n";
    cout<<"\n hope you enjoyed";
}