#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <iostream>
#include <list>

using namespace std;
typedef enum{
    NONE,
    MALE,
    FEMALE
}Gender;

typedef enum{
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
}Rank;


class Student{
    private:
    string name;
    int age;
    int id;
    float math;
    float physics;
    float chemistry;
    float mediumScore ;
    Gender studenGender;
    Rank classify;
    public : 
    Student(string sName = "", int iAge = 0, float fMath = 0, float fPhysics = 0, float fChemistry = 0, Gender Ggender = NONE): 
        name(sName),
        age(iAge),
        math(fMath),
        physics(fPhysics),
        studenGender(Ggender),
        chemistry(fChemistry){
        static int Id = 0;
        Id ++;
        id = Id;
    }
    void caculateScore();
    void classification();
    void edit(string sName, int iAge,  float fMath, float fPhysics, float fChemistry,Gender Gender);
    int Id()const;
    string Name();
    float getMediumScore();
    string gender();
    string getClassify();
    int getAge();
    float getPhysics();
    float getChemistry();
    float getMath();
    void displayIfo();
};


#endif