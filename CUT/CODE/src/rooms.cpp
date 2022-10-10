#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
#include "../header/rooms.h"
Room::Room(int roomno,string type,bool status,string stype,int customer_id){
 this->roomNumber=roomno;
 this->type =type;
 this->stype =stype;
 this->status =status;
 this->customer_id=customer_id;
}
void Room::setcustomerId(int custid){
this->customer_id =custid;
}

void Room::setRoomNumber(int roomNumber)
{
  this->roomNumber=roomNumber;
}

void Room::setType(string type)
{
  this->type= type;
}

void Room::setStype(string stype)
{
  this->stype = stype;
}

void Room::setStatus(bool status)
{
  this->status = status;
}

int Room::getRoomNumber()
{
  return roomNumber;
}

string Room::getType()
{
  return type;
}

string Room::getStype()
{
  return stype;
}

bool Room::getStatus()
{
  return status;
}
int Room::getCustomerId(){
  return customer_id;
}

int Room::searchRoom(Room *obj) {
            if(obj->getStatus() == 0) {
                return 0;//meaning Vacant
            }
            else {
                return 1;
            }
return -1;
    }

void Room:: displayRoom(Room *obj) 
{
    
cout<<obj->getRoomNumber()<<" "<<obj->getType()<<""<<obj->getStatus()<<" "<<obj->getStype()<<endl;

}

