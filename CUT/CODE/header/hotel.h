#include<vector>
#include<map>
#include "./rooms.h"
#include "./customer.h"
#include "./bookings.h"

class Hotel 
{
private:
vector<Room*>room;
map<int,Bookings>bookings;
map<int,Customer>cust;
vector<int>checkout;
public:
void booking_func();
void checkIn(); 
void checkOut();
double calculateBill(int,int);
void updateBillBook(int,double);
int noofAvailableRooms();
void displayRooms();
void updateBookingDB();
void updateCustomerDB();
void updateRoomDB();
void filereadRooms();
void filereadBooking();
void displayBookingsReports();
void displayCutomerReports();
void displayRoomReports();
void readCheckOutDB();
void updateCheckOutDB();
vector<Room*> getRoom(){
    return room;
}



/*void deleteSpace(){
         for(auto it=room.begin();it!=room.end(); it++){
            delete *it;
         }
}*/
};

