// Compile: c++ -c -o stack.o stack.cpp -std=c++11
#include <iostream>

class Stack;

class StackEntry {
private:
    int data;
    StackEntry *next;
    StackEntry(int v, StackEntry *n);
    friend class Stack;
};


class Stack {
private:
    int size;
    StackEntry *top;
public:
    Stack();
    virtual ~Stack();
    bool empty();
    void push(int v);
    int pop();
};

void print_stack(std::ostream &out, Stack *s);

StackEntry::StackEntry(int v, StackEntry* n) : data(v), next(n) {}

Stack::Stack() : size(0), top(nullptr) {}
Stack::~Stack() {
    while (!empty()) { pop(); }
}

bool Stack::empty() { return size == 0 || top == nullptr; }

void Stack::push(int v) {
    StackEntry *newEntry = new StackEntry(v, top);
    if (newEntry == nullptr) {
        std::cerr << "[push()] out of memory\n";
        return;
    }
    top = newEntry;
    size++;
}

int Stack::pop() {
    if (empty()) {
        std::cerr << "Error: [pop()] stack is empty\n";
        return 0;
    }

    StackEntry *popped = top;
    int res = popped->data;
    top = popped->next;
    size--;

    delete popped;

    return res;
}

void print_stack(std::ostream &out, Stack *s) {

    // same as (s!=nullptr)  or  (s!=NULL)
    if (!s) {
        out << "nil\n";
        return;
    }

    // the only way to observe what is in the stack is to pop from it.
    // to preserve the values, we store what was popped into a local
    // stack, and then reconstruct the original stack.

    // local storage
    Stack local;

    // print stack while popping
    out << "[ ";
    while (!s->empty()) {
        int v = s->pop();
        out << v << " ";
        local.push(v);
    }
    out << "]\n";

    // restore the stack from local copy
    while (!local.empty()) {
        s->push (local.pop());
    }
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("stack example") {
    Stack st;
    st.push(5);
    st.push(6);
    print_stack(std::cout, &st);
    CHECK(st.pop() == 6);
    CHECK(st.pop() == 5);
    CHECK(st.empty() == true);
}
