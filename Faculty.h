//
// Created by creator on 11/9/16.
//

#ifndef JSONOBJSERIALIZE_FACULTY_H
#define JSONOBJSERIALIZE_FACULTY_H

#include <string>
#include <vector>
#include "Sequence.h"

using namespace std;
using namespace cpsc350;

class Faculty {
public:
    static int Total_IDS;
    int mID;
    Faculty();

    //Called when constructing for FIRST time, sets id using static var
    Faculty(string name, string level, string department);

    Faculty(const Faculty& fac)
    {
        mID = fac.mID;
        mName = fac.mName;
        mLevel = fac.mLevel;
        mDepartment = fac.mLevel;
        pAdviseesIDS = new NodeSequence<int>(*fac.pAdviseesIDS);
    }

    Faculty(int id, string name, string level, string department);

    //Called when constructed from existing data, sets id from data
    Faculty(int id, string name, string level, string department,  int* adviseeArr, int adviseeArrLength);

    ~Faculty();

    //Class Methods
    void addStudentID(int id);
    void removeStudentID(int id);

    NodeSequence<int> getAdviseeIDs() const { return *pAdviseesIDS; }

    //ToString & JSON Methods
    string toString() const;
    string getJson() const;

    friend bool operator==(const Faculty A, const Faculty& B){
        return (A.mID == B.mID);
    };

    friend bool operator<(const Faculty A, const Faculty& B){
        return (A.mID < B.mID);
    };

    friend bool operator>(const Faculty A, const Faculty& B){
        return (A.mID > B.mID);
    };

    friend std::ostream& operator<<(std::ostream& os, const Faculty& obj)
    {
        os << obj.toString();

        return os;
    }
private:
    string mName;
    string mLevel;
    string mDepartment;
    NodeSequence<int>* pAdviseesIDS = new NodeSequence<int>();
};


#endif //JSONOBJSERIALIZE_FACULTY_H