#include <iostream>
#include "Sequence.h"
#include <iostream>


using namespace cpsc350;
using namespace std;

int main()
{
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
}