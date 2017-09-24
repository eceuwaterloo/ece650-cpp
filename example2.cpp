// compile: c++ -o example2 example2.cpp
#include<iostream>

using namespace std;

// declaration of function sqr
int sqr( int n );

// main function that uses sqr
int main() {
    cout << "The square of 3 is " << sqr(3) << endl;
    return 0;
}

// definition of function sqr
int sqr( int n ) {     // Function declaration and definition
    return n*n;
}
