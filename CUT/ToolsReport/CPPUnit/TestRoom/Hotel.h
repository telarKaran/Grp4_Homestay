#include "rooms.cpp"
#include "Customer.cpp"
#include "Bookings.h"
#include<vector>
#include<map>
class Hotel
{
public:
vector<Room>room;
map<int,Bookings>bookings;
map<int,Customer>cust;
void booking_func();
void checkIn(); 
void checkOut();
//void guestList();
void display(){
    for(auto it =bookings.begin() ;it!=bookings.end(); it++){
        cout<<it->second.getcustomerId()<<" "<<it->second.getbookingId()<<endl;
    }
}
};

