#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
using namespace std;

#define MANAGEMENT          system("clear");\
                            cout<<"________________________________________"<<endl;\
                            cout<<"|_____________MANAGEMENT_______________|"<<endl;\
                            cout<<"| 1>Staff Management                   |"<<endl;\
                            cout<<"| 2>Room Management                    |"<<endl;\
                            cout<<"| 3>Service                            |"<<endl;\
                            cout<<"| 0>Exit                               |"<<endl;\
                            cout<<"|______________________________________|"<<endl;\
                            cout<<"  Enter option:"; cin>>option;

#define STAFF               system("clear");\
                            cout<<"________________________________________"<<endl;\
                            cout<<"|__________STAFF-MANAGEMENT____________|"<<endl;\
                            cout<<"| 1>Addition Staff                     |"<<endl;\
                            cout<<"| 2>Edit Information Staff             |"<<endl;\
                            cout<<"| 3>Erase Staff                        |"<<endl;\
                            cout<<"| 4>Shift Scheduling                   |"<<endl;\
                            cout<<"| 5>List Information Staff             |"<<endl;\
                            cout<<"| 6>Time Working                       |"<<endl;\
                            cout<<"| 0>Exit                               |"<<endl;\
                            cout<<"|______________________________________|"<<endl;\
                            cout<<"  Enter option:"; cin>>option;


#define ROOM                system("clear");\
                            cout<<"________________________________________"<<endl;\
                            cout<<"|__________ROOM-MANAGEMENT_____________|"<<endl;\
                            cout<<"| 1>Addition Room                      |"<<endl;\
                            cout<<"| 2>Erase Room                         |"<<endl;\
                            cout<<"| 3>Room Status                        |"<<endl;\
                            cout<<"| 0>Exit                               |"<<endl;\
                            cout<<"|______________________________________|"<<endl;\
                            cout<<"  Enter option:"; cin>>option;

#define SERVICE             system("clear");\
                            cout<<"________________________________________"<<endl;\
                            cout<<"|______________SERVICE_________________|"<<endl;\
                            cout<<"| 1>Food And Drink                     |"<<endl;\
                            cout<<"| 2>Pool                               |"<<endl;\
                            cout<<"| 3>Gym                                |"<<endl;\
                            cout<<"| 4>Laundry                            |"<<endl;\                         
                            cout<<"| 0>Exit                               |"<<endl;\
                            cout<<"|______________________________________|"<<endl;\
                            cout<<"  Enter option:"; cin>>option;

                

void menu();


#endif