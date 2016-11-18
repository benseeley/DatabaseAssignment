//
// Created by creator on 11/15/16.
//

#include "DatabaseController.h"
#include "PeopleSerializable.h"
#include "BinarySearchTree.h"
#include "Sequence.h"

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
    ifstream facStream("masterFaculty.txt");
    ifstream studStream("masterStudent.txt");

    PeopleSerializable PS;

    //Check for file
    if(facStream.good()){
        facStream.close();

        PS.setFile(PeopleSerializable::sudentFile);

        //Deserialize Faculty Data
        vector<Faculty>* f = PS.deserializeFacultyFromStream();

        //Populate Tree
        for(int i = 0; i < f->size(); i++){
            facultyBST->insert(f->at(i));
        }

        PS.closeFile();
    }

    //Check for File
    if(studStream.good()){
        studStream.close();

        PS.setFile(PeopleSerializable::sudentFile);


        //Deserilize Student Data
        vector<Student>* s = PS.deserializeStudentsFromStream();

        //Populate Tree
        for(int i = 0; i < s->size(); i++){
            studentBST->insert(s->at(i));
        }

        PS.closeFile();
    }

}

void DatabaseController::serializeBST() {

    PeopleSerializable PS;

    if(studentBST->size() > 0){

        PS.setFile(PeopleSerializable::sudentFile);

        cpsc350::NodeSequence<Student>* NSPtr = studentBST->toSequence();

        for(int i = 0; i < NSPtr->size(); i++){
            Student& s = *(NSPtr->atIndex(i));
            string toS = s.toString();
            PS.serializePerson(toS);
        }

        PS.closeFile();
    }

    if(facultyBST->size() > 0){

        PS.setFile(PeopleSerializable::facultyFile);

        cpsc350::NodeSequence<Faculty>* NSPtr = facultyBST->toSequence();

        for(int i = 0; i < NSPtr->size(); i++){
            Faculty& s = *(NSPtr->atIndex(i));
            string toS = s.toString();
            PS.serializePerson(toS);
        }

        PS.closeFile();
    }

    //TODO: Populate BST with people arrays @
}


//Main option selector for Database
void DatabaseController::consoleCommand() {
    printAllCommands();

    string command = "";
    cin >> command;

    if(command == "1"){
        studentBST->inOrderPrint();
        //TODO: Call BST Search Function
    }
    else if(command == "2"){
        facultyBST->inOrderPrint();
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
        addFaculty();
    }
    else if(command == "9"){
        //Add a new faculty member TODO:CONTACT TEAM MEMBER
        deleteStudent();

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
    consoleCommand();
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
    cout << "\n\n*** Hello User : Enter the numerical value for the command you would like to use***" << endl;

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

    string toS = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0, 0)).toString();
    cout << toS << endl;
}

void DatabaseController::findPrintFaculty() {
    cout << "Enter the id of the faculty you would like to display" << endl;
    int id = getIdFromConsole();

    string toS = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class")).toString();
    cout << toS << endl;
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
    cout << "Creating Faculty" << endl;
    cout << "Name : ";
    string name;
    cin >> name;

    cout << "Level : ";
    string level;
    cin >> level;

    cout << "Department : ";
    string department;
    cin >> department;

    facultyBST->insert(Faculty(name, level, department));
}

void DatabaseController::deleteStudent() {
    cout << "Enter the id of the student you would like to DELETE" << endl;
    int id = getIdFromConsole();

    Student& s = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0));

    studentBST->erase(s);
}

void DatabaseController::deleteFaculty() {
    cout << "Enter the id of the faculty you would like to DELETE" << endl;
    int id = getIdFromConsole();

    Faculty& f = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

    facultyBST->erase(f);
}

void DatabaseController::studentChangeAdvisor() {
    cout << "Enter the id of the students you would like to CHANGE" << endl;
    int studID = getIdFromConsole();

    cout << "Enter this students new advisor id" << endl;
    int advisorID = getIdFromConsole();

    //Checks to see if faculty exists
    facultyBST->find(Faculty(advisorID, "T Name", "T Level", "T Class")).addStudentID(studID);

    //Find dummy obj with ID
    studentBST->find(Student(studID, "T Name", "T Level", "T Class", 0.0)).changeAdvisor(advisorID);
}

void DatabaseController::facultyRemoveAdvisee() {
    cout << "Enter the id of the faculty you would like to CHANGE" << endl;
    int facID = getIdFromConsole();

    cout << "\nEnter the id of the advisee you would like to REMOVE";
    int studID = getIdFromConsole();

    //Removes student with id
    facultyBST->find(Faculty(facID, "T Name", "T Level", "T Class")).removeStudentID(studID);

    studentBST->find(Student(studID, "T Name", "T Level", "T Class", 0.0)).changeAdvisor(0);
}