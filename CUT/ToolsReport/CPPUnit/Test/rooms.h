#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Room 
{
int roomNumber;
int customer_id;
string type;
string stype;
string status;
public:
 Room(){}
  Room(int roomno,string type,string status,string stype){
 this->roomNumber=roomno;
 this->type =type;
 this->stype =stype;
 this->status =status;
}
void setcustomerId(int custid){
this->customer_id =custid;
}

void setRoomNumber(int roomNumber)
{
  this->roomNumber=roomNumber;
}

void setType(string type)
{
  this->type= type;
}

void setStype(string stype)
{
  this->stype = stype;
}

void setStatus(bool status)
{
  this->status = status;
}

int getRoomNumber()
{
  return roomNumber;
}

string getType()
{
  return type;
}

string getStype()
{
  return stype;
}

string getStatus()
{
  return status;
}
void display(){
            
  cout<<"\nroom no: "<<this->roomNumber<<endl;
  cout<<"\ntype: "<<this->type<<endl;
  cout<<"\nstype : "<<this->stype<<endl;
  cout<<"\nstatus: "<<this->status<<endl;
}
//void setoomNumber
int searchRoom(vector<Room>&room,int);
void editRoom(vector<Room>&room);
void displayRoom(vector<Room>&room);
//setRoomdetails(roomnumber,status,type);
};