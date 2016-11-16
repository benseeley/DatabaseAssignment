//
// Created by creator on 11/15/16.
//

#ifndef DATABASEASSIGNMENT_DATABASECONTROLLER_H
#define DATABASEASSIGNMENT_DATABASECONTROLLER_H

#include <iostream>


class DatabaseController {
public:
    void run();
    void consoleCommand();
    void printAllCommands();
    void findStudent();
    void findFaculty();
private:
    //TODO: Add referances to bst
    void init();

};


#endif //DATABASEASSIGNMENT_DATABASECONTROLLER_H
