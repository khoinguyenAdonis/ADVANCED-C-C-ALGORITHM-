#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\menu.hpp"


/*
Funtion Name: menu
Function description : Select program functions
Input parameters: NONE
Output: None
*/
void menu(){
    StudentManagement listStudent;
    int option;
    int ID;
    int uid; 
    while(1){
        MENU
        switch (option)
        {
        case 1:
            listStudent.addStudent();
            break;
        case 2/* constant-expression */:
            /* code */
            SEARCHID
            listStudent.removeStudent(uid);
            break;
        case 3:
            SEARCHID
            listStudent.editStudent(uid);
            break;
        case 4/* constant-expression */:
            SORTSTUDENT
            switch (option)
            {
            case 1:
                listStudent.arrangeName();
                cout<<"Thanh cong"<<endl;
            case 2:
            case 3:
            case 4:
            case 5:
                listStudent.arrangeScore();
                cout<<"Thanh cong"<<endl;
            case 0:
                /* code */
                break;
            /* code */
            }
            break;
        case 5/* constant-expression */:
            listStudent.displayStudents();
            break;
        case 6:
            SEARCHID
            listStudent.displayStudentById(uid);
            break;
        case 7/* constant-expression */:
            listStudent.saveToCSV(FILEPATH);
            break;
        case 0/* constant-expression */:
            system("clear");
            cout<<"GOOD___BYE"<<endl;
            exit(0);
            break;
        default:
            break;
        }

   }

}