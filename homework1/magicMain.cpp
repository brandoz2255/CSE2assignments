//#include "magic.cpp"
#include "magic.h"

#include<iostream>
#include<cstdlib>

int main() {

    int size;

    bool validInput =false;

    while(!validInput){
        std::cout<<"This is a simple usuage of the magic square algorithm!!"<< std::endl;
        std::cout << "Just choose an odd number!! -->  " << std::endl;

        if (!(std::cin >> size)){
            std::cout << "invalid input please enter a valid integer must be odd!!!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }else if (size <= 0 || size % 2 == 0){
            std::cout << "Error:size must be a positive odd numebr" << std::endl;

        }else {
            validInput = true;
        }



    }


    magic_square(size);

    return 0;


}