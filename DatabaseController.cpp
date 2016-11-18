//
// Created by creator on 11/15/16.
//

#ifndef DATABASEASSIGNMENT_DATABASECONTROLLER_CPP
#define DATABASEASSIGNMENT_DATABASECONTROLLER_CPP
#include "DatabaseController.h"
#include "PeopleSerializable.h"
#include "BinarySearchTree.h"
#include "Sequence.h"
#include "DataBase.h"


using namespace std;

cpsc350::BinarySearchTree<Student>* studentBST = new cpsc350::BinarySearchTree<Student>;
cpsc350::BinarySearchTree<Faculty>* facultyBST = new cpsc350::BinarySearchTree<Faculty>;

DataBase<Student>* studentDataBase = new DataBase<Student>(5);
DataBase<Faculty>* facultyDataBase = new DataBase<Faculty>(5);

DatabaseController::DatabaseController() {}
DatabaseController::~DatabaseController() {}



void DatabaseController::run() {
    init();
    studentDataBase->backUp((new BinarySearchTree<Student>(*studentBST)));
    facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));
    consoleCommand();
}


void DatabaseController::init() {
    bool noFileFlag = true;

    ifstream facStream("facultyTable.txt");
    ifstream studStream("studentTable.txt");

    PeopleSerializable PS;

    cout << "Running init" << endl;

    //Check for file
    if(facStream.good()){
        facStream.close();
        noFileFlag = false;

        cout << "************************************\n"
             << "***Deserializing Faculty into BST***\n"
             << "************************************\n"
             << endl;

        PS.setFile(PeopleSerializable::facultyFile);

        //The library i use to parse serialized data returns a vector array.
        //This is why built in dataStruct is being used
        //Deserialize Faculty Data
        vector<Faculty>* f = PS.deserializeFacultyFromStream();

        //Populate Tree
        for(int i = 0; i < f->size(); i++){
            Faculty& objF = f->at(i);
            facultyBST->insert(objF);

            if(objF.mID > Faculty::Total_IDS){
                Faculty::Total_IDS = objF.mID;
            }
        }

        PS.closeFile();
    }

    //Check for File
    if(studStream.good()){
        studStream.close();
        noFileFlag = false;

        cout << "************************************\n"
             << "***Deserializing Student into BST***\n"
             << "************************************\n"
             << endl;

        PS.setFile(PeopleSerializable::sudentFile);


        //The library i use to parse serialized data returns a vector array.
        //This is why built in dataStruct is being used
        //Deserilize Student Data
        vector<Student>* s = PS.deserializeStudentsFromStream();

        //Populate Tree
        for(int i = 0; i < s->size(); i++){
            Student& objS = s->at(i);
            studentBST->insert(objS);

            if(objS.mID > Student::Total_IDS){
                Student::Total_IDS = objS.mID;
            }
        }

        PS.closeFile();
    }

    if(noFileFlag == true){
        cout << "*No File Found : Blank project created*" << endl;
    }

}

void DatabaseController::serializeBST() {

    PeopleSerializable PS;
    bool noFileFlag = true;

    if(studentBST->size() > 0){
        noFileFlag = false;

        cout << "*Serializing Student BST to *" << endl;

        PS.setFile(PeopleSerializable::sudentFile);

        cpsc350::NodeSequence<Student>* NSPtr = studentBST->toSequence();

        for(int i = 0; i < NSPtr->size(); i++){
            Student& s = *(NSPtr->atIndex(i));
            string toS = s.getJson();
            PS.serializePerson(toS);

        }

        PS.closeFile();
    }

    if(facultyBST->size() > 0){
        noFileFlag = false;

        cout << "*Serializing Faculty BST to *" << endl;

        PS.setFile(PeopleSerializable::facultyFile);

        cpsc350::NodeSequence<Faculty>* NSPtr = facultyBST->toSequence();

        for(int i = 0; i < NSPtr->size(); i++){
            Faculty& s = *(NSPtr->atIndex(i));
            string toS = s.getJson();
            PS.serializePerson(toS);
        }

        PS.closeFile();
    }

    if(noFileFlag == true){
        cout << "*No BST Data Found : Exited without serialization*" << endl;
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
        findPrintStudentAdvisor();
    }
    else if(command == "6"){
        //Given a faculty id, print ALL the names and info of his/her advisees. TODO:@copp
        findPrintFacultyAdvisees();

    }
    else if(command == "7"){
        //Add a new student TODO:CONTACT TEAM MEMBER
        addStudent();
        cout << "test" << endl;
        studentDataBase->backUp((new BinarySearchTree<Student>(*studentBST)));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));

    }
    else if(command == "8"){
        //Delete a student given the id, TODO:CONTACT TEAM MEMBER
        addFaculty();
        studentDataBase->backUp((new BinarySearchTree<Student>(*studentBST)));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));
    }
    else if(command == "9"){
        //Add a new faculty member TODO:CONTACT TEAM MEMBER
        deleteStudent();
        studentDataBase->backUp(new BinarySearchTree<Student>(*studentBST));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));

    }
    else if(command == "10"){
        //Delete a faculty member given the id. TODO:CONTACT TEAM MEMBER
        deleteFaculty();
        studentDataBase->backUp(new BinarySearchTree<Student>(*studentBST));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));

    }
    else if(command == "11"){
        //Change a student’s advisor given the student id and the new faculty id. @TODO:copp
        studentChangeAdvisor();
        studentDataBase->backUp(new BinarySearchTree<Student>(*studentBST));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));

    }
    else if(command == "12"){
        //Remove an advisee from a faculty member given the ids TODO:@copp
        facultyRemoveAdvisee();
        studentDataBase->backUp(new BinarySearchTree<Student>(*studentBST));
        facultyDataBase->backUp(new BinarySearchTree<Faculty>(*facultyBST));
    }
    else if(command == "13"){
        //Rollback TODO:@ben
        facultyBST = facultyDataBase->getRollback();
        studentBST = studentDataBase->getRollback();
    }
    else if(command == "14"){
        //Exit
        cout << "Exiting and Serializing BST" << endl;
        serializeBST();
        return;
    }
    else{
        cout << "Error : Enter a valid command" << endl;
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
    try
    {
        string toS = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0, 0)).toString();
        cout << toS << endl;
    }
    catch (std::logic_error)
    {
        cout << "Student does not exist" << endl;
    }

}

