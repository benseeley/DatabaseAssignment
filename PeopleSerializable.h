//
// Created by creator on 11/12/16.
//

#ifndef JSONOBJSERIALIZE_PEOPLESERIALIZABLE_H
#define JSONOBJSERIALIZE_PEOPLESERIALIZABLE_H

#include <string>
#include "fstream"
#include "json.hpp"
#include "Student.h"
#include "Faculty.h"

using namespace std;

//Dec;are for compiler
class Student;


class PeopleSerializable {
private:
    std::string dataFile;

    const string STUDENT_FILE = "studentTable.txt";
    const string FACULTY_FILE = "facultyTable.txt";

    bool streamFlag = false;
    std::ifstream* readStream;
    std::ofstream* writeStream;

public:
    PeopleSerializable();
    ~PeopleSerializable();


    vector<Faculty>* deserializeFacultyFromStream();
    vector<Student>* deserializeStudentsFromStream();

    //Extra overloaded method (for testing)
    Student deserializeStudent(std::string jString);
    Faculty deserializeFaculty(std::string jString);

    void serializePerson(std::string jString);

    enum file {sudentFile = 0, facultyFile = 1};

    bool streamNotNull() {return (streamFlag == true);}
    bool streamIsNull() {return (streamFlag == false);}

    void setFile(file mEnum);
    void closeFile();

};


#endif //JSONOBJSERIALIZE_PEOPLESERIALIZABLE_H