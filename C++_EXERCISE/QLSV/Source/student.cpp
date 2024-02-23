#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\student.hpp"

/*
Funtion Name: caculateScore
Function description : caculate student score
Input parameters: NONE
Output: None
*/
void Student::caculateScore(){
    mediumScore = (math+physics+chemistry)/3;
}

/*
Funtion Name: classification
Function description : classification student score
Input parameters: NONE
Output: None
*/
void Student::classification(){
    if (mediumScore >= 8.5) classify = GIOI;
    else if(mediumScore<8.5 &&mediumScore>= 6.5) classify = KHA;
    else if(mediumScore<6.5 &&mediumScore>= 5) classify = TRUNGBINH;
    else classify = YEU;
}

/*
Funtion Name: Id
Function description : get student ID 
Input parameters: NONE
Output: ID 
*/
int Student::Id()const{
    return id;
}

/*
Funtion Name: getMediumScore
Function description : get medium student score  
Input parameters: NONE
Output: Medium Score
*/
float Student::getMediumScore(){
    return mediumScore;
}

/*
Funtion Name: Name
Function description : get student Name  
Input parameters: NONE
Output: student Name  
*/
string Student::Name(){
        return name;
}

/*
Funtion Name: getAge
Function description : get student age
Input parameters: NONE
Output: student age 
*/
int Student::getAge(){
    return age;
}

/*
Funtion Name: gender
Function description : get student gender
Input parameters: NONE
Output: student gender
*/
string Student::gender(){
    if(studenGender == MALE) return "MALE";
    else if(studenGender == FEMALE) return "FEMALE";
    else return "NONE";
}

/*
Funtion Name: getClassify
Function description : get student Classify
Input parameters: NONE
Output: student Classify
*/
string Student::getClassify(){
    if(classify == GIOI) return "GIOI";
    else if(classify == KHA) return "KHA";
    else if(classify == TRUNGBINH) return "TRUNGBINH";
    else return "YEU";
}

/*
Funtion Name: getChemistry
Function description : get student score Chemistry
Input parameters: NONE
Output: student score getChemistry
*/
float Student::getChemistry(){
    return chemistry;
}

/*
Funtion Name: getMath
Function description : get student score Math
Input parameters: NONE
Output: get student score Math
*/
float Student::getMath(){
    return math;
}

/*
Funtion Name: getPhysics
Function description : get student score Physics
Input parameters: NONE
Output: student score Physics
*/
float Student::getPhysics(){
    return physics;
}

/*
Funtion Name: edit
Function description : edit infomation of student
Input parameters: NONE
Output: NONE
*/
void Student::edit(string sName, int iAge, float fMath, float fPhysics, float fChemistry,Gender Gender){
    name = sName;
    age = iAge;
    math = fMath;
    physics = fPhysics;
    chemistry = fChemistry;
    studenGender = Gender;
}

/*
Funtion Name: displayIfo
Function description : show infomation of student
Input parameters: NONE
Output: NONE
*/
void Student::displayIfo(){
    cout<<"ID: "<< Id()<<endl;
    cout<<"TEN: "<< Name()<<endl;
    cout<<"TUOI: "<< getAge()<<endl;
    cout<<"GIOI TINH: "<< gender()<<endl;
    cout<<"TOAN |   LY | HOA"<<endl;
    cout<<getMath()<<"      "<<getPhysics()<<"      "<<getChemistry()<<"        "<<endl;
    cout<<"DIEM TRUNG BINH: "<< getMediumScore()<<endl;
    cout<<"XEP LOAI: "<<getClassify()<<endl;
}