void DatabaseController::findPrintFaculty() {
    cout << "Enter the id of the faculty you would like to display" << endl;
    int id = getIdFromConsole();

    try
    {
        string toS = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class")).toString();
        cout << toS << endl;
    }
    catch (std::logic_error)
    {
        cout << "Faculty does not exist" << endl;
    }

}

void DatabaseController::addStudent() {
    cout << "*Create Student*" << endl;
    cout << "Please use underscore _ to link words with spaces" << endl;
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
    string option = "";

    cin >> option;
    double gpa;

    try{
        gpa = stod(option);
    }
    catch(exception err){
        cout << err.what() << endl;
        throw invalid_argument("Error, invalid integer, exiting program");
    }

    studentBST->insert(Student(name, level, major, gpa));
}

void DatabaseController::addFaculty() {
    cout << "Creating Faculty" << endl;
    cout << "Please use underscore _ to link words with spaces" << endl;

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
    try
    {
        Student& s = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0));

        studentBST->erase(s);
    }
    catch (std::logic_error)
    {
        cout << "Student does not exist" << endl;
    }



}

void DatabaseController::deleteFaculty() {
    cout << "Enter the id of the faculty you would like to DELETE" << endl;
    int id = getIdFromConsole();
    try
    {
        Faculty& f = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

        facultyBST->erase(f);
    }
    catch (std::logic_error)
    {
        cout << "Student does not exist" << endl;
    }


}

void DatabaseController::studentChangeAdvisor() {
    cout << "Enter the id of the students you would like to CHANGE" << endl;
    int studID = getIdFromConsole();

    cout << "Enter this students new advisor id" << endl;
    int newAdvisorID = getIdFromConsole();

    try
    {
        //Search with dummy objects
                Student& s = studentBST->find(Student(studID, "T Name", "T Level", "T Class", 0.0));
                Faculty& f = facultyBST->find(Faculty(newAdvisorID, "T Name", "T Level", "T Class"));


                //Find/Remove old ID
                int oldFacultyID = s.getAdvisorID();
                //Checks to see if faculty exists
                if(oldFacultyID != 0){
                    Faculty& fOld = facultyBST->find(Faculty(oldFacultyID, "T Name", "T Level", "T Class"));
                    fOld.removeStudentID(studID);
                }

                //Change ids
                s.changeAdvisor(newAdvisorID);
                f.addStudentID(studID);
    }
    catch (std::logic_error)
    {
        cout << "Student does not exist" << endl;
    }


}

void DatabaseController::facultyRemoveAdvisee() {
    cout << "Enter the id of the faculty you would like to CHANGE" << endl;
    int facID = getIdFromConsole();

    cout << "\nEnter the id of the advisee you would like to REMOVE";
    int studID = getIdFromConsole();

    try
    {
        //Removes student with id
        facultyBST->find(Faculty(facID, "T Name", "T Level", "T Class")).removeStudentID(studID);

        studentBST->find(Student(studID, "T Name", "T Level", "T Class", 0.0)).changeAdvisor(0);
    }
    catch (std::logic_error)
    {
        cout << "Faculty does not exist" << endl;
    }

}

void DatabaseController::findPrintStudentAdvisor()
{
    cout << "Enter the id of the student you would like to display the advisor of" << endl;
    int id = getIdFromConsole();

    try
    {
        Student student = studentBST->find(Student(id, "T Name", "T Level", "T Class", 0.0, 0));

        int advisorID = student.getAdvisorID();

        string toS = facultyBST->find(Faculty(advisorID, "T Name", "T Level", "T Class")).toString();
        cout << toS << endl;
    }
    catch (std::logic_error)
    {
        cout << "Student does not exist" << endl;
    }

}

void DatabaseController::findPrintFacultyAdvisees()
{
    cout << "Enter the id of the faculty you would like to display the advisees of" << endl;
    int id = getIdFromConsole();

    try
    {
        Faculty faculty = facultyBST->find(Faculty(id, "T Name", "T Level", "T Class"));

        int* studentIDs = faculty.getAdviseeIDs().toArray();

        for(int i = 0; i < faculty.getAdviseeIDs().size(); ++i)
        {
            Student stud = studentBST->find(Student(studentIDs[i], "T Name", "T Level", "T Class", 0.0, 0));
            cout << stud.toString() << endl;
        }
    }
    catch (std::logic_error)
    {
        cout << "Faculty does not exist" << endl;
    }



}


#endif







