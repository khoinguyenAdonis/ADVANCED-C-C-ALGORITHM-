#ifndef __MENU_H__
#define __MENU_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\RestaurantManagement\Header\management.hpp"

#define MENU            system("clear");\
                        cout<<"----------------Restaurent__Management----------------"<<endl;\
                        cout<<"| *Choose program funtion:                           |"<<endl;\
                        cout<<"|>1. Management                                      |"<<endl;\
                        cout<<"|>2. Staff                                           |"<<endl;\
                        cout<<"---------------------------------------------------"<<endl;\
                        cout<<"   Input choose program funtion: ";\
                        cin>>option;\
                        cout<<"---------------------------------------------------"<<endl;\
                        fflush(stdin);



#define MANAGEMENT      system("clear");\
                        cout<<"----------------MANAGEMENT------------------------"<<endl;\
                        cout<<"| *Choose program funtion:                        |"<<endl;\
                        cout<<"|>1. Setup table number                           |"<<endl;\
                        cout<<"|>2. Addition dish                                |"<<endl;\
                        cout<<"|>3. Edit dish                                    |"<<endl;\
                        cout<<"|>4. Erase dish                                   |"<<endl;\
                        cout<<"|>5. Dish list                                    |"<<endl;\
                        cout<<"|>0. Exit                                         |"<<endl;\
                        cout<<"---------------------------------------------------"<<endl;\
                        cout<<"   Input choose program funtion: ";\
                        cin>>option;\
                        cout<<"---------------------------------------------------"<<endl;\
                        fflush(stdin);

#define OPTION          system("clear");\
                        cout<<"--------------------------------------------------"<<endl;\
                        cout<<"| *Choose program funtion:                        |"<<endl;\
                        cout<<"|>1. Oder food                                    |"<<endl;\
                        cout<<"|>2. Cancel oder                                  |"<<endl;\
                        cout<<"|>3. Change oder                                  |"<<endl;\
                        cout<<"|>4. List of ordered dishes                       |"<<endl;\
                        cout<<"|>5. Pay                                          |"<<endl;\
                        cout<<"|>0. Exit                                         |"<<endl;\
                        cout<<"---------------------------------------------------"<<endl;\
                        cout<<"   Input choose program funtion: ";\
                        cin>>option;\
                        cout<<"---------------------------------------------------"<<endl;\
                        fflush(stdin);

#define TABLENUMBER     system("clear");\
                        cout<<"Setup table number"<<endl;\
                        cout<<"Enter table number: ";\
                        cin >> option;
#define CHOOSETABLE     cout<<"Chon ban: ";\
                        cin>>numTable;\
                        cout<<endl;
void menu();
#endif