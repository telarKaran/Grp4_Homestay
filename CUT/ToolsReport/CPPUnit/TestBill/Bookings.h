#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class Bookings {
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
Bookings()
{
        //constructor
   
}
//Bookings(int,string,string,string,string,string,int);

int getbookingId(){
    return booking_id;
}
//void Bookings(int,string,string,string,string,int);
 string getfirstName(){
 return first_name;
 }
 string getlastName(){
 return last_name;
 }
 int getcustomerId(){
    return customer_id;
 }
 string getfromDate(){
    return from_date;
 }
 string gettoDate(){
 return to_date;
 }
 int getnoofPersons(){
 return no_of_persons;
 }
 void setCustomerId(int custid){
   this->customer_id= custid;
 }

//void displayBooking(int a){}
//void displayBill(int a){}
//double calculateBill(map <int,Bookings > &bookings,int k);
//void updateBillBook(map <int,Bookings > &bookings,int k,double d);
Bookings(int booking_id,string cust_first_name,string cust_last_name,string address,string from_date,string to_date,int no_of_persons,int custid=00000){
        this->booking_id =booking_id;
        this->first_name = cust_first_name;
        this->last_name= cust_last_name;
        this->address=address;
       // this->phone_number=phone_number;
     
        this->from_date = from_date;
        this->to_date= to_date;
        this->no_of_persons= no_of_persons;
        this->customer_id=custid;
    }
    Bookings(int booking_id,int custId,string cust_first_name,string cust_last_name,string address,string from_date,string to_date,int no_of_persons){
        this->booking_id =booking_id;
        this->customer_id=custId;
        this->first_name = cust_first_name;
        this->last_name= cust_last_name;
        this->address=address;
       // this->phone_number=phone_number;
        this->from_date = from_date;
        this->to_date= to_date;
        this->no_of_persons= no_of_persons;
        this->customer_id=custId;
    }
bool isLeapYear(int year)
 {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
     
     bool isValidDate(int day, int month, int year)
{
    
    if (month < 1 || month > 12)
    return false;
    if (day < 1 || day > 31)
    return false;
 
    // Handle February month
    // with leap year
    if (month == 2)
    {
        if (isLeapYear(year))
        return (day<= 29);
        else
        return (day <= 28);
    }
 
    if (month == 4 || month== 6 ||
        month == 9 || month == 11)
        return (day <= 30);
 
    return true;
}
 
int daysBetweenDates(string date1, string date2) {
    //cout<<date1<<endl;

    int year1, month1, day1;
        try{
                    
            year1 = stoi(date1.substr(0, 4));
            month1 = stoi(date1.substr(5, 2));
            day1 = stoi(date1.substr(8));

            }
            catch(...){
                cout<<"Error!!!!!!!!!!"<<endl;
            }

    //cout<<year1<<endl;
    if(!isValidDate(day1,month1,year1)){
        return -1;
    }

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
    

    if(!((count2 - count1)>0)){
        return -1;
    }else{
        return count2-count1;
    }
}
void updateBillBook(map<int,Bookings>&bookings,int bookId,double total_bill){

 string first_name,last_name,booking_id,from_date,to_date;
 int customer_id, no_of_persons;
 auto it = bookings.find(bookId);
  if(it!=bookings.end())
 {
       customer_id=it->second.getcustomerId();
       first_name=it->second.getfirstName();
       last_name=it->second.getlastName();
       from_date=it->second.getfromDate();
       to_date=it->second.gettoDate();
       no_of_persons=it->second.getnoofPersons();
 }

 


            int noOfDaysOfStay = daysBetweenDates(from_date,to_date);

            string full_name = first_name +" "+ last_name;



            char filename[ ] = "billbook.txt";


            ofstream file_out;



            file_out.open(filename, std::ios_base::app);

            file_out <<bookId<<":"<<full_name<<":"<<customer_id<<":"<<noOfDaysOfStay<<":"<<total_bill<<endl;
            file_out.close();

    }
double calculateBill(map<int,Bookings>&bookings,int bookId)
    {
        string first_name,last_name,customer_id,from_date,to_date;
        int no_of_persons;
      
      auto it =bookings.find(bookId);
      //cout<<bookId<<endl;
    
            if(it!=bookings.end())
            {
                
                first_name=it->second.getfirstName();
                last_name=it->second.getlastName();
                from_date=it->second.getfromDate();
                to_date=it->second.gettoDate();
                //cout<<it->second.gettoDate();
                no_of_persons=it->second.getnoofPersons();
              }
              //cout<<bookId<<endl;

   int noOfDaysOfStay = daysBetweenDates(from_date,to_date);
    
      if(no_of_persons>3){
            return -1;
        }
    
    //update the rent of room
    double totalBill = ((double)noOfDaysOfStay*1000) + (double)noOfDaysOfStay *(100) + (100* (double)no_of_persons);
    double service_tax = 15;
    double GST = 5;
    double totalTax = (totalBill*(service_tax/(double)100) + totalBill*(GST/(double)100) );
    totalBill = totalBill + totalTax;
    
     if(totalBill<0){
        return -1;
    }else{
        return totalBill;
    }
   // return totalBill;

    }
};
 