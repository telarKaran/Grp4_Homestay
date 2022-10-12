#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include <hotel.h>
#include "./hotel1.cpp"
#define FOOD_CHARGE 1000
#define EXTRA_PERSON_CHARGE 500   
using namespace std;


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
 
     
int daysBetweenDates(string date1, string date2){

        
    int year1 = stoi(date1.substr(0, 4));
    int month1 = stoi(date1.substr(5, 2));
    int day1 = stoi(date1.substr(8));
     int result1=  isValidDate(day1,month1,year1);
     if(result1==0){
        return 0;
     }
    
    int year2 = stoi(date2.substr(0, 4));
    int month2 = stoi(date2.substr(5, 2));
    int day2 = stoi(date2.substr(8));
    int result2=  isValidDate(day1,month1,year1);
    if(result2==0){
        return 0;
    }
    
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
    
    return (count2 - count1);
}

void Hotel::booking_func()
{
     system("clear");
     string cust_first_name,cust_last_name,cust_phone,cust_address,stay_start_date,stay_end_date;
     int no_of_persons,year1,month1,day1,year2,month2,day2,key;
     bool flag =0,res1,res2;
        //menudriven;
       cout<<"\nEnter First name"<<endl;
       cin>>cust_first_name;
       cout<<"\nEnter Last name"<<endl;
       cin>>cust_last_name;
       cout<<"\nEnter your address"<<endl;
       cin>>cust_address;
       cout<<"\nenter your phone number"<<endl;
       cin>>cust_phone;
       cout<<"\nenter the from date of stay"<<endl;


       cin>>stay_start_date;
       cout<<"\nenter the to date of stay "<<endl;
       cin>>stay_end_date;
        cout<<"\nenter number of persons"<<endl;
        cin>>no_of_persons;
        //genarate booking id;
        if(no_of_persons>5){
         cout<<"\nonly five persons are allowed in a single room"<<endl;
           return;
        }
        try {
        year1 = stoi(stay_start_date.substr(0, 4));
        month1 =stoi(stay_start_date.substr(5, 2));
        day1 =  stoi(stay_start_date.substr(8));
        res1 = isValidDate(day1, month1,year1);
        year2 = stoi(stay_end_date.substr(0, 4));
        month2 =stoi(stay_end_date.substr(5, 2));
        day2 = stoi(stay_end_date.substr(8));
        res2 = isValidDate(day2, month2,year2);
        }
        catch(...){
           cout<<"\nenter valid date format yyyy-mm-dd"<<endl;
        }
        int res3 =0;
        if(res1==1 && res2==1){
        res3 = daysBetweenDates(stay_start_date,stay_end_date);
        }

        if(res1==1 && res2==1 && res3>=1 && res3<=10 && cust_phone.size()==10){
                  fstream fin2;
                  string segment;
                 fin2.open("../data/stat1.txt",ios::in);
                 getline(fin2,segment);
                 int  bookId=(stoi)(segment);
               fin2.close();
               bookId++;
        Bookings booking_new(bookId,cust_first_name,cust_last_name,cust_address,stay_start_date,stay_end_date,no_of_persons);

         bookings[bookId] = booking_new;


             fstream file_out;
              file_out.open("../data/stat1.txt");
              file_out<<bookId;
             file_out.close();
        cout<<"\nBooking Done Succesfully and your bookingId is :"<<bookId<<endl;
            
        }
        else{
            cout<<"\nplease enter correct details"<<endl;
        }
}

void Hotel::checkOut()
{
            system("clear");
            int custid,bookId, rent,key;
            string confirmation;
            double totalBill;
            bool flag1=0;
                        
            cout<<"Enter booking id";
            cin>>bookId;
            auto it=bookings.find(bookId);
            for(int i=0; i<checkout.size(); i++ ){
                      if(checkout[i]==bookId){
                         flag1=1;
                      }
               }
            if(it!=bookings.end() && it->second.getcustomerId()!=0 && flag1==0)
            {
                    custid= it->second.getcustomerId();
                    checkout.push_back(bookId);

                for(auto itr=room.begin(); itr!=room.end();itr++)
                  {
                       if((*itr)->getCustomerId()==custid)

                        {
                           string roomType = (*itr)->getType();
                           if(roomType=="standard"){
                               rent =((StdRoom*)(*itr))->getRent();
                               
                            
                           }
                           else if(roomType=="deluxe"){
                               rent =((Deluxe*)(*itr))->getRent();
                              
                           }
                           else{
                               rent =((Cottage*)(*itr))->getRent();
                            
                           }
                            int default_val =0;
                           (*itr)->setcustomerId(default_val);
                           bool flag=0;
                           (*itr)->setStatus(flag);
                           break;
                        }
                  }
                  try{
            
                     totalBill = calculateBill(bookId,rent);
                     cout<<" your bill amount is :"<<totalBill<<endl;
                     cout<<"please enter the payment mode";
                     cin>>confirmation;
                      if(confirmation=="NO"){
                        cout<<"please process your payment"<<endl;
                        return;
                      }

                  }
                  catch(...){
                    cout<<"exception occured"<<endl;
                  }
                 updateBillBook(bookId,totalBill);
                      
                cout<<"Customer Checked out Succesfully and updated Bill Book"<<endl;
    
                    for(auto ite=check_in.begin(); ite!=check_in.end(); ite++){
                        if(*ite==bookId){
                            check_in.erase(ite);
                            break;
                        }
                    }
                    
            }
            else{
                cout<<"\nenter valid booking id"<<endl;
                cout<<"\nenter any key to checkout again"<<endl;
                cin>>key;
            }
}


