//
// Created by creator on 11/15/16.
//

#include "DatabaseController.h"
#include "PeopleSerializable.h"

using namespace std;

void DatabaseController::run() {
    init();


}




void DatabaseController::init() {
    //TODO: Check & Set Students+Faculty from file
    PeopleSerializable streamController;


    //TODO: Populate BST with people arrays @BEN

}

//Main option selector for Database
void DatabaseController::consoleCommand() {
    printAllCommands();

    string command = "";
    cin >> command;

    if(command == "1"){
        //Print all students
        //TODO: Call BST Search Function
    }
    else if(command == "2"){
        //print all faculty
        //TODO: Call BST Search Function
    }
    else if(command == "3"){
        //Display Student (from id)
        findStudent();

    }
    else if(command == "4"){
        //Display Faculty (from id)
        findFaculty();

    }
    else{
        cout << "Error : Enter a valid command" << endl;
        consoleCommand();
    }

}

//"consoleCommand" methods
void DatabaseController::findStudent() {
    cout << "Enter the id of the student you would like to display" << endl;
    string option = "";

    cin >> option;
    int id;

    try{
        id = stoi(option);
    }
    catch(exception err){
        cout << err.what() << endl;
        return;
    }

    //TODO: Search BST for Student

}

void DatabaseController::findFaculty() {
    cout << "Enter the id of the faculty you would like to display" << endl;
    string option = "";

    cin >> option;
    int ID;

    try{
        ID = stoi(option);
    }
    catch(exception err){
        cout << err.what() << endl;
        return;
    }

    //TODO: Search BST for Student
}




void DatabaseController::printAllCommands() {
    cout << "*** Hello User : Enter the numerical value for the command you would like to use***" << endl;

    cout << "1 - Print all students\n"
         << "2 - Print all faculty\n"
         << "3 - Display student info (Using ID)\n"
         << "4 - Display faculty info (Using ID)\n"
         << "5 - Display Advisor info (Using Student ID)\n"
         << "6 - Display all advisees of faculty (Using Faculty ID)\n"
         << "7 - Add a new Student\n"
         << "8 - Add a new Faculty\n"
         << "9 - Delete a student (Using ID)\n"
         << "10 - Delete a faculty (Using ID)\n"
         << "11 - Change a students advisor (Using Student and Faculty ID\n"
         << "12 - Remove an advisee from a faculty member (Using Faculty and Student ID\n"
         << "13 - UNDO\n"
         << "14 - Exit\n";
}




