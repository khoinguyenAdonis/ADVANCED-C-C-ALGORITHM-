#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\management.hpp"



/*
Funtion Name: addStudent
Function description : Add add studen to list
Input parameters: NONE
Output: None
*/
void StudentManagement::addStudent(){
    STUDENTIFO
    Student studentInit(name,age,math,physics,chemistry,studentGender);
    studentInit.caculateScore();
    studentInit.classification();
    array.push_back(studentInit);
    cout<<"Them thanh cong"<<endl;
}

/*
Funtion Name: removeStudent
Function description : erase student in list
Input parameters: ID student
Output: None
*/
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

/*
Funtion Name: editStudent
Function description : edit information student in list
Input parameters: ID student
Output: None
*/
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

/*
Funtion Name: arrangeName
Function description : Sort student name in list
Input parameters: NONE
Output: NONE
*/
void StudentManagement::arrangeName() {
        array.sort([]( Student& a,Student& b) {
            return a.Name() < b.Name();
        });

        std::cout << "Students arranged by name." << std::endl;
}

/*
Funtion Name: arrangeScore
Function description : Sort student score in list
Input parameters: NONE
Output: NONE
*/
void StudentManagement::arrangeScore() {
        array.sort([](Student& a,Student& b) {
            return a.getMediumScore()< b.getMediumScore();
        });

        std::cout << "Students arranged by name." << std::endl;
}


/*
Funtion Name: displayStudents
Function description : show list student on terminal
Input parameters: NONE
Output: NONE
*/
void StudentManagement::displayStudents() {
    if (array.empty()) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }

    cout << "Danh sach sinh vien:" << endl;
    for ( auto ST : array) {
        ST.displayIfo();
    }
}

/*
Funtion Name: findStudentById
Function description : Sort student name in list
Input parameters: ID student
Output: NONE
*/
Student* StudentManagement::findStudentById(int studentId) {
    for (auto& student : array) {
        if (student.Id() == studentId) {
            return &student; 
        }
    }
    return nullptr; 
}

/*
Funtion Name: displayStudentById
Function description : show one student by id search name in list
Input parameters: ID student
Output: NONE
*/
void StudentManagement::displayStudentById(int studentId) {
    Student* foundStudent = findStudentById(studentId); // Tìm sinh viên theo ID

    if (foundStudent != nullptr) {
        cout << "Thong tin sinh vien co ID " << studentId << ":" << endl;
        foundStudent->displayIfo(); // Hiển thị thông tin của sinh viên đã tìm thấy
    } else {
        cout << "Khong tim thay sinh vien co ID " << studentId << endl;
    }
}


/*
Funtion Name: saveToCSV
Function description :save list student to file csv
Input parameters: file path
Output: NONE
*/
void StudentManagement::saveToCSV(const string& filename) {
    ofstream outFile(filename); 

    if (outFile.is_open()) { 
        outFile << "ID,Name,Age,Math,Physics,Chemistry,Gender,Classification" << endl;
        for ( auto& student : array) {
            outFile << student.Id() << ","; // ID
            outFile << student.Name() << ","; // Tên
            outFile << student.getAge() << ","; // Tuổi
            outFile << student.getMath() << ","; // Điểm Toán
            outFile << student.getPhysics() << ","; // Điểm Lý
            outFile << student.getChemistry() << ","; // Điểm Hóa
            outFile << student.gender() << ","; // Giới tính
            outFile << student.getClassify(); // Xếp loại
            outFile << endl;
        }

        outFile.close();
        cout << "Danh sach sinh vien da duoc luu vao file " << filename << endl;
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}