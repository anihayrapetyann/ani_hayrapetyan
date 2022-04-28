#ifndef __MY_GENERATOR_H__
#define __MY_GENERATOR_H__

#include <ctime>
#include <random>

using namespace std;

mt19937 gen (time(0));

int MyGenerator() {
    int rand = gen() % 5000;
    return rand;
}

#endif 