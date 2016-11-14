//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_RINGBUFFER_H
#define DATABASEASSIGNMENT_RINGBUFFER_H

#endif //DATABASEASSIGNMENT_RINGBUFFER_H

namespace cpsc350
{
    template <typename T>
    class RingBuffer
    {
    public:
        RingBuffer(int size = 5);
        ~RingBuffer();
        void push(T elem);
        void pop();
        void peek();

    private:
        int capacity_;
        int num_elements_;
        T data_array_;
    };
}
