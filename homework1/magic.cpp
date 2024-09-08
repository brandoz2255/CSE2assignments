#include "magic.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <stdexcept>



void magic_square(int size) {
    if (size <= 0 || size % 2 == 0) {
        throw std::invalid_argument("Size must be a positive odd number!!");
    }

    std::vector<std::vector<int>> dynamicGenerateSquare(size, std::vector<int>(size, 0));

    int num = 1;
    int i = 0;
    int j = size / 2;  // Start from the middle of the first row

    while (num <= size * size) {
        dynamicGenerateSquare[i][j] = num++;  // Place the current number

        // Calculate the new position
        int new_i = (i - 1 + size) % size;
        int new_j = (j + 1) % size;

        // If the new position is already filled, move down instead
        if (dynamicGenerateSquare[new_i][new_j] != 0) {
            i = (i + 1) % size;
        } else {
            i = new_i;
            j = new_j;
        }
    }




    // Print the magic square
    std::cout << "The magic square of size " << size << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(4) << dynamicGenerateSquare[i][j] << " ";
        }
        std::cout << "\n";
    }



    // Verify the magic property
    int magic_constant = size * (size * size + 1) / 2;
    bool isValid = true;
    for (int i = 0; i < size; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < size; j++) {
            row_sum += dynamicGenerateSquare[i][j];
            col_sum += dynamicGenerateSquare[j][i];
        }
        if (row_sum != magic_constant || col_sum != magic_constant) {
            isValid = false;
            break;
        }
    }

    

    if (!isValid) {
        std::cerr << "Error: The generated square is not valid.\n";
    } else {
        std::cout << "Sum of each row/column: " << magic_constant << "\n";
    }
}
