#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<sstream>
#include <hotel.h>
using namespace std;



void case1(Hotel &nature_valley){
     system("clear");
  
    cout<<"\n-------Manage Rooms--------------"<<endl;
    cout<<"\n-------Enter 1: Search Available Rooms-------"<<endl;
    cout<<"\n------Enter 2: Back to main Menu-------"<<endl;
    int input2;
    cout<<"option"<<endl;
     cin>>input2;
    switch(input2) {
        case 1:  
            nature_valley.displayRooms();
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
    cout<<"\n-------Manage Cutomers--------------"<<endl;
    cout<<"\n-------Enter 1: Booking-------"<<endl;
    cout<<"\n-------Enter 2: Check In------"<<endl;
    cout<<"\n------ Enter 3: Check out------"<<endl;
    cout<<"\n-------Enter 4:  Back to Main Menu-------"<<endl;
    
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
            //back to mainmenu
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
    cout<<"\n\t-------Display Reports------------"<<endl;
    cout<<"\n-------Enter 1: Customer Report-------"<<endl;
    cout<<"\n------Enter 2: Booking Report-------"<<endl;
    cout<<"\n-------Enter 3: Rooms Report-------"<<endl;
    cout<<"\n-------Enter 4: Back to Main Menu-------"<<endl<<endl;
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
        cout<<"\n\t-------WELCOME TO THE HOTEL NATURE VALLEY---------------"<<endl;
        int input;
        cout<<"\n-------Enter 1: Manage Rooms-------"<<endl;
        cout<<"\n-------Enter 2: Manage Customers---"<<endl;
        cout<<"\n-------Enter 3: Guest Reports------"<<endl;
        cout<<"\n-------Enter 4: Exit Main Menu-----"<<endl;
        cout<<"\n-------Enter choice :"<<endl;
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
//nature_valley.updateCustomerDB();
nature_valley.updateRoomDB();
nature_valley.updateCheckInDB();
nature_valley.updateCheckOutDB();
     
//nature_valley.deleteSpace();
cout<<"\n\nThank you for using the application"<<endl;
return 0;
}
