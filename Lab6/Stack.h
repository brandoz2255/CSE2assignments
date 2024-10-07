#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <iostream>
#include <cassert>

template <typename T, typename C = std::vector<T>>
class Stack {
public:
    typedef typename C::value_type value_type;

    // Constructor
    Stack() {}

    // Returns the size of the stack
    int size() const {
        return thestack.size();
    }

    // Checks if the stack is empty
    bool empty() const {
        return thestack.empty();
    }

    // Pushes an element onto the stack
    void push(const value_type& x) {
        thestack.push_back(x);
    }

    // Pops an element from the stack
    void pop() {
        assert(!thestack.empty()); 
        thestack.pop_back();
    }

    // Returns the top element of the stack
    value_type top() const {
        assert(!thestack.empty()); 
        return thestack.back();
    }

private:
    C thestack;
};

#endif
