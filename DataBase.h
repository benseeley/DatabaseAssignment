//
// Created by Benjamin on 11/16/2016.
//

#ifndef DATABASEASSIGNMENT_DATABASE_H
#define DATABASEASSIGNMENT_DATABASE_H


#include "BinarySearchTree.h"
#include "RingBuffer.h"

using namespace cpsc350;

template <typename Elem>
class DataBase
{
public:
    DataBase(int historySize = 5);
    ~DataBase();
    BinarySearchTree<Elem>* getRollback();
    void backUp(BinarySearchTree<Elem>* tree);
    bool empty() { return treeHistory->empty();}

private:
    RingBuffer<BinarySearchTree<Elem>*>* treeHistory;
};

template <typename Elem>
DataBase<Elem>::DataBase(int historySize)
{
    treeHistory = new RingBuffer<BinarySearchTree<Elem>*>();
}

template <typename Elem>
DataBase<Elem>::~DataBase()
{
    delete treeHistory;
}

template <typename Elem>
BinarySearchTree<Elem> *DataBase<Elem>::getRollback()
{
    BinarySearchTree<Elem>* temp = treeHistory->peek();
    treeHistory->pop();
    return temp;
}

template <typename Elem>
void DataBase<Elem>::backUp(BinarySearchTree<Elem>* tree)
{
    BinarySearchTree<Elem>* newTree = new BinarySearchTree<Elem>(*tree);
    if(treeHistory->full())
    {
        BinarySearchTree<Elem>* temp = treeHistory->back();
        treeHistory->push(tree);
        delete temp;
        return;
    }
    else
    {
        treeHistory->push(tree);
    }
}


#endif //DATABASEASSIGNMENT_DATABASE_H
