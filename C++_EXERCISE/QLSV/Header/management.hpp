#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\student.hpp"
#include <algorithm>
#define STUDENTIFO      string name;\
                        int age;\
                        float math;\
                        float physics;\
                        float chemistry;\
                        string gender;\
                        Gender studentGender;\
                        cout<<"Nhap thong tin sinh vien:"<<endl;\
                        cout<<"Ho & ten  : "; getline(cin,name);\
                        fflush(stdin);\
                        cout<<"Tuoi : "; cin>>age;\
                        fflush(stdin);\
                        do\
                        {\
                            cout << "Gioi Tinh  : ";\
                            cin >> gender; \
                            if(gender == "MALE") studentGender = MALE;\
                            else if(gender == "FEMALE") studentGender = FEMALE;\
                        } while (studentGender != MALE );\
                        do\
                        {\
                            fflush(stdin);\
                            cout << "Toan : ";\
                            cin >> math; \
                        } while (math > 10 || math < 0);\
                        do\
                        {\
                            fflush(stdin);\
                            cout << "Ly   : ";\
                            cin >> physics; \
                        } while (physics > 10 || physics < 0);\
                        do\
                        {\
                            fflush(stdin);\
                            cout << "Hoa  : "; \
                            cin >> chemistry; \
                        } while (chemistry > 10 || chemistry < 0);\
                        cin.ignore();




class StudentManagement {
    private:
        list<Student> array;
    public:
        void addStudent();
        void removeStudent(int studentId);
        void editStudent(int studentId);
        void arrangeName();
        void arrangeScore();
};

#endif
