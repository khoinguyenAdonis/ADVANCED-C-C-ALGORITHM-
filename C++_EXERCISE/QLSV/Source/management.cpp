#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\management.hpp"


void StudentManagement::addStudent(){
    STUDENTIFO
    Student studentInit(name,age,math,physics,chemistry,studentGender);
    studentInit.caculateScore();
    studentInit.classification();
    array.push_back(studentInit);
    cout<<"Them thanh cong"<<endl;
}

void StudentManagement::removeStudent(int studentId) {
    auto it = std::find_if(array.begin(), array.end(), [studentId](const Student& student) {
    return student.Id() == studentId;
});

    if (it != array.end()) {
        array.erase(it);
        std::cout << "Student with ID " << studentId << " removed successfully." << std::endl;
    } else {
        std::cout << "Student with ID " << studentId << " not found." << std::endl;
    }
}

void StudentManagement::editStudent(int studentId) {
        auto it = std::find_if(array.begin(), array.end(), [studentId](const Student& student) {
            return student.Id() == studentId;
        });
        if (it != array.end()) {
        STUDENTIFO        
            it->edit(name,age,math,physics,chemistry,studentGender);
            it->caculateScore();
            it->classification();
            std::cout << "Student with ID " << studentId << " edited successfully." << std::endl;
        } else {
            std::cout << "Student with ID " << studentId << " not found." << std::endl;
        }
}
void StudentManagement::arrangeName() {
        array.sort([]( Student& a,Student& b) {
            return a.Name() < b.Name();
        });

        std::cout << "Students arranged by name." << std::endl;
}
void StudentManagement::arrangeScore() {
        array.sort([](Student& a,Student& b) {
            return a.getMediumScore()< b.getMediumScore();
        });

        std::cout << "Students arranged by name." << std::endl;
}

