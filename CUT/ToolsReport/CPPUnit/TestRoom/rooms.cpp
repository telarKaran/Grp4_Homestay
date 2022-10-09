#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
#include "rooms.h"

int Room::searchRoom(vector<Room>&room,int roomNo) {
    int n = roomNo;
    for(auto it=room.begin(); it!=room.end();  it++) {
        //char jj 
        int j = it->getRoomNumber();
        if(j == n) {
            if(it->getStatus() == "vacant") {
                return 0;//meaning Vacant
            }
            else {
                return 1;
            }
        }
    }
    return -1;
}
void Room:: editRoom(vector<Room>&room) {
    cout<<"Enter the Room Number ";
    int n,s;
    cin>>n;
    cout<<"Enter 1->to book the room for maintanace & 0->make available";
    cin>>s;
    for( auto it=room.begin(); it!=room.end();  it++) {
        int j = it->getRoomNumber();
        if(j == n) {
        
        it->setStatus(s);
           
        }
    }
}
void Room:: displayRoom(vector<Room>&room) 
{
    for(auto it =room.begin() ;it!=room.end(); it++)
    {
        cout<<it->getRoomNumber()<<" "<<it->getType()<<""<<it->getStatus()<<" "<<it->getStype()<<endl;
    }

}

