//
// Created by Benjamin on 11/16/2016.
//

#ifndef DATABASEASSIGNMENT_DEQUEUE_H
#define DATABASEASSIGNMENT_DEQUEUE_H

#include "DLinkedList.h"

namespace cpsc350
{
    template <typename Elem>
    class Dequeue
    {
    public:
        Dequeue();
        ~Dequeue();
        void insertFront(const Elem& elem) { list_->insertFront(elem); }
        void insertBack(const Elem& elem) { list_->insertBack(elem); }
        void removeFront() { list_->eraseFront(); }
        void removeBack() { list_->eraseBack(); }
        bool empty() { return list_->empty(); }
        int size(){ return list_->size(); }
        Elem& front() { return list_->front(); }
        Elem& back() { return list_->back(); }

    private:
        DLinkedList<Elem>* list_;
    };

    template <typename Elem>
    Dequeue<Elem>::Dequeue()
    {
        list_ = new DLinkedList<Elem>();
    }

    template <typename Elem>
    Dequeue<Elem>::~Dequeue()
    {
        delete list_;
    }
}



#endif //DATABASEASSIGNMENT_DEQUEUE_H
