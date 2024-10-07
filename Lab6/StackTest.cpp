#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // Declare a stack that holds vectors of integers
    stack<vector<int>> mystack; 

    // Push integers 1 through 10 into the stack
    for (int i = 1; i <= 10; i++) {
        cout << "Pushing into stack: " << i << endl;
        
        // Since we're using a stack of vectors, we push a vector containing the integer
        vector<int> vec;
        vec.push_back(i);
        mystack.push(vec);
    }

    cout << endl;
    cout << "Popping the stack one element at a time..." << endl << endl;

    // Pop elements from the stack
    while (!mystack.empty()) {
        vector<int> tp = mystack.top(); // Get the top vector
        cout << tp[0] << " "; // Print the first element in the vector
        mystack.pop(); // Remove the top element from the stack
    }

    cout << endl;
    return 0;
}
