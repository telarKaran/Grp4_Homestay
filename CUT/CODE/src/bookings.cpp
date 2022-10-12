#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "../header/bookings.h"
using namespace std;
Bookings::Bookings(){
   
}

int Bookings::getbookingId(){
    return booking_id;
}
 string Bookings::getfirstName(){
 return first_name;
 }
 string Bookings::getlastName(){
 return last_name;
 }
 int Bookings::getcustomerId(){
    return customer_id;
 }
 string Bookings::getfromDate(){
    return from_date;
 }
 string Bookings::gettoDate(){
 return to_date;
 }
 int Bookings::getnoofPersons(){
 return no_of_persons;
 }
 string Bookings::getAddress(){
    return address;
 }
 void Bookings::setCustomerId(int custid){
   this->customer_id= custid;
 }



