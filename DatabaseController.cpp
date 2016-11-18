//
// Created by creator on 11/15/16.
//

#include "DatabaseController.h"
#include "PeopleSerializable.h"
#include "BinarySearchTree.h"

using namespace std;

cpsc350::BinarySearchTree<Student>* studentBST = new cpsc350::BinarySearchTree<Student>;
cpsc350::BinarySearchTree<Faculty>* facultyBST = new cpsc350::BinarySearchTree<Faculty>;


DatabaseController::DatabaseController() {}
DatabaseController::~DatabaseController() {}

void DatabaseController::run() {
    init();
    consoleCommand();
}


void DatabaseController::init() {
    //TODO: Check & Set Students+Faculty from file
    PeopleSerializable streamController;


    //TODO: Populate BST with people arrays @

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
        //Find and display student information given the students id TODO:@copp
        findPrintStudent();

    }
    else if(command == "4"){
        //Find and display faculty information given the faculty id TODO:@copp
        findPrintFaculty();

    }
    else if(command == "5"){
        //Given a student’s id, print the name and info of their faculty advisor TODO:@copp
        

    }
    else if(command == "6"){
        //Given a faculty id, print ALL the names and info of his/her advisees. TODO:@copp


    }
    else if(command == "7"){
        //Add a new student TODO:CONTACT TEAM MEMBER
        addStudent();

    }
    else if(command == "8"){
        //Delete a student given the id, TODO:CONTACT TEAM MEMBER
        deleteStudent();

    }
    else if(command == "9"){
        //Add a new faculty member TODO:CONTACT TEAM MEMBER
        addFaculty();

    }
    else if(command == "10"){
        //Delete a faculty member given the id. TODO:CONTACT TEAM MEMBER
        deleteFaculty();

    }
    else if(command == "11"){
        //Change a student’s advisor given the student id and the new faculty id. @TODO:copp
        studentChangeAdvisor();

    }
    else if(command == "12"){
        //Remove an advisee from a faculty member given the ids TODO:@copp
        facultyRemoveAdvisee();

    }
    else if(command == "13"){
        //Rollback TODO:@ben


    }
    else if(command == "14"){
        //Exit
        return;
    }
    else{
        cout << "Error : Enter a valid command" << endl;
        consoleCommand();
    }

}

int DatabaseController::getIdFromConsole() {
    string option = "";

    cin >> option;
    int id;

    try{
        id = stoi(option);
    }
    catch(exception err){
        cout << err.what() << endl;
        throw invalid_argument("Error, invalid integer, exiting program");
    }

    return id;
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

void DatabaseController::findPrintStudent() {
    cout << "Enter the id of the student you would like to display" << endl;
    int id = getIdFromConsole();

    Student s = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0, 0));

    s.toString();
}

void DatabaseController::findPrintFaculty() {
    cout << "Enter the id of the faculty you would like to display" << endl;
    int id = getIdFromConsole();

    Faculty f = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

    f.toString();
}

void DatabaseController::addStudent() {
    cout << "Creating Student" << endl;
    cout << "Name : ";
    string name;
    cin >> name;

    cout << "\nLevel : ";
    string level;
    cin >> level;

    cout << "\nMajor : ";
    string major;
    cin >> major;

    cout << "\nGPA : ";
    double gpa;
    cin >> gpa;

    studentBST->insert(Student(name, level, major, gpa));
}

void DatabaseController::addFaculty() {
    cout << "Creating Student" << endl;
    cout << "Name : ";
    string name;
    cin >> name;

    cout << "\nLevel : ";
    string level;
    cin >> level;

    cout << "\nMajor : ";
    string major;
    cin >> major;

    cout << "\nGPA : ";
    double gpa;
    cin >> gpa;

    studentBST->insert(Student(name, level, major, gpa));
}

void DatabaseController::deleteStudent() {
    cout << "Enter the id of the student you would like to DELETE" << endl;
    int id = getIdFromConsole();

    Student s = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0));

    studentBST->erase(s);
}

void DatabaseController::deleteFaculty() {
    cout << "Enter the id of the faculty you would like to DELETE" << endl;
    int id = getIdFromConsole();

    Faculty f = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

    facultyBST->erase(f);
}

void DatabaseController::studentChangeAdvisor() {
    cout << "Enter the id of the student you would like to CHANGE" << endl;

    int id = getIdFromConsole();

    Faculty f = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

    facultyBST->erase(f);
}

void DatabaseController::facultyChangeAdvisor() {
    cout << "Enter the id of the faculty you would like to CHANGE" << endl;
    int facID = getIdFromConsole();

    cout << "\nEnter the id of the advisee you would like to REMOVE";
    int studID = getIdFromConsole();

    Faculty f = facultyBST->find(Faculty(facID, "T Name", "T Level", "T Class"));

    Student s = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0));

    facultyBST->erase(f);
}






