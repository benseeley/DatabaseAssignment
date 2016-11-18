//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_SEQUENCE_H
#define DATABASEASSIGNMENT_SEQUENCE_H

#include "DLinkedList.h"
#include <stdexcept>




namespace cpsc350
{

    template <typename Elem>
    using Iterator = typename DLinkedList<Elem>::DLinkedIterator;

    template <typename Elem>
    class NodeSequence : public DLinkedList<Elem>
    {
    public:
        NodeSequence();
        ~NodeSequence();
        NodeSequence(const NodeSequence<Elem>& seq) : DLinkedList<Elem>(seq)
        {
        }
        Elem* toArray();

        typename DLinkedList<Elem>::DLinkedIterator atIndex(int idx) const; //returns iterator at given index
        int indexOf(const typename DLinkedList<Elem>::DLinkedIterator& p) const; //returns -1 if element not found
        Iterator<Elem> operator[](int idx)
        { return this->atIndex(idx); }
    };

    template <typename Elem>
    NodeSequence<Elem>::NodeSequence() : DLinkedList<Elem>::DLinkedList()
    {}

    template <typename Elem>
    NodeSequence<Elem>::~NodeSequence()
    {
        DLinkedList<Elem>::~DLinkedList();
    }

    template <typename Elem>
    Iterator<Elem> NodeSequence<Elem>::atIndex(int idx) const
    {
        if(idx < 0 || idx >= this->size()) //index is out of range
        {
            throw(std::out_of_range("Index out of range"));
        }

        //determines which end of the list to search from in order to improve performance
        else if(idx < (this->size()/2)) //index is closer to begin()
        {
            Iterator<Elem> pos = this->begin();
            for (int i = 0; i < idx; ++i)
            {
                ++pos;
            }
            return pos;
        }
        else //index is closer to end()
        {
            Iterator<Elem> pos = --this->end();
            for (int i = this->size() - 1; i > idx; --i)
            {
                --pos;
            }
            return pos;
        }

    }

    template <typename Elem>
    int NodeSequence<Elem>::indexOf(const Iterator<Elem> &pos) const
    {
        Iterator<Elem> curr = this->begin();
        int idx = 0;
        while (curr != pos)
        {
            ++curr;
            ++idx;
            if(pos == this->end()) //end of sequence reached without finding value
            {
                return -1;
            }
        }
        return idx;
    }

    template <typename Elem>
    Elem *NodeSequence<Elem>::toArray()
    {
        Elem* temp = new Elem[this->size()];
        for(int i = 0; i < this->size(); ++i)
        {
            temp[i] = this->atIndex(i).operator*();
        }
        return temp;

    }

}

#endif //DATABASEASSIGNMENT_SEQUENCE_H
