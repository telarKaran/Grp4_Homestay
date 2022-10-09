#include<iostream>
#include<string>
using namespace std;
class Customer
{
private:
int customer_id;
string first_name;
string last_name;
string address;
string stay_start_date;
string stay_end_date;
int no_of_persons;
public:
Customer(){

}
 Customer(int custid,string first_name,string last_name,string address,string from_date,string to_date,int no_of_persons){
   this->customer_id =custid;
   this->first_name=first_name;
   this->last_name=last_name;
   this->stay_start_date=from_date;
   this->stay_end_date=to_date;
   this->no_of_persons=no_of_persons;
   this->address=address;
    //constructor
 }
void setCustomerDetails(string first_name,string last_name,string phone_number,string address);
   void setCustomerFName(string);
   void setCustomerLName(string);
   void setCustomerPhoneNumber(string);
   void setCustomerAddress(string);
   void setCustomerId(int);

   //---------- Getters -------------
   string getCustomerFName();
   string getCustomerLName();
   string getCustomerPhoneNumber();
   string getCustomerAddress();
   int  getnoofPersons();
   string getfromDate();
   string gettoDate();
   int getCustomerId();
};