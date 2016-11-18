#include <iostream>
#include "Sequence.h"
#include "PeopleSerializable.h"
#include "BinarySearchTree.h"
#include "bst_test.h"
#include <iostream>


using namespace cpsc350;
using namespace std;

int main()
{


}




//FACULTY TESTS (DOES : Serialize, Deserialize, json, multiple/no advisees
/**
Faculty f1("Steve", "Instructor", "Com Sci");;

Faculty f2("Steve", "Instructor", "Com Sci");
f2.addStudentID(10);

Faculty f3("Steve", "Instructor", "Com Sci");
f3.addStudentID(10);
f3.addStudentID(11);
f3.addStudentID(12);
f3.addStudentID(13);
f3.addStudentID(14);
f3.addStudentID(15);

PeopleSerializable p;

//*** Must Set File Before use
p.setFile(PeopleSerializable::facultyFile);


p.serializePerson(f1.getJson());
p.serializePerson(f2.getJson());
p.serializePerson(f3.getJson());

//*** Must Close file before beginning new io Action
p.closeFile();


p.setFile(PeopleSerializable::facultyFile);
vector<Faculty>* fVec = p.deserializeFacultyFromStream();
p.closeFile();

for(int i = 0; i < fVec->size(); i++){
    cout << fVec->at(i).toString() << endl;
}
**/



//BENS TEST (Does : IDK)
/**
std::cout << "Hello, World!" << std::endl;
DLinkedList<int> *list2 = new DLinkedList<int>();

NodeSequence<int> *seq = new NodeSequence<int>();

seq->insertFront(3);
seq->insertFront(5);
seq->insertFront(54);
seq->insertFront(7);
seq->insertFront(23);

for(int i = 0; i < seq->size(); ++i)
{
    cout << *(*seq)[i] << endl;

}

cout << "==============" << endl;

seq->eraseBack();
seq->eraseBack();
seq->eraseBack();



for(int i = 0; i < seq->size(); ++i)
{
    cout << *(*seq)[i] << endl;

}



DLinkedList<int> *list = new DLinkedList<int>();
list->insertFront(0);
list->insertFront(1);
list->insertFront(1);
list->insertFront(2);
list->insertFront(3);
list->insertFront(5);
list->insertFront(8);





for(DLinkedList<int>::Iterator b = list->begin(); b != list->end(); ++ b)
{
    cout << *b << endl;
}

delete list;
delete seq;
return 0;

 **/