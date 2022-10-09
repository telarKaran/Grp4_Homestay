#include "../header/customer.h"
//seter functions..............................
void Customer::setCustomerFName(string first_name)
{
    this->first_name = first_name;
}
void Customer::setCustomerLName(string last_name)
{
    this->last_name = last_name;
}

void Customer::setCustomerAddress(string address)
{
    this->address = address;
}
void Customer::setCustomerId(int id){
      this->customer_id= id;
   }


//-------------------------------------------------

string Customer::getCustomerFName()
{
    return first_name;
}
string Customer::getCustomerLName()
{
    return last_name;
}
string Customer::getCustomerAddress()
{
    return address;
}
string Customer::getfromDate(){
 return stay_start_date;
}
string Customer::gettoDate(){
 return stay_end_date;
}
int Customer::getnoofPersons(){
    return no_of_persons;
}
int Customer::getCustomerId(){
      return customer_id;
   }


