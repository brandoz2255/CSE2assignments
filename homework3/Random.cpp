#include <cassert>
#include <iostream>
#include "Random.h"

using namespace std;

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

// random integer between a and b;
int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

