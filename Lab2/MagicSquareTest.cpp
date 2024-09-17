#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <fstream>


/**
 * IMPORTANT PROFESSOR!!!
 * The second screenshot is when i modified the code to have both square11b 
 * to be analyzed which is why is states that both dont contain the magic squares
 * So it works i made this code to analyze both of them and then tell you which one is and isnt a 
 * magic square while also printing out the contents of the real one!!
 * 
 * Also one screenshot is from my terminal and the other is from my VScode 
 * so sorry for the confusion there I wanted to show what i did to the code that got the whoops none 
 * of them are magics squares :) 
 * 
 *  */

using namespace std;



// This function checks if the given square is a magic square


bool magic_square(const vector<vector<int>>& square, int size) {
    int magic_constant = size * (size * size + 1) / 2;

    // Check rows and columns and stuff
    for (int i = 0; i < size; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < size; j++) {
            row_sum += square[i][j];
            col_sum += square[j][i];
        }
        if (row_sum != magic_constant || col_sum != magic_constant) {
            return false;
        }
    }

    

    int diagonal1_sum = 0;
    int diagonal2_sum = 0;


    for (int i = 0; i < size; i++) {
        diagonal1_sum += square[i][i];            
        diagonal2_sum += square[i][size - i - 1]; 
    }



    if (diagonal1_sum != magic_constant || diagonal2_sum != magic_constant) {
        return false;
    }



    return true; 
}

void printSquare(const vector<vector<int>>& square, int size) {
    cout << "The contents of the magic square are:\n";
    for (int i = 0; i < size; i++) {
        for(int j =  0; j < size; j++){
            cout << setw(4) << square[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {


    // File paths for the input files
    ifstream file1("square11A.txt"); 
    ifstream file2("square11B.txt");

    // Ensure both files are open correctly
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Error opening one of the files!" << endl;
        return 1;
    }

    // Define 11x11 squares
    vector<vector<int>> square1(11, vector<int>(11));
    vector<vector<int>> square2(11, vector<int>(11));



    // Nested for loops for Reading from file1 into square1
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            file1 >> square1[i][j];
            file2 >> square2[i][j];
        }
    }



    // Close the files after reading
    file1.close();
    file2.close();



    // Check if the squares are magic squares and print the results
    if (magic_square(square1, 11)) {
        cout << "File 1 contains a magic square!" << endl;
        printSquare(square1, 11);  // Print the contents of the magic square
    } else {
        cout << "File 1 does not contain a magic square." << endl;
    }



    if (magic_square(square2, 11)) {
        cout << "File 2 contains a magic square!" << endl;
        printSquare(square2, 11);  // Print the contents of the magic square
    } else {
        cout << "File 2 does not contain a magic square." << endl;
    }



    return 0;
}

