#pragma once

#include <cstddef>
#include <deque>



template <typename T>
class FIFOBuffer {

    private:
        size_t size;
        std::deque<T> buffer;

    public:
        FIFOBuffer();
        FIFOBuffer(long initial_size);
        ~FIFOBuffer();

        void push(T elem);
        T& pop();

};



//? Implementations -------------------------------------------------------------------------

template<typename T> FIFOBuffer<T>::FIFOBuffer(){
    this->size = 0;
    this->buffer = std::deque<T>(0);
}

template<typename T> FIFOBuffer<T>::FIFOBuffer(long initial_size){
    this->size = 0;
    this->buffer = std::deque<T>(initial_size);
}

template<typename T> FIFOBuffer<T>::~FIFOBuffer(){
    this->buffer.clear();
}





template<typename T> void FIFOBuffer<T>::push(T elem){
    this->buffer.push_back(elem);
    this->size++;
}

template<typename T> T& FIFOBuffer<T>::pop(){
    T& ret = this->buffer.at(0);
    this->buffer.pop_front();
    this->size--;
    return ret;
}




