#ifndef __MENU_H__
#define __MENU_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\management.hpp"

#define MENU            system("clear");\
                        cout<<"----------------Student__Management----------------"<<endl;\
                        cout<<"| *CHON CHUC NANG CHUONG TRINH:                   |"<<endl;\
                        cout<<"|>1. THEM SINH VIEN                               |"<<endl;\
                        cout<<"|>2. XOA SINH VIEN                                |"<<endl;\
                        cout<<"|>3. SUA THONG TIN SINH VIEN                      |"<<endl;\
                        cout<<"|>4. SAP XEP SINH VIEN                            |"<<endl;\
                        cout<<"|>5. HIEN THI DANH SACH SINH VIEN                 |"<<endl;\
                        cout<<"|>6. TIM KIEM SINH VIEN                           |"<<endl;\
                        cout<<"|>7. LUU VAO FILE CSV                             |"<<endl;\
                        cout<<"|>0. THOAT CHUONG TRINH                           |"<<endl;\
                        cout<<"---------------------------------------------------"<<endl;\
                        cout<<"   NHAP CHUC NANG CHUONG TRINH: ";\
                        cin>>option;\
                        cout<<"---------------------------------------------------"<<endl;\
                        fflush(stdin);



#define SORTSTUDENT     system("clear");\
                        cout<<"----------------Student__Management----------------"<<endl;\
                        cout<<"| *CHON CHUC NANG CHUONG TRINH:                   |"<<endl;\
                        cout<<"|>1. SAP XEP THEO TEN                             |"<<endl;\
                        cout<<"|>2. SAP XEP THEO DIEM TOAN                       |"<<endl;\
                        cout<<"|>3. SAP XEP THEO DIEM LY                         |"<<endl;\
                        cout<<"|>4. SAP XEP THEO DIEM HOA                        |"<<endl;\
                        cout<<"|>5. SAP XEP THEO DIEM TRUNG BINH                 |"<<endl;\
                        cout<<"|>0. THOAT CHUONG TRINH                           |"<<endl;\
                        cout<<"---------------------------------------------------"<<endl;\
                        cout<<"   NHAP CHUC NANG CHUONG TRINH: ";\
                        cin>>option;\
                        cout<<"---------------------------------------------------"<<endl;\
                        fflush(stdin);

#define SEARCHID        system("clear");\
                        cout<<"NHAP UID SV CAN TIM KIEM: ";\
                        fflush(stdin);\
                        cin>>uid;

#define FILEPATH        student.csv

void menu();
#endif