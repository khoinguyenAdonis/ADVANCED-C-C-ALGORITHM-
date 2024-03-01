
#ifndef   __STAFF_H__
#define   __STAFF_H__

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

#define ENTERSTAFF      system("clear")\
                        std::string newName;\
                        std::string newPosition;\
                        int newPhone;\
                        std::cout<<"Enter New Staff: "<<std::endl;\
                        std::cout<<"Enter Name Staff: ";std::cin>>name;std::cout<<std::endl;\
                        std::cout<<"Enter Phone Staff: ";std::cin>>newPhone;std::cout<<std::endl;\
                        std::cout<<"Enter Positon Staff: ";std::cin>>newPosition;std::cout<<std::endl;

#define SEARCHID        if (array.empty())\
                        cout << "No dishes available to edit." << endl;\
                        int id;\
                        cout << "Enter ID of Staff to edit: ";\
                        cin >> id;


class Staff
{
private:
    std::string name;
    std::string position;
    int id;
    int phone;
public:
    Staff(std::string sName,std::string sPosition,  int iPhone) : 
    name(sName),
    position(sPosition),
    phone(iPhone){
        static int Id;
        Id++;
        id = Id;
    }
    std::string getName();
    std::string getPosition();
    int getId()const;
    int getPhone();
    void display();

};  

class StaffManagement
{
private:
    std::list<Staff> array;
public:
    void addStaff();
    void editStaff();
    void eraseStaff();
    void shiftScheduling();
    void listScheduling();
    void timeWorking();
};




#endif
