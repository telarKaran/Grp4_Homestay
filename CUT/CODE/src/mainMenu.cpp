#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<sstream>
#include "../header/hotel.h"
using namespace std;



void case1(Hotel &nature_valley){
     system("clear");
  
    cout<<"-------Manage Rooms--------------"<<endl;
    cout<<"-------Enter 1: Search Available Rooms-------"<<endl;
    cout<<"-------Enter 2: Back to main Menu-------"<<endl;
    int input2;
    cout<<"option"<<endl;
     cin>>input2;
    switch(input2) {
        case 1:  
            int index;
            for(auto it = nature_valley.getRoom().begin(); it!=nature_valley.getRoom().end();it++){
                if((*it)->getRoomNumber()==input2){
                     index=(*it)->getRoomNumber();
               (nature_valley.getRoom())[index]->searchRoom(nature_valley.getRoom()[index]);
              break;
                }
            }
          break;
        
        case 2: {
               //back to main menu
            break;
        }
        default: {
            cout<<"--------Invalid Input-----------"<<endl;
            break;
        }
    }
}

void case2(Hotel &nature_valley) {
   system("clear");
    cout<<endl;
    cout<<"-------Customer Rooms--------------"<<endl;
    cout<<"-------Enter 1: Booking-------"<<endl;
    cout<<"-------Enter 2: Check In------"<<endl;
    cout<<"-------Enter 3: Check out------"<<endl;
    cout<<"-------Enter 4:  Edit info--------"<<endl;
    cout<<"-------Enter 5: Back to Main Menu-------"<<endl<<endl;
    int input2;
    cout<< "Enter Choice "<<endl;
    cin>>input2;
    switch(input2) {
        case 1: {
            nature_valley.booking_func();
            break;
        }
        case 2: {
            nature_valley.checkIn();
            break;
        }
        case 3: {
            nature_valley.checkOut();
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            //getting back to main menu
            break;
        }
        default: {
            cout<<"--------Invalid Input-----------"<<endl;
            break;
        }
    }
}

void case3(Hotel &nature_valley) {
    system("clear");
    cout<<"-------Display Reports------------"<<endl;
    cout<<"-------Enter 1: Customer Report-------"<<endl;
    cout<<"-------Enter 2: Booking Report-------"<<endl;
    cout<<"-------Enter 3: Rooms Report-------"<<endl;
    cout<<"-------Enter 4: Back to Main Menu-------"<<endl<<endl;
    int input2;
    cout<<"Enter Choice"<<endl;
    cin>>input2;
    switch(input2) {
        case 1: {
            nature_valley.displayCutomerReports();
            break;
        }
        case 2: {
            nature_valley.displayBookingsReports();
            break;
        }
        case 3: {
            nature_valley.displayRoomReports();
            break;
        }
        case 4: {
            break;
        }
        default: {
            cout<<"--------Invalid Input-----------"<<endl<<endl;
            break;
        }
    }
}


int main() {

     
     Hotel nature_valley;

     //read the rooms file and bookings file
     nature_valley.filereadRooms();
     nature_valley.filereadBooking();
     nature_valley.readCheckOutDB();
     nature_valley.readCheckInDB();
     
     

    while(1){
        //Level 1
        system("clear");
        level1:
        cout<<"-------WELCOME TO THE HOTEL NATURE VALLEY---------------"<<endl;
        int input;
        cout<<"-------Enter 1: Manage Rooms-------"<<endl;
        cout<<"-------Enter 2: Manage Customers---"<<endl;
        cout<<"-------Enter 3: Guest Reports------"<<endl;
        cout<<"-------Enter 4: Exit Main Menu-----"<<endl;
        cout<<"Enter choice"<<endl;
        cin>>input;

        //Level 2
        switch(input) {
            case 1: {
                case1(nature_valley);
                goto level1;
            }

            case 2: {
                case2(nature_valley);
                goto level1;
            }

            case 3: {
                case3(nature_valley);
                goto level1;
            }

            case 4: {
                goto label;
            }

            default: {
                cout<<"--------Invalid Input-----------"<<endl<<endl;
                goto level1;
            }

        }
        label:
           break;
    }
//update the customer STL into customers database;
//update the room STL into rooms database;
//update the bookings STL into bookings database;
nature_valley.updateBookingDB();
nature_valley.updateCustomerDB();
nature_valley.updateRoomDB();
nature_valley.updateCheckOutDB();
nature_valley.updateCheckInDB();
     
//nature_valley.deleteSpace();
return 0;
}
