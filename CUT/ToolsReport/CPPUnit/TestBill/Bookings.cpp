#include "Bookings.h"
#include<map>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
Bookings::Bookings(int booking_id,string cust_first_name,string cust_last_name,string address,string from_date,string to_date,int no_of_persons){
        this->booking_id =booking_id;
        this->first_name = cust_first_name;
        this->last_name= cust_last_name;
        this->address=address;
       // this->phone_number=phone_number;
        this->stay_start_date = from_date;
        this->stay_end_date = to_date;
        this->no_of_persons= no_of_persons;
    }
bool isLeapYear(int year)
 {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
     
int daysBetweenDates(string date1, string date2) {
        
    int year1 = stoi(date1.substr(0, 4));
    int month1 = stoi(date1.substr(5, 2));
    int day1 = stoi(date1.substr(8));
    
    int year2 = stoi(date2.substr(0, 4));
    int month2 = stoi(date2.substr(5, 2));
    int day2 = stoi(date2.substr(8));
    
    vector<int> days1 = {31, isLeapYear(year1) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days2 = {31, isLeapYear(year2) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count1 = 0;
    for(int i=1971; i<year1; i++){
        count1 += (i%4 == 0 ? 366 : 365);
    }
    for(int i=0; i<month1 - 1; i++){
        count1 += days1[i];
    }
    count1 += day1;
    
    int count2 = 0;
    for(int i=1971; i<year2; i++){
        count2 += (i%4 == 0 ? 366 : 365);
    }
    for(int i=0; i<month2 - 1; i++){
        count2 += days2[i];
    }
    count2 += day2;
    
    return abs(count2 - count1);
}

void Bookings::updateBillBook(map<int,Bookings>&bookings,int custid,double total_bill){

 string first_name,last_name,booking_id,customer_id,from_date,to_date;
  for(auto it=bookings.begin(); it!=bookings.end(); it++)
 { 
    if(it->second.getcustomerId()==custid){
       booking_id=it->second.getbookingId();
       first_name=it->second.getfirstName();
       last_name=it->second.getlastName();
       from_date=it->second.getfromDate();
       to_date=it->second.gettoDate();
 }
}
 


            int noOfDaysOfStay = daysBetweenDates(from_date,to_date);

            string full_name = first_name +" "+ last_name;



            char filename[ ] = "billbook.txt";


            ofstream file_out;



            file_out.open(filename, std::ios_base::app);

            file_out <<booking_id<<":"<<full_name<<":"<<customer_id<<":"<<noOfDaysOfStay<<":"<<total_bill<<endl;
            file_out.close();

    }

 double Bookings::calculateBill(map<int,Bookings>&bookings,int custid)
    {
        string first_name,last_name,customer_id,from_date,to_date;
        int no_of_persons;
    for(auto it=bookings.begin(); it!=bookings.end(); it++)
    { 
            if(it->second.getCustomerId()==custid)
            {
                
                first_name=it->second.getfirstName();
                last_name=it->second.getlastName();
                from_date=it->second.getfromDate();
                to_date=it->second.gettoDate();
                no_of_persons=it->second.getnoofPersons();
              }
    }

    
    int noOfDaysOfStay = daysBetweenDates(from_date,to_date);
    //update the rent of room
    double totalBill = ((double)noOfDaysOfStay*((double)10000))) + (double)noOfDaysOfStay *((double) 200) + ((double)200* (double)no_of_persons);
    double service_tax = 15;
    double GST = 5;
    double totalTax = (totalBill*(service_tax/(double)100) + totalBill*(GST/(double)100) );
    totalBill = totalBill + totalTax;
    cout<<totalBill<<endl;
    
    return totalBill;
    }
    
    