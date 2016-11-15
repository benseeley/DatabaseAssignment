//
// Created by creator on 11/12/16.
//

#include "PeopleSerializable.h"



using namespace std;

PeopleSerializable::PeopleSerializable() {
    readStream = new ifstream();
    writeStream = new ofstream();
}

PeopleSerializable::~PeopleSerializable() {
    if(readStream != NULL){
        delete readStream;
        readStream == 0;
    }
    if(writeStream != NULL){
        delete writeStream;
        writeStream == 0;
    }
}

vector<Faculty> *PeopleSerializable::deserializeFacultyFromStream() {
    if(streamFlag == false){
        throw invalid_argument("Stream is has not been set, must set file with \"openFile()\"");
    }
    if(!(readStream->is_open())){
        readStream->open(dataFile.c_str());
    }

    vector<Faculty>* facVector = new vector<Faculty>;
    string line = "";

    while(getline(*readStream, line)){
        if(line != ""){

            facVector->push_back(deserializeFaculty(line));
        }

    }

    //Create Student from Data
    return facVector;
}

vector<Student>* PeopleSerializable::deserializeStudentsFromStream() {

    if(streamFlag == false){
        throw invalid_argument("Stream is has not been set, must set file with \"openFile()\"");
    }
    if(!(readStream->is_open())){
        readStream->open(dataFile.c_str());
    }

    vector<Student>* studVector = new vector<Student>;
    string line = "";

    while(getline(*readStream, line)){
        if(line != ""){

            studVector->push_back(deserializeStudent(line));
        }

    }

    //Create Student from Data
    return studVector;
}

Student PeopleSerializable::deserializeStudent(std::string jString) {
    nlohmann::json j = nlohmann::json::parse(jString);


    //Get Var from JSONObj
    int id = j.at("id");
    string name = j.at("name");
    string level = j.at("level");
    string major = j.at("major");
    double gpa = j.at("gpa");
    int advisorID = j.at("advisorID");

    //Create Student from Data
    return Student(id, name, level, major, gpa, advisorID);
}

Faculty PeopleSerializable::deserializeFaculty(std::string jString) {
    nlohmann::json j = nlohmann::json::parse(jString);


    //Get Var from JSONObj
    int id = j.at("id");
    string name = j.at("name");
    string level = j.at("level");
    string department = j.at("department");

    //TODO: Json is returning bool (since id is 1) insdead of an array of ints;

    int numOfAdvisees = j.at("numOfAdvisees");
    int* adviseeArr = new int[numOfAdvisees];;

    if(0 == numOfAdvisees){
        adviseeArr = 0;
    }
    else if(1 == numOfAdvisees){
        *adviseeArr = j.at("adviseesIDS").back();
    }
    else {
        vector<int> v = j.at("adviseesIDS");;
        for(int i = 0; i < numOfAdvisees; i++){
            *(adviseeArr + i) = v.at(i);
        }
    }

    //Create Student from Data
    return Faculty(id, name, level, department, adviseeArr, numOfAdvisees);
}


//Student & Faculty Serialize Methods
void PeopleSerializable::serializePerson(std::string jString) {
    if(streamFlag == false){
        throw invalid_argument("Stream is has not been set, must set file with \"openFile()\"");
    }
    if(!(writeStream->is_open())){
        cout << dataFile << endl;
        writeStream->open(dataFile.c_str());
    }

    writeStream->write(jString.c_str(), jString.length());
    writeStream->write("\n", 1);
}



void PeopleSerializable::setFile(file inEnum) {
    if(streamFlag == true){
        throw invalid_argument("Error : close file before setting a new one");
    }

    //Enum parsing
    if(inEnum == 0){
        dataFile = STUDENT_FILE;
    }
    else if(inEnum == 1){
        dataFile = FACULTY_FILE;
    }
    else{
        throw invalid_argument("Improper file name, use PeopleSerializable.file ENUM ");
    }

    streamFlag = true;
}

void PeopleSerializable::closeFile() {
    if(streamFlag == false){
        throw invalid_argument("Error : File must be open in order to call \"closeFile\"");
    }
    if(readStream->is_open()){
        readStream->close();
    }
    if(writeStream->is_open()){
        writeStream->close();
    }

    streamFlag = false;
}






/**
 *
 *
 */


