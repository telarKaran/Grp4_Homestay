#include<iostream>
#include<string>
#include<sstream>
#include "../header/hotel.h"
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
 
     
int daysBetweenDates(string date1, string date2) {

        
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
     string cust_first_name,cust_last_name,cust_phone,cust_address,stay_start_date,stay_end_date;
     int no_of_persons,year1,month1,day1,year2,month2,day2;
     bool flag =0,res1,res2;
        //menudriven;
       cout<<"Enter First name"<<endl;
       cin>>cust_first_name;
       cout<<"Enter Last name"<<endl;
       cin>>cust_last_name;
       cout<<"Enter your address"<<endl;
       cin>>cust_address;
       cout<<"enter your phone number"<<endl;
       cin>>cust_phone;
       cout<<"enter the from date of stay"<<endl;


       cin>>stay_start_date;
       cout<<"enter the to date of stay "<<endl;
       cin>>stay_end_date;
        cout<<"enter number of persons"<<endl;
        cin>>no_of_persons;
        //genarate booking id;
        if(no_of_persons>5){
         cout<<"only five persons are allowed in a single room"<<endl;
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
           cout<<"enter valid date format yyyy-mm-dd"<<endl;
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
        }
        else{
            cout<<"please enter correct details"<<endl;
        }
}
void Hotel::checkIn(){
    
     int booking_id,CustomerId;
     string room_type;

     cout<<"Enter booking id";
     cin>>booking_id;
     bool flag=0,flag1=0;
     
   if(!noofAvailableRooms()){
       cout<<"No rooms are available";
    }
    
    else{
        //traverse the bookings map  to get the customer details for the booking id
               auto it =bookings.find(booking_id);
               for(int i=0; i<checkout.size(); i++ ){
                      if(checkout[i]==booking_id){
                         flag1=1;
                      }
               }
               //generate customer id;
               if(it!=bookings.end() && flag1==0){
                  fstream fin2;
                  string segment;
                 fin2.open("../data/stat2.txt",ios::in);
                 getline(fin2,segment);
                  CustomerId=(stoi)(segment);
                fin2.close();
                
                displayRooms();
                CustomerId++;
        Customer custom(CustomerId,it->second.getfirstName(),it->second.getlastName(),it->second.getAddress(),it->second.getfromDate(),it->second.gettoDate(),it->second.getnoofPersons());
           cust[CustomerId] = custom;
           //update the bookings database with customer id;
              it->second.setCustomerId(CustomerId);
            

                cout<<"Enter the room type to stay in";
                cin>>room_type;
                if(room_type!="standard" && room_type!="delux" && room_type!="cottage"){
                    cout<<"Please choose valid room type"<<endl;
                    return;
                }
                for(auto x =room.begin(); x!=room.end();x++)
                {
                       if((*x)->getStatus()== 0 && (*x)->getType()==room_type)
                        {
                           (*x)->setcustomerId(CustomerId);
                           bool k=1;
                           (*x)->setStatus(k);
                           break;
                        }
                }
          
              fstream file_out;
              file_out.open("../data/stat2.txt");
              file_out<<CustomerId;
             file_out.close();

       }
            else{
               cout<<"Enter correct booking_id"<<endl;
            }
        }
}
void Hotel::checkOut()
{
            int custid,bookId, rent;
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
                            int default_val =00000;
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
                    
            }
            else{
                cout<<"enter valid booking id"<<endl;
            }
}
int  Hotel::noofAvailableRooms(){
    int count=0;
    for(auto it = room.begin(); it!=room.end(); it++){
            if((*it)->getStatus()==0){
                count++;
            }
    }
    return count;
}
void Hotel::displayRooms(){
    for(auto it = room.begin(); it!=room.end(); it++){
            if((*it)->getStatus()==0){
             cout<<(*it)->getRoomNumber()<<" "<<(*it)->getType()<<" "<<(*it)->getStype()<<endl;
            }
    }
}
bool checkValidity(string str)
{
  int words = 0;
  int lenOfStr = str.size();

  for(int i = 0; i < lenOfStr; i++)
  {
    if(str[i] == ':')
    {
      words++;
    }

  }

  words = words + 1;

 if(words==4){return 1;}else{return 0;}
}
void Hotel::filereadRooms()
{
    ifstream fin("../reports/roomsfile.txt");
	ifstream fin2("../reports/roomsfile.txt");
   while(true)
    {
		
        string segment;

        if (!getline(fin, segment)){
		break;}
		
		

        stringstream transporter;
	
        transporter << segment;

        string roomNumber;
		string type;
		string status;
		string stype;
		string line;
		getline(fin2,line);

		if(!checkValidity(line)){continue;}
        getline(transporter, roomNumber, ':');
        getline(transporter, type, ':');
		getline(transporter, status, ':');
		getline(transporter, stype, ':');
		if(roomNumber.size()<2){
			continue;
		}
		if(type.size()<2){
			continue;
		}
		if((status.size()<2)||((status.compare("vacant")&& (status.compare("occupied"))))){
			continue;
		}
		if(stype.size()<2){
			continue;
		}
        bool isBooked;
        if(status == "vacant"){
            isBooked = 0;
        }else{
            isBooked = 1;
        }
		
        Room *room_obj;
        room_obj =new Room((stoi)(roomNumber),type,isBooked,stype);

        room.emplace_back(room_obj);
        //delete room_obj;

    }
  
}
void Hotel::filereadBooking()
{
    
    ifstream fin("../reports/bookDB.txt");

    while(true)
    {
        string segment;
        if (!getline(fin, segment))
            break;

        stringstream transporter;
        transporter << segment;

        string booking_id;
        string customer_id;
		string cust_first_name;
		string cust_last_name;
		string address;
        string from_date;
        string to_date;
        string no_of_persons;
        getline(transporter, booking_id, ':');
        getline(transporter, customer_id, ':');
        getline(transporter, cust_first_name, ':');
		getline(transporter, cust_last_name, ':');
		getline(transporter, address, ':');
        getline(transporter, from_date, ':');
        getline(transporter, to_date, ':');
        getline(transporter, no_of_persons, ':');

    
       Bookings booking_obj((stoi)(booking_id),cust_first_name,cust_last_name,address,from_date,to_date,(stoi)(no_of_persons),(stoi)(customer_id));

         int bookId=(stoi)(booking_id);
         int custId=(stoi)(customer_id);
         
        bookings[bookId] =booking_obj;
        if(custId!=0){
            
        Customer cust_obj((stoi)(customer_id),cust_first_name,cust_last_name,address,from_date,to_date,(stoi)(no_of_persons));
        cust[custId]= cust_obj;
        }
        

    }
  
}
void Hotel::readCheckOutDB(){
     char filename[ ] = "../reports/checkOut.txt";
     fstream fin2;

     try {
		fin2.open(filename,ios::in);
		if(!fin2.is_open())
			throw ;
	}
	catch(...) {
		cout<<"\n\tError in opening file to read...";
		return;
	}
     while(true)
    {
                
                string segment;
                
              if (!getline(fin2, segment))
                     break;
                     
                
                 int bookId=(stoi)(segment);

                  checkout.push_back(bookId);
                  
    }
                fin2.close();
}
void Hotel::updateCheckOutDB(){
 char filename[ ] = "../reports/checkOut.txt";
        ofstream file_out;
        try {
		file_out.open(filename, std::ios_base::trunc);
		if(!file_out.is_open())
			throw ;
	}
	catch(...) {
		cout<<"\n\tError in opening file to write...";
		return;
	}
        for(int i=0; i<checkout.size(); i++){
            file_out<<checkout[i]<<endl;
        }
        file_out.close();
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
void Hotel::updateRoomDB(){
    string status;
    char filename[ ] = "../reports/roomsfile.txt";
        ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);

    for(auto it=room.begin(); it!=room.end(); it++)
        { 
        if((*it)->getStatus()==0) status ="vacant";
        else status ="occupied";
        file_out <<(*it)->getRoomNumber()<<":"<<(*it)->getType()<<":"<<status<<":"<<(*it)->getStype()<<endl;
        }
        file_out.close();
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
        for(auto it =cust.begin();it!=cust.end(); it++){
            cout<<it->second.getCustomerId()<<" "<<it->second.getCustomerFName()<<" "<<it->second.getCustomerLName()<<" "<<it->second.getCustomerAddress()<<" "<<it->second.getfromDate()<<" "<<it->second.gettoDate()<<" "<<it->second.getnoofPersons()<<endl;
        }
    }
    void Hotel::displayBookingsReports(){
        for(auto it =bookings.begin();it!=bookings.end(); it++){
            cout<<it->second.getbookingId()<<" "<<it->second.getcustomerId()<<" "<<it->second.getfirstName()<<" "<<it->second.getlastName()<<" "<<it->second.getfromDate()<<" "<<it->second.gettoDate()<<" "<<it->second.getnoofPersons()<<endl;
        }
    }
    void Hotel::displayRoomReports(){
        for(auto it = room.begin(); it!=room.end(); it++){
            
cout<<(*it)->getRoomNumber()<<" "<<(*it)->getStatus()<<" "<<" "<<(*it)->getType()<<" "<<(*it)->getStype()<<endl;
            }
    }
    
 
   