void Hotel::updateBillBook(int bookId,double total_bill){

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



            char filename[ ] = "../reports/billbook.txt";


            ofstream file_out;



            file_out.open(filename, std::ios_base::app);

            file_out <<bookId<<":"<<full_name<<":"<<customer_id<<":"<<noOfDaysOfStay<<":"<<total_bill<<endl;
            file_out.close();

    }
double Hotel::calculateBill(int bookId,int rent)
    {
        string first_name,last_name,customer_id,from_date,to_date;
        int no_of_persons,extraPersons=0;
      auto it =bookings.find(bookId);
      //cout<<bookId<<endl;
    
            if(it!=bookings.end())
            {
                
                first_name=it->second.getfirstName();
                last_name=it->second.getlastName();
                from_date=it->second.getfromDate();
                to_date=it->second.gettoDate();
                
                no_of_persons=it->second.getnoofPersons();
              }
              
              if(no_of_persons>3){
                extraPersons=no_of_persons-3;
              }
              
    int noOfDaysOfStay = daysBetweenDates(from_date,to_date);
             
    //update the rent of room
    double totalBill = ((double)noOfDaysOfStay*rent) + (double)noOfDaysOfStay *(FOOD_CHARGE) + (EXTRA_PERSON_CHARGE* (double)extraPersons);
    double service_tax = 15;
    double GST = 5;
    double totalTax = (totalBill*(service_tax/(double)100) + totalBill*(GST/(double)100) );
    totalBill = totalBill + totalTax;
    cout<<totalBill<<endl;

    return totalBill;
    }
   
void Hotel::displayCutomerReports(){
        int key;
        system("clear");
        cout<<"\n\n"<<endl;
        for(auto it =cust.begin();it!=cust.end(); it++){
            cout<<"\n";
            cout<<it->second.getCustomerId()<<" "<<it->second.getCustomerFName()<<" "<<it->second.getCustomerLName()<<" "<<it->second.getCustomerAddress()<<" "<<it->second.getfromDate()<<" "<<it->second.gettoDate()<<" "<<it->second.getnoofPersons()<<endl;
        }
        cout<<"\nEnter any key to exit"<<endl;
        cin>>key;
    }
    void Hotel::displayBookingsReports(){
        system("clear");
        cout<<"\n\n"<<endl;
       int key;
        for(auto it =bookings.begin();it!=bookings.end(); it++){
            cout<<"\n"<<endl;
            cout<<it->second.getbookingId()<<" "<<it->second.getcustomerId()<<" "<<it->second.getfirstName()<<" "<<it->second.getlastName()<<" "<<it->second.getfromDate()<<" "<<it->second.gettoDate()<<" "<<it->second.getnoofPersons()<<endl;
        }
        cout<<"\nEnter any key to exit"<<endl;
        cin>>key;
    }
    void Hotel::displayRoomReports(){
        int key;
        system("clear");
        cout<<"\n\n"<<endl;
        for(auto it = room.begin(); it!=room.end(); it++){
            cout<<"\n"<<endl;
cout<<(*it)->getRoomNumber()<<" "<<(*it)->getStatus()<<" "<<" "<<(*it)->getType()<<" "<<(*it)->getStype()<<endl;
            }
            cout<<"\nEnter any key to exit"<<endl;
        cin>>key;
    }
    void Hotel::updateBookingDB(){
    char filename[ ] = "../reports/bookDB.txt";
        ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);
        auto it =bookings.begin();

    
    while(it!=bookings.end())
        { 
        
        file_out <<it->second.getbookingId()<<":"<<it->second.getcustomerId()<<":"<<it->second.getfirstName()<<":"<<it->second.getlastName()<<":"<<it->second.getAddress()<<":"<<it->second.getfromDate()<<":"<<it->second.gettoDate()<<":"<<it->second.getnoofPersons()<<endl;
        
        it++;
        }
        file_out.close();
}
void Hotel::updateCustomerDB(){
    char filename[ ] = "../reports/customerDB.txt";
       ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);
         auto itr=bookings.begin();
    
    while(itr!=bookings.end() && itr->second.getcustomerId()!=0)
        { 
        
        file_out <<itr->second.getcustomerId()<<":"<<itr->second.getfirstName()<<" "<<itr->second.getlastName()<<":"<<itr->second.getfromDate()<<":"<<itr->second.gettoDate()<<":"<<itr->second.getnoofPersons()<<endl;

        itr++;
        }
        file_out.close();
 
}