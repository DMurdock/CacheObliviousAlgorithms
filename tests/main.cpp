//============================================================================
// Name        : CacheObliviousAlgorithms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>

#include "CountingSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"

#include "MedianOfMedians.hpp"

#include "CountingSortTests.hpp"
#include "InsertionSortTests.hpp"
#include "QuickSortTests.hpp"

#include "utils/SampleDataGenerators.hpp"

using namespace std;

int main() {

    std::cout << "Start" << std::endl << std::flush;
    const std::size_t setLength = 10000000;
    std::cout << "Create vector" << std::endl << std::flush;
    std::vector<int> dataSet(setLength);
    std::cout << "Create descending vector" << std::endl << std::flush;
    createDescendingIntArray(dataSet);
    std::cout << "Shuffle vector" << std::endl << std::flush;
    std::shuffle(dataSet.begin(), dataSet.end(), std::default_random_engine());

    /*
     * Speed Tests
     */
    //QuickSort::testQuickSort(dataSet);
    //CountingSort::testCountingSort(dataSet);
    //InsertionSort::testInsertionSort(dataSet);

    /*
     * Mini-set Speed Tests
     */
    const unsigned int MINISET_SIZE = 5;
    //QuickSort::testQuickSortMiniSets(dataSet, MINISET_SIZE);
    //CountingSort::testCountingSortMiniSets(dataSet, MINISET_SIZE);
    //InsertionSort::testInsertionSortMiniSets(dataSet, MINISET_SIZE);

    std::cout << (*getMedianOfMedians(dataSet)) << std::cout;

	return 0;
}
