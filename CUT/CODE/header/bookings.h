#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class Bookings {
private:
    int booking_id;
    int customer_id;
    string first_name;
    string last_name;
    string address;
    string from_date;
    string to_date;
    int no_of_persons;
    double total_bill;
public:
   
Bookings();
Bookings(int booking_id,string cust_first_name,string cust_last_name,string address,string from_date,string to_date,int no_of_persons,int custid=00000){
        this->booking_id =booking_id;
        this->first_name = cust_first_name;
        this->last_name= cust_last_name;
        this->address=address;
        this->from_date = from_date;
        this->to_date= to_date;
        this->no_of_persons= no_of_persons;
        this->customer_id=custid;
    }
int getbookingId();
 string getfirstName();
 string getlastName();
 int getcustomerId();
 string getfromDate();
 string gettoDate();
 int getnoofPersons();
 string getAddress();
 void setCustomerId(int custid);
};

