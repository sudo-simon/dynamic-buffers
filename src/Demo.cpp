#include "buffer.hpp"

#include <iostream>
#include <string>

using namespace std;


template<typename T> void pushElem(FIFOBuffer<T> buf, T elem){
    cout << "Pushing: " << elem << endl;
    buf.push(elem);
}

template<typename T> void popElem(FIFOBuffer<T> buf){
    T& elem = buf.pop();
    cout << "Popped: " << elem << endl;
}





int main(int argc, char** argv){

    //const long init_size = 100;
    //FIFOBuffer<string> buf = FIFOBuffer<string>(init_size);
    
    FIFOBuffer<string> buf = FIFOBuffer<string>();



    // ----------------------------------------------------------

    //popElem(buf); // Error
    
    pushElem(buf, (string) "1");
    popElem(buf); // 1
    
    pushElem(buf, (string) "1");
    pushElem(buf, (string) "2");
    popElem(buf); // 1
    popElem(buf); // 2

    //popElem(buf); // Error

    pushElem(buf, (string) "1");
    pushElem(buf, (string) "2");
    pushElem(buf, (string) "3");
    popElem(buf); // 1
    pushElem(buf, (string) "4");
    popElem(buf); // 2
    popElem(buf); // 3
    pushElem(buf, (string) "5");
    popElem(buf); // 4
    popElem(buf); // 5

    //popElem(buf); // Error

    //-----------------------------------------------------------



    return 0;
}