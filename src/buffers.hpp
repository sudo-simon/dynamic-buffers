#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

/*
    FIFO buffer class
*/
template <typename T>
class FIFOBuffer {

    private:
        size_t size;
        long capacity;
        long push_i;
        long pop_i;
        std::vector<T> buffer;

    public:
        FIFOBuffer();
        FIFOBuffer(long initial_capacity);
        ~FIFOBuffer();

        size_t getSize();
        long getCapacity();
        T at(long index);

        void push(T elem);
        void pop(T* ret_pointer);

};






















//? Start of FIFO buffer implementations -------------------------------------------------------------------------

template<typename T> FIFOBuffer<T>::FIFOBuffer(){
    this->size = 0;
    this->capacity = 1;
    this->push_i = -1;
    this->pop_i = -1;
    this->buffer = std::vector<T>();
    this->buffer.reserve(1);
}

template<typename T> FIFOBuffer<T>::FIFOBuffer(long initial_capacity){
    if (initial_capacity <= 0){
        std::cerr << "FIFOBuffer ERROR: initial_capacity was not a positive long int" <<std::endl;
        std::exit(1);
    }

    this->size = 0;
    this->capacity = initial_capacity;
    this->push_i = -1;
    this->pop_i = -1;
    this->buffer = std::vector<T>();
    this->buffer.reserve(initial_capacity);
}

template<typename T> FIFOBuffer<T>::~FIFOBuffer(){
    this->buffer.clear();
}





template<typename T> size_t FIFOBuffer<T>::getSize(){
    return this->size;
}

template<typename T> long FIFOBuffer<T>::getCapacity(){
    return this->capacity;
}

/*
    Function used only during debug that does not follow the FIFO principle,
    use is deprecated
*/
template<typename T> T FIFOBuffer<T>::at(long index){
    return this->buffer[index];
}





template<typename T> void FIFOBuffer<T>::push(T elem){

    if (this->size == 0){   //? No elements in buffer, we can start from the beginning
        this->push_i = 0;
        this->pop_i = 0;
        goto PUSH;
    }

    if (this->push_i == this->capacity){    //? Reached end of buffer
        if (this->pop_i > 0){   //? There are empty locations before pop_i
            this->push_i = 0;
            goto PUSH;
        }
        else {  //? Buffer is full, double allocated space
            this->buffer.resize(this->capacity*2);
            this->capacity *= 2;
            goto PUSH;
        }
    }

    if (this->push_i == this->pop_i){   //? Buffer is full, risk of overwriting
        this->push_i = this->capacity;
        this->buffer.resize(this->capacity*2);
        this->capacity *= 2;
    }

    PUSH:
    this->buffer[this->push_i++] = elem;    //? Core push operation on correct push_i
    this->size++;                           //? Size increase

}

template<typename T> void FIFOBuffer<T>::pop(T* ret_pointer){
    
    if (this->size == 0) return;    //? No elements in buffer

    *ret_pointer = this->buffer[this->pop_i++]; //? Core pop operation on correct pop_i
    this->pop_i %= this->capacity;              //? Avoid pop_i going over bounds
    this->size--;                               //? Size decrease

}

//? End of FIFO buffer implementations -------------------------------------------------------------------------
