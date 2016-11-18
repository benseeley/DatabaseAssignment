//
// Created by creator on 11/9/16.
//

#include "Student.h"
#include "json.hpp"

int Student::Total_IDS = 0;


Student::Student() : mID(++Total_IDS) {

}

Student::~Student() {

}

Student::Student(string name, string level, string major, double gpa, int advisorID) : mID(++Total_IDS), mName(name), mLevel(level), mMajor(major), mGPA(gpa), mAdvisorID(advisorID){

}

//Sets id from data
Student::Student(int id, string name, string level, string major, double gpa, int advisorID) : mID(id), mName(name), mLevel(level), mMajor(major), mGPA(gpa), mAdvisorID(advisorID){
    //Make sure Total_IDS is global max
    if(Total_IDS < id){
        Total_IDS = id;
    }
}

void Student::changeAdvisor(int advisorID) {
    mAdvisorID = advisorID;
}

void Student::updateAdvisor() {
    //Find advisor by id and update its vecor array
}


const string Student::toString() const {
    string toS = "Type : Student, ID : " + to_string(mID) + "\nName : " + mName + ",\nLevel : " + mLevel + ",\nMajor : " + mMajor + ",\nGPA : " + to_string(mGPA) + ",\nAdvisor : " + to_string(mAdvisorID);
    return toS;
}

std::string Student::getJson() const {
    nlohmann::json j;
    j["id"] = mID;
    j["name"] = mName;
    j["level"] = mLevel;
    j["major"] = mMajor;
    j["gpa"] = mGPA;
    j["advisorID"] = mAdvisorID;

    return j.dump();
}


//**Operator Overloads**


bool operator==(const Student A, const Student& B) {
    return (A.mID == B.mID);
}

bool operator<(const Student A, const Student &B) {
    return (A.mID < B.mID);
}

bool operator>(const Student A, const Student &B) {
    return (A.mID > B.mID);
}





