#include <iostream>
#include <string>
#include "Stack.h"  // Your Stack template class

using namespace std;

bool areMatchingBrackets(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int main() {
    string input;
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);

    // Initialize a stack to hold characters
    Stack<char, vector<char>> mystack;

    for (char nextchar : input) {
        // If character is an opening bracket, push it to the stack
        if (nextchar == '(' || nextchar == '[' || nextchar == '{' || nextchar == '<') {
            mystack.push(nextchar);
        }
        // If character is a closing bracket
        else if (nextchar == ')' || nextchar == ']' || nextchar == '}' || nextchar == '>') {
            // If the stack is empty, there's no matching opening bracket
            if (mystack.empty()) {
                cout << "Mismatched brackets!" << endl;
                return 1;
            }

            // Check if the top of the stack matches the current closing bracket
            char topChar = mystack.top();
            if (areMatchingBrackets(topChar, nextchar)) {
                mystack.pop();
            } else {
                cout << "Mismatched brackets!" << endl;
                return 1;
            }
        }
    }

    // If the stack is empty, all brackets matched
    if (mystack.empty()) {
        cout << "Matching brackets." << endl;
    } else {
        cout << "Mismatched brackets!" << endl;
    }

    return 0;
}
