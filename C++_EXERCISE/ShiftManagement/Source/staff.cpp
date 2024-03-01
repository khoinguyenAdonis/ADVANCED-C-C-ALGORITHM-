#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\ShiftManagement\Header\staff.hpp"




int Staff::getId()const{  
    return id;
}


std::string Staff::getName(){
    return name;
}

std::string Staff::getPosition(){
    return position;
}

int Staff::getPhone(){
    return phone;
}

void Staff::display(){
    std::cout<<"Information Staff:"<<std::endl;
    std::cout<<std::setw(6)<<std::left<<"ID";
    std::cout<<std::setw(15)<<std::left<<"NAME";
    std::cout<<std::setw(15)<<std::left<<"PHONE NUMBER";
    std::cout<<std::setw(15)<<std::left<<"POSITION"<<std::endl;
    std::cout<<std::setfill('-');
	std::cout<<std::setw(55)<<"-"<<std::endl;
	std::cout<<std::setfill(' ');
}


void StaffManagement::addStaff(){

}


