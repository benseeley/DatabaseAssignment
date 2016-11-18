//
// Created by creator on 11/9/16.
//

#ifndef JSONOBJSERIALIZE_FACULTY_H
#define JSONOBJSERIALIZE_FACULTY_H

#include <string>
#include <vector>

using namespace std;

class Faculty {
public:
    static int Total_IDS;
    int mID;
    Faculty();

    //Called when constructing for FIRST time, sets id using static var
    Faculty(string name, string level, string department);

    Faculty(int id, string name, string level, string department);

    //Called when constructed from existing data, sets id from data
    Faculty(int id, string name, string level, string department,  int* adviseeArr, int adviseeArrLength);

    ~Faculty();

    //Class Methods
    void addStudentID(int id);
    void removeStudentID(int id);

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
    vector<int>* pAdviseesIDS = new vector<int>;
};


#endif //JSONOBJSERIALIZE_FACULTY_H