#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>

#include "CountingSort.hpp"

#include "utils/timers.hpp"

namespace CountingSort
{

template<typename Type>
void testCountingSort(Type dataSet)
{
    std::cout << "Counting sort start" << std::endl << std::flush;
    auto startTime = GetTimeMs64();
    countingSort(dataSet);
    std::cout << (GetTimeMs64() - startTime) << std::endl;
    assert(std::is_sorted(dataSet.begin(), dataSet.end()));
}

template<typename Type>
void testCountingSortMiniSets(Type dataSet, unsigned int minisetSize)
{
    std::cout << "Counting sort mini-set start" << std::endl << std::flush;
    unsigned int size = dataSet.size();
    Type miniset(5);
    auto startTime = GetTimeMs64();
    for(unsigned int i = 0; i < size; i+=minisetSize)
    {
        std::copy(dataSet.begin()+i, dataSet.begin()+i+minisetSize, miniset.begin());
        countingSort(miniset);
        //assert(std::is_sorted(dataSet.begin(), dataSet.begin()+i+minisetSize-1));
    }
    std::cout << (GetTimeMs64() - startTime) << std::endl;
}


}
