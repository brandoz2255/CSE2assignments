#include <iostream>
#include "greetings.h"

int main(){

	
	std::string name;
	int number;
	std::cout << "enter your name-> ";
	std::cin >> name;
	printGreeting(name);
	std::cout<< "Enter a number: ";
	std::cin >> number;
	std::cout << "Twice your number is: " << number * 2 << std::endl;
	return 0;
}

