//============================================================================
// Name        : CacheObliviousAlgorithms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <random>
#include "SampleDataGenerators.hpp"
#include "timers.hpp"
#include "QuickSort.hpp"

using namespace std;

int main() {

    const unsigned int setLength = 10000000;
    std::cout << "A" << std::flush;
    int* dataSet = createDescendingIntArray(setLength);
    std::shuffle(dataSet, dataSet + setLength, std::default_random_engine());
    std::cout << "B" << std::flush;

    auto startTime = GetTimeMs64();
    std::cout << "C" << std::flush;
    quickSort(dataSet, 0, setLength-1);
    std::cout << "D" << std::endl << std::flush;
    std::cout << (GetTimeMs64() - startTime) << std::endl;


	return 0;
}
