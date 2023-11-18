#include "buffers.hpp"

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <chrono>

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




int intensiveTestRoutine(FIFOBuffer<int>* fifo, LIFOBuffer<int>* lifo, int iterations){
    cout << 
        "---- Launching intensive test routine with " << iterations <<" iterations per cycle ----\n" 
        "\tNo output will be given during the single tests to measure only the push and pop execution times\n"
        "\t(initial capacity of FIFO and LIFO buffers = " << fifo->getCapacity() << ")\n"
    << endl;

    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    int tmp = 0;

    cout << "Press Enter to start..." << endl;
    cin.get();


    // -------------------------------------------------------------------------------------

    cout << "\n\n\n~> Testing the FIFOBuffer...\n" << endl;

    cout << "~> Performing " << iterations << " pushes...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->push(i);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " invalid pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pushes...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->push(i);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " invalid pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        fifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent FIFOBuffer capacity = " << fifo->getCapacity() << "\n"
    << endl;


    // -------------------------------------------------------------------------------------

    cout << "\n\n\n~> Testing the LIFOBuffer...\n" << endl;

    cout << "~> Performing " << iterations << " pushes...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->push(i);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " invalid pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pushes...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->push(i);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;

    cout << "~> Performing " << iterations << " invalid pops...\n" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0; i<iterations; ++i){
        lifo->pop(&tmp);
    }
    end = chrono::high_resolution_clock::now();
    cout << 
        "\tTime taken = " << (chrono::duration_cast<chrono::milliseconds>(end-start)).count() << " ms\n"
        "\tCurrent LIFOBuffer capacity = " << lifo->getCapacity() << "\n"
    << endl;





    return 0;
}





int main(int argc, char** argv){

    int capacity = 1;
    int iterations = 20;

    bool intensive_test = false;
    const int intensiveTest_iterations = 100'000'000;

    //? Argument parsing
    string arg = "";
    if (argc < 2){
        cout <<
            "Accepted arguments:\n"
            "\t-c, --capacity <int>: initial capacity of buffer\n"
            "\t-i, --iterations <int>: number of iterations per test\n"
            "\t-t, --time: launch an intensive timed test of " << intensiveTest_iterations << " iterations per test case\n"
        << endl;
        exit(0);
    }

    for (int i=1; i<argc; ++i){
        arg = (string)argv[i];
        if (arg == "-h" || arg == "--help"){
            cout <<
                "Accepted arguments:\n"
                "\t-c, --capacity <int>: initial capacity of buffer\n"
                "\t-i, --iterations <int>: number of iterations per test\n"
                "\t-t, --time: launch an intensive timed test of " << intensiveTest_iterations << " iterations per test case\n"
            << endl;
            exit(0);
        }
        if (arg == "-c" || arg == "--capacity")
            capacity = stoi(argv[i+1]);
        if (arg == "-i" || arg == "--iterations")
            iterations = stoi(argv[i+1]);
        if (arg == "-t" || arg == "--time")
            intensive_test = true;
    }

    FIFOBuffer<int> fifo = FIFOBuffer<int>(capacity);
    LIFOBuffer<int> lifo = LIFOBuffer<int>(capacity);

    if (intensive_test){
        if (intensiveTestRoutine(&fifo, &lifo, intensiveTest_iterations)){
            cout << "Oops! Something went wrong in the test routine!\n" << endl;
            return 1;
        }
        return 0;
    }

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