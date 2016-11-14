//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_STACK_H
#define DATABASEASSIGNMENT_STACK_H

#endif //DATABASEASSIGNMENT_STACK_H

#include "DLinkedList.h"
#include <stdexcept>

namespace cpsc350
{
    template <typename Elem>
    class Stack
    {
    public:
        Stack();
        ~Stack();
        void push(const Elem& e); //pushes a copy of e onto the top of the stack
        void pop() throw(std::logic_error); //removes element from the top of the stack
        Elem& peek() throw(std::logic_error); //returns a reference to the element on the top of the stack
        int size();
        bool empty();

    private:
        int n_; //number of elements
        DLinkedList<Elem> *l_; //list of elements
    };
    template <typename Elem>
    Stack<Elem>::Stack()
    {
        n_ = 0;
        l_ = new DLinkedList<Elem>();
    }

    template <typename Elem>
    Stack<Elem>::~Stack()
    {
        delete l_;
    }

    template <typename Elem>
    void Stack<Elem>::push(const Elem& e)
    {
        l_->insertBack(e);
    }

    template <typename Elem>
    void Stack<Elem>::pop() throw(std::logic_error)
    {
        if(empty())
        {
            throw std::logic_error("Pop from empty stack");
        }
        else
        {
            --n_;
            l_->eraseBack();
        }
    }

    template <typename Elem>
    Elem& Stack<Elem>::peek() throw(std::logic_error)
    {
        if(empty())
        {
            throw std::logic_error("Top of empty stack");
        }
        else
        {
            return --(l_->end());
        }
    }

    template <typename Elem>
    int Stack<Elem>::size()
    {
        return (n_);
    }

    template <typename Elem>
    bool Stack<Elem>::empty()
    {
        return (n_ == 0);
    }




}