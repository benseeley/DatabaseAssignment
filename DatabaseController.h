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

    int getIdFromConsole();

    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();

    void init();
    void consoleCommand();
    void printAllCommands();
    void findPrintStudent();
    void findPrintFaculty();
    void studentChangeAdvisor();
    void facultyChangeAdvisor();

};




#endif //DATABASEASSIGNMENT_DATABASECONTROLLER_H
