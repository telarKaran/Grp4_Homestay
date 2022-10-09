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
bool status;
public:
Room();
Room(int roomno,string type,bool status,string stype);
void setcustomerId(int custid);
void setRoomNumber(int roomNumber);
void setType(string type);
void setStype(string stype);
void setStatus(bool status);
int getRoomNumber();
string getType();
string getStype();
bool getStatus();
int getCustomerId();
int searchRoom(Room *obj);
void displayRoom(Room *obj);
};

class StdRoom: public Room {
    static int const rent =2500;
    public:
        StdRoom() {
          
        }
        
        int getRent() {
            return this->rent;
        }
};

class Deluxe: public Room {
    static int const rent=3500;
    public:
        Deluxe() {
          
        }
        int getRent() {
            return this->rent;
        }
};

class Cottage: public Room {
    static int const rent=4500;
    public:
        Cottage() {
        }
        
        int getRent() {
            return this->rent;
        }
};