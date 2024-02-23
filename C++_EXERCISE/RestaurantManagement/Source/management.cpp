#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\RestaurantManagement\Header\management.hpp"

void Table::oder(ManageDish listD){
	Dish Oder = listD.dish();
	array.push_back(Oder);
    SUCCESSFULl 
}

void Table::display() {
    if (array.empty()) {
        FAIL
    } else {
        cout << "Dish List:" << endl;
        for ( auto& dish : array) {
            dish.displayInfo();
        }
    }
}

void Table::cancel(){
    display();
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

void Table::change(ManageDish listD){
    display();
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            Dish Oder = listD.dish();
            *it = Oder;
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
	FAIL   
}

void Table::pay(){
    int money = 0;
    auto it = array.begin();
    while (it != array.end()){
        money += it->getPrice();
        it->displayInfo();
        ++it;
    }
    cout<<"Total:  "<<money<<" VND"<<endl;
}

void Table::setStatus(bool bStatus){
    status = bStatus;
}

 
string Table::getStatus(){
   if(status){
        return "O";
   }
   return "X";
}


void Management::resizeArray(int newSize){
    myArray.resize(newSize);
}
void Management::displayTable(){
    int number = 0;
    system("clear");
    cout<< setw(20)<<left <<"Table Number:";
    for(auto i : myArray){
        cout<< setw(4)<<left <<number;
        number ++;
    }
    cout<<endl;
    cout<< setw(20)<<left <<"Statu:";
    for ( auto i : myArray)
    {
        cout<< setw(4)<<left <<i.getStatus();
    }
    cout<<endl;
    cout<<"X Busy"<<endl;
    cout<<"O Available"<<endl;
}

void Management::editTable(int num, int option,ManageDish listd){
    if (myArray.size() >= num) {
        switch (option)
        {
        case 1:
            myArray[num-1].oder(listd);
        case 2:
            myArray[num-1].cancel();
        case 3:
            myArray[num-1].change(listd);
        case 4:
            myArray[num-1].display();
        case 5:
            myArray[num-1].pay();
        default:
            break;
        }
    }
}