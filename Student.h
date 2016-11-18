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
    int mID;
    Student();

    //Called when constructing for FIRST time, sets id using static var
    Student(string name, string level, string major, double gpa);

    //Called on dummy construction
    Student(int id, string name, string level, string major, double gpa);

    //Called when constructed from existing data, sets id from data
    Student(int id, string name, string level, string major, double gpa, int advisorID);


    ~Student();

    void changeAdvisor(int advisorID);
    void updateAdvisor();

    //Overloaded Operators
    friend bool operator==(const Student A, const Student& B);
    friend bool operator<(const Student A, const Student& B);
    friend bool operator>(const Student A, const Student& B);
    friend std::ostream& operator<<(std::ostream& os, const Student& obj)
    {
        os << obj.toString();

        return os;
    }



    //To strings and json conversion
    const string toString() const;
    virtual string getJson() const;
    ;
private:
    string mName;
    string mLevel;
    string mMajor;
    double mGPA;
    int mAdvisorID;

};




#endif //JSONOBJSERIALIZE_STUDENT_H