#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

void rand_seed();
int rand_int(int, int);

// for vector
void random_vector(int, int, int, vector<int>&, int);
void random_vector_norep(int, int, int, vector<int>&, int);

#endif
