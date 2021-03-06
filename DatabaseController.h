//
// Created by creator on 11/15/16.
//

#ifndef DATABASEASSIGNMENT_DATABASECONTROLLER_H
#define DATABASEASSIGNMENT_DATABASECONTROLLER_H

#include <iostream>
#include "Student.h"
#include "Faculty.h"


class DatabaseController {
public:
    DatabaseController();
    ~DatabaseController();
    void run();



private:
    //TODO: Add referances to bst

    //Structure Commands
    void init();

    void consoleCommand();
    void serializeBST();

    //Helper
    void printAllCommands();
    int getIdFromConsole();

    //Console commands
    void addStudent();
    void addFaculty();
    void deleteStudent();
    void deleteFaculty();

    void findPrintStudent();
    void findPrintFaculty();
    void studentChangeAdvisor();
    void facultyRemoveAdvisee();

    void findPrintStudentAdvisor();
    void findPrintFacultyAdvisees();

};




#endif //DATABASEASSIGNMENT_DATABASECONTROLLER_H
