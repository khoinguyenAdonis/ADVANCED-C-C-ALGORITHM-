#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C++_EXERCISE\QLSV\Header\student.hpp"


void Student::caculateScore(){
    mediumScore = (math+physics+chemistry)/3;
}

void Student::classification(){
    if (mediumScore >= 8.5) classify = GIOI;
    else if(mediumScore<8.5 &&mediumScore>= 6.5) classify = KHA;
    else if(mediumScore<6.5 &&mediumScore>= 5) classify = TRUNGBINH;
    else classify = YEU;
}
int Student::Id()const{
    return id;
}

float Student::getMediumScore(){
    return mediumScore;
}

string Student::Name(){
        return name;
}
int Student::getAge(){
    return age;
}

string Student::gender(){
    if(studenGender == MALE) return "MALE";
    else if(studenGender == FEMALE) return "FEMALE";
    else return "NONE";
}

string Student::getClassify(){
    if(classify == GIOI) return "GIOI";
    else if(classify == KHA) return "KHA";
    else if(classify == TRUNGBINH) return "TRUNGBINH";
    else return "YEU";
}
float Student::getChemistry(){
    return chemistry;
}
float Student::getMath(){
    return math;
}
float Student::getPhysics(){
    return physics;
}

void Student::edit(string sName, int iAge, float fMath, float fPhysics, float fChemistry,Gender Gender){
    name = sName;
    age = iAge;
    math = fMath;
    physics = fPhysics;
    chemistry = fChemistry;
    studenGender = Gender;
}

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