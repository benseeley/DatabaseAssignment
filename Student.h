//
// Created by creator on 11/9/16.
//


#ifndef JSONOBJSERIALIZE_STUDENT_H
#define JSONOBJSERIALIZE_STUDENT_H

#include <string>


using namespace std;

class Student{
public:
    static int Total_IDS;
    const int mID;
    Student();

    //Called when constructing for FIRST time, sets id using static var
    Student(string name, string level, string major, double gpa, int advisorID);

    //Called when constructed from existing data, sets id from data
    Student(int id, string name, string level, string major, double gpa, int advisorID);


    ~Student();

    void changeAdvisor(int advisorID);
    void updateAdvisor();

    //Overloaded Operators
    bool operator==(Student& s);
    bool operator<(Student& s);
    bool operator>(Student& s);

    //To strings and json conversion
    string toString();
    virtual string getJson();
    ;
private:
    string mName;
    string mLevel;
    string mMajor;
    double mGPA;
    int mAdvisorID;

};




#endif //JSONOBJSERIALIZE_STUDENT_H