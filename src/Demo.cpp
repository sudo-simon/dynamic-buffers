#include "buffers.hpp"

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;





int main(int argc, char** argv){

    //const long init_size = 100;
    //FIFOBuffer<int> buf = FIFOBuffer<int>(init_size);
    
    FIFOBuffer<int> buf = FIFOBuffer<int>();



    // ----------------------------------------------------------

    const int iterations = 20;
    char msg[64] = "\0";

    //? Many pushes
    cout << "---- Many pushes ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        snprintf(msg, 64, "Pushing: %d , buf capacity = %ld",i,buf.getCapacity());
        cout << msg << endl;

        buf.push(i);

        snprintf(msg, 64, "Elem at %d = %d , buf size = %ld\n",i,buf.at(i),buf.getSize());
        cout << msg << endl;
    }

    //? Many pops + 1
    cout << "---- Many pops + 1 ----\n" << endl;
    for (int i=0; i<iterations+1; ++i){
        snprintf(msg, 64, "Pop #%d ...",i);
        cout << msg << endl;

        int elem = -1;
        buf.pop(&elem);

        snprintf(msg, 64, "Popped: %d , buf size = %ld\n",elem,buf.getSize());
        cout << msg << endl;
    }

    //? Many pushes again
    cout << "---- Many pushes again ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        snprintf(msg, 64, "Pushing: %d , buf capacity = %ld",i,buf.getCapacity());
        cout << msg << endl;

        buf.push(i);

        snprintf(msg, 64, "buf size = %ld\n",buf.getSize());
        cout << msg << endl;
    }

    //? Alternating push and pops
    cout << "---- Alternating pushes and pops ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        if (i%2 == 0){
            int push_val = i/2;
            snprintf(msg, 64, "Pushing: %d , buf capacity = %ld",push_val,buf.getCapacity());
            cout << msg << endl;

            buf.push(push_val);

            snprintf(msg, 64, "buf size = %ld\n",buf.getSize());
            cout << msg << endl;
        }
        else {
            snprintf(msg, 64, "Pop #%d ...",i/2);
            cout << msg << endl;

            int elem = -1;
            buf.pop(&elem);

            snprintf(msg, 64, "Popped: %d , buf size = %ld\n",elem,buf.getSize());
            cout << msg << endl;
        }
    }

    //? Many pops again
    cout << "---- Many pops again ----\n" << endl;
    for (int i=0; i<iterations; ++i){
        snprintf(msg, 64, "Pop #%d ...",i);
        cout << msg << endl;

        int elem = -1;
        buf.pop(&elem);

        snprintf(msg, 64, "Popped: %d , buf size = %ld\n",elem,buf.getSize());
        cout << msg << endl;
    }

    //? All invalid pops
    cout << "---- All invalid pops ----\n" << endl;
    for (int i=0; i<iterations+1; ++i){
        snprintf(msg, 64, "Pop #%d ...",i);
        cout << msg << endl;

        int elem = -1;
        buf.pop(&elem);

        snprintf(msg, 64, "Popped: %d , buf size = %ld\n",elem,buf.getSize());
        cout << msg << endl;
    }

    //-----------------------------------------------------------



    return 0;
}