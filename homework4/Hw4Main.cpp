#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
#include "Vector.h"

int main() {
    Stack<char, Vector<char>> mystack;  // Use your custom Vector with the Stack
    std::string filename;

    // Ask the user for the file to check
    std::cout << "Enter the filename to check for matching brackets: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string nextline;
    bool mismatchFound = false;

    // Read the file line by line
    while (std::getline(inputFile, nextline)) {
        // Check each character in the line
        for (char nextchar : nextline) {
            if (nextchar == '{') {
                mystack.push(nextchar);
            } else if (nextchar == '}') {
                if (mystack.empty()) {
                    std::cerr << "Mismatch found: More closing brackets ('}') than opening brackets ('{')." << std::endl;
                    mismatchFound = true;
                    break;
                } else {
                    mystack.pop();
                }
            }
        }

        if (mismatchFound) {
            break;  // Exit the loop if a mismatch was found
        }
    }

    inputFile.close();

    // After reading the file, check if there are unmatched opening brackets
    if (!mismatchFound) {
        if (mystack.empty()) {
            std::cout << "All brackets match successfully." << std::endl;
        } else {
            std::cerr << "Mismatch found: More opening brackets ('{') than closing brackets ('}')." << std::endl;
        }
    }

    return 0;
}