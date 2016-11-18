//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_RINGBUFFER_H
#define DATABASEASSIGNMENT_RINGBUFFER_H

#endif //DATABASEASSIGNMENT_RINGBUFFER_H

#include "Dequeue.h"

namespace cpsc350
{
    template <typename Elem>
    class RingBuffer
    {
    public:
        RingBuffer(int size = 5);
        ~RingBuffer();
        void push(Elem& elem);
        void pop() throw(std::logic_error);
        Elem& peek() throw(std::logic_error);
        bool full();

    private:
        int capacity_;
        int num_elements_;
        Dequeue *queue;
    };

    template <typename Elem>
    RingBuffer::RingBuffer(int size)
    {
        capacity_ = size;
        num_elements_ = 0;
        queue = new Dequeue<Elem>();
    }

    template <typename Elem>
    RingBuffer::~RingBuffer()
    {
        delete queue;
    }

    template <typename Elem>
    void RingBuffer::push(Elem& elem)
    {
        if(num_elements_ < capacity_)
        {
            queue->insertBack(elem);
            num_elements_++;
        }
        else
        {
            queue->removeFront();
            queue->insertBack(elem);
        }
    }

    template <typename Elem>
    void RingBuffer::pop() throw(std::logic_error)
    {
        queue->removeFront();
    }

    template <typename Elem>
    Elem& RingBuffer::peek() throw(std::logic_error)
    {
        queue->front();
    }

    bool RingBuffer::full()
    {
        return (num_elements_ == capacity_);
    }
}
