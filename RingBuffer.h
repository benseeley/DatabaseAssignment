//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_RINGBUFFER_H
#define DATABASEASSIGNMENT_RINGBUFFER_H

#endif //DATABASEASSIGNMENT_RINGBUFFER_H

namespace cpsc350
{
    template <typename Elem>
    class RingBuffer
    {
    public:
        RingBuffer(int size = 5);
        ~RingBuffer();
        void push(Elem elem);
        void pop();
        Elem& peek();
        bool full();

    private:
        int capacity_;
        int num_elements_;
        int head;
        int tail;
        Elem* data_array;
        int getHead();
        int getTail();
    };

    template <typename Elem>
    RingBuffer::RingBuffer(int size)
    {
        data_array = new Elem[size];
        capacity_ = size;
        num_elements_ = 0;
    }

    template <typename Elem>
    RingBuffer::~RingBuffer()
    {
        delete data_array;
    }

    template <typename Elem>
    void RingBuffer::push(Elem elem)
    {
        if(full())
        {
            data_array[(head++) % (capacity_-1)] = elem;
        }
        else
        {
            data_array[(head++) % (capacity_-1)] = elem;
            num_elements_++;
        }
    }

    template <typename Elem>
    void RingBuffer::pop()
    {

    }

    template <typename Elem>
    Elem& RingBuffer::peek()
    {

    }

    bool RingBuffer::full()
    {
        return (num_elements_ == capacity_);
    }
}
