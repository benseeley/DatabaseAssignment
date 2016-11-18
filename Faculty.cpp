//
// Created by creator on 11/9/16.
//

#include "Faculty.h"
#include "json.hpp"

int Faculty::Total_IDS = 0;

Faculty::Faculty() : mID(++Total_IDS) {

}

Faculty::Faculty(string name, string level, string department) : mID(++Total_IDS), mName(name), mLevel(level), mDepartment(department) {

}

//For Dummy Obj
Faculty::Faculty(int id, string name, string level, string department) : mID(id), mName(name), mLevel(level), mDepartment(department){

}

Faculty::Faculty(int id, string name, string level, string department, int* adviseeArr, int adviseeArrLength) : mID(id), mName(name), mLevel(level), mDepartment(department) {

    //Adds advisees
    if(adviseeArr != 0){

        pAdviseesIDS = new vector<int>;
        for (int i = 0; i < adviseeArrLength; ++i) {
            pAdviseesIDS->push_back(*(adviseeArr + i));
        }
    }
}




Faculty::~Faculty() {

}

string Faculty::toString() const {
    string toS = "Type : Faculty, ID : " + to_string(mID) + ",\nLevel : " + mLevel + ",\nDepartement : " + mDepartment + ",\nAdviseesIDS : ";

    //Populates toString with adviseesID's
    for(int i = 0; i < pAdviseesIDS->size(); i++){
        toS += to_string(pAdviseesIDS->at(i));
        toS += ", ";
    }

    return toS;
}

void Faculty::addStudentID(int id){
    //int lastIndex = pAdviseesIDS->size() -1);

    pAdviseesIDS->push_back(id);

}

string Faculty::getJson() const {
    nlohmann::json j;

    j["id"] = mID;
    j["name"] = mName;
    j["level"] = mLevel;
    j["department"] = mDepartment;
    j["numOfAdvisees"] = pAdviseesIDS->size();
    j["adviseesIDS"] = *pAdviseesIDS;



    return j.dump();
}



