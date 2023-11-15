#include "buffers.hpp"

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


void pushMsg(FIFOBuffer<int>* fifo, LIFOBuffer<int>* lifo, int val){
    char msg[64] = "\0";

    snprintf(msg, 64, "FIFO -> Pushing: %d , buf capacity = %ld",val,fifo->getCapacity());
    cout << msg << endl;
    fifo->push(val);
    snprintf(msg, 64, "FIFO -> buf size = %ld",fifo->getSize());
    cout << msg << endl;

    snprintf(msg, 64, "LIFO -> Pushing: %d , buf capacity = %ld",val,lifo->getCapacity());
    cout << msg << endl;
    lifo->push(val);
    snprintf(msg, 64, "LIFO -> buf size = %ld\n",lifo->getSize());
    cout << msg << endl;
}

void popMsg(FIFOBuffer<int>* fifo, LIFOBuffer<int>* lifo, int i){
    char msg[64] = "\0";

    snprintf(msg, 64, "FIFO -> Pop #%d ...",i);
    cout << msg << endl;
    int elem = -1;
    fifo->pop(&elem);
    snprintf(msg, 64, "FIFO -> Popped: %d , buf size = %ld",elem,fifo->getSize());
    cout << msg << endl;

    snprintf(msg, 64, "LIFO -> Pop #%d ...",i);
    cout << msg << endl;
    elem = -1;
    lifo->pop(&elem);
    snprintf(msg, 64, "LIFO -> Popped: %d , buf size = %ld\n",elem,lifo->getSize());
    cout << msg << endl;
}





int main(int argc, char** argv){

    int capacity = 1;
    int iterations = 20;

    //? Argument parsing
    for (int i=1; i<argc; ++i){
        string arg = (string)argv[i];
        if (arg == "-h" || arg == "--help"){
            cout <<
            "Accepted arguments:\n"
            "\t-c, --capacity <int>: initial capacity of buffer\n"
            "\t-i, --iterations <int>: number of iterations per test\n"
            << endl;
            exit(0);
        }
        if (arg == "-c" || arg == "--capacity")
            capacity = stoi(argv[i+1]);
        if (arg == "-i" || arg == "--iterations")
            iterations = stoi(argv[i+1]);
    }

    FIFOBuffer<int> fifo = FIFOBuffer<int>(capacity);
    LIFOBuffer<int> lifo = LIFOBuffer<int>(capacity);



    // ----------------------------------------------------------

    //? Many pushes
    cout << "---- Many pushes ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        pushMsg(&fifo, &lifo, i);
    }

    //? Many pops + 1
    cout << "---- Many pops + 1 ----\n" << endl;
    for (int i=0; i<iterations+1; ++i){
        popMsg(&fifo, &lifo, i);
    }

    //? Many pushes again
    cout << "---- Many pushes again ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        pushMsg(&fifo, &lifo, i);
    }

    //? Alternating push and pops
    cout << "---- Alternating pushes and pops ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        if (i%2 == 0){
            int push_val = i/2;
            pushMsg(&fifo, &lifo, push_val);
        }
        else {
            popMsg(&fifo, &lifo, i/2);
        }
    }

    //? Many pops again
    cout << "---- Many pops again ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        popMsg(&fifo, &lifo, i);
    }

    //? All invalid pops
    cout << "---- All invalid pops ----\n" << endl;
    for (int i=0; i<iterations+1; ++i){
        popMsg(&fifo, &lifo, i);
    }

    //? Particular case test
    cout << "---- Filling buffer ----\n" << endl;
    long tmp_max_iter = fifo.getCapacity();
    for (int i=0; i<tmp_max_iter; ++i){
        pushMsg(&fifo, &lifo, i);
    }
    cout << "---- Popping half of the buffer ----\n" << endl;
    for (int i=0; i<tmp_max_iter/2; ++i){
        popMsg(&fifo, &lifo, i);
    }
    cout << "---- Pushing more values in the buffer ----\n" << endl;
    tmp_max_iter = fifo.getCapacity();
    for (int i=0; i<tmp_max_iter; ++i){
        pushMsg(&fifo, &lifo, i);
    }
    cout << "---- Popping all the remaining buffer ----\n" << endl;
    tmp_max_iter = fifo.getSize();
    for (int i=0; i<tmp_max_iter; ++i){
        popMsg(&fifo, &lifo, i);
    }
    cout << "---- All invalid pops ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        popMsg(&fifo, &lifo, i);
    }

    //-----------------------------------------------------------



    return 0;
}