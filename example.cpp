// compile: c++ -o example example.cpp
#include<iostream>

using namespace std;

int sqr( int n ) {     // Function declaration and definition
    return n*n;
}

int main() {
    cout << "The square of 3 is " << sqr(3) << endl;
    return 0;
}
