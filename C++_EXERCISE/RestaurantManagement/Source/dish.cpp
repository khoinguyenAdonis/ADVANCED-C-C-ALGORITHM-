#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\RestaurantManagement\Header\dish.hpp"

int Dish::getId()const{
    return id;
}

string Dish::getName(){
    return name;
}

int Dish::getPrice(){
    return price;
}

void Dish::displayInfo(){
    cout<<"Infomation:  "<<endl;
    cout << setw(5) << left << "ID";
	cout << setw(30) << left << "NAME";
	cout << setw(20) << right << "PRICE" << endl;
	cout << setfill('-');
	cout << setw(55) << "-" << endl;
	cout << setfill(' ');	
	cout << setw(5) << left << getId();
	cout << setw(30) << left << getName();
	cout << setw(20) << right << getPrice<< endl;
}

void ManageDish::addDish() {
    INPUTDISH
	Dish newDish(name, price);
    array.push_back(newDish);
    SUCCESSFULl
}

void ManageDish::displayDish() {
    if (array.empty()) {
        FAIL
    } else {
        cout << "Dish List:" << endl;
        for ( auto& dish : array) {
            dish.displayInfo();
        }
    }
}

void ManageDish::editDish() {
	SEARCHID
    bool found = false;
    for (auto& dish : array) {
        if (dish.getId() == id) {
            INPUTDISH            
            dish = Dish(name, price);
            found = true;
            SUCCESSFULl
            break;
        }
    }
    
    if (!found) {
        FAIL
    }
}

void ManageDish::eraseDish() {
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            it = array.erase(it);
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
	FAIL
}
Dish ManageDish::dish(){
	SEARCHID
	auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            SUCCESSFULl
            return *it;
        } else {
            ++it;
        }
    }
	FAIL
}


