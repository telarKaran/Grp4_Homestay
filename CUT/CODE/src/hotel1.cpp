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

 if(words==5){return 1;}else{return 0;}
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
        string customer_id;
		string line;
		getline(fin2,line);

		if(!checkValidity(line)){continue;}
        getline(transporter, roomNumber, ':');
        getline(transporter, type, ':');
		getline(transporter, status, ':');
		getline(transporter, stype, ':');
        getline(transporter,customer_id,':');
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
        room_obj =new Room((stoi)(roomNumber),type,isBooked,stype,(stoi)(customer_id));

        room.emplace_back(room_obj);
        //delete room_obj;

    }
  
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
void Hotel::updateCheckInDB(){
 char filename[ ] = "../reports/checkIn.txt";
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
        for(int i=0; i<check_in.size(); i++){
            file_out<<check_in[i]<<endl;
        }
        file_out.close();
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
void Hotel::readCheckInDB(){
     char filename[ ] = "../reports/checkIn.txt";
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

                  check_in.push_back(bookId);
                  
    }
                fin2.close();
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
        file_out <<(*it)->getRoomNumber()<<":"<<(*it)->getType()<<":"<<status<<":"<<(*it)->getStype()<<":"<<(*it)->getCustomerId()<<endl;
        }
        file_out.close();
}
void Hotel::checkIn(){
     system("clear");
     int booking_id,CustomerId,choice,key;
     string room_type,stype;

     cout<<"\nEnter booking id";
     cin>>booking_id;
     bool flag=0,flag1=0;
     
   if(!noofAvailableRooms()){
       cout<<"No rooms are available";
       return;
    }
        //traverse the bookings map  to get the customer details for the booking id
               auto it =bookings.find(booking_id);
               for(int i=0; i<checkout.size(); i++ ){
                      if(checkout[i]==booking_id){
                         flag1=1;
                      }
               }
               for(int i=0; i<check_in.size(); i++ ){
                      if(check_in[i]==booking_id){
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
            

                cout<<"\t.Enter the room type to stay in"<<endl;
                cout<<"Enter 1 to Standard "<<endl;
                cout<<"Enter 2 to Delux"<<endl;
                cout<<"Enter 3 to cottage"<<endl;
                cout<<"Enter choice"<<endl;
                cin>>choice;
                switch(choice){
                    case 1: 
                         room_type="standard";
                    break;
                    case 2:
                        room_type="delux";
                    break;
                    case 3:
                       room_type ="cottage";
                    break;
                    default:
                       cout<<"Enter valid choice"<<endl;
                     
                }
                
               if(room_type!="standard" && room_type!="delux" && room_type!="cottage"){
                    cout<<"Please choose valid room type"<<endl;
                    return;
                }
               else 
                {
                    for(auto itr=room.begin(); itr!=room.end();itr++)
                    {
                       if((*itr)->getStatus()== 0 && (*itr)->getType()==room_type)
                        {
                           (*itr)->setcustomerId(CustomerId);
                           bool k=1;
                           (*itr)->setStatus(k);
                           cout<<"\nCustomer CheckedIn Successfully"<<endl;
                           flag1=1;
                           updateCustomerDB();
                           break;
                        }
                        
                    }
                    if(flag1==0){
                      cout<<"\nThe entered room type is not available currently"<<endl;
                    }
                }
          
              fstream file_out;
              file_out.open("../data/stat2.txt");
              file_out<<CustomerId;
             file_out.close();
             check_in.push_back(booking_id);
             
    }
else{
               cout<<"\nEnter correct booking_id"<<endl;
               cout<<"\n press any key to do booking again"<<endl;
               cin>>key;
            }
}
    