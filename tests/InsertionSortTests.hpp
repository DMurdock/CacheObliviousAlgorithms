#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>

#include "InsertionSort.hpp"

#include "utils/timers.hpp"

namespace InsertionSort
{

template<typename Type>
void testInsertionSort(Type dataSet)
{
    std::cout << "Insertion sort start" << std::endl << std::flush;
    auto startTime = GetTimeMs64();
    insertionSort(dataSet);
    std::cout << (GetTimeMs64() - startTime) << std::endl;
    assert(std::is_sorted(dataSet.begin(), dataSet.end()));
}

template<typename Type>
void testInsertionSortMiniSets(Type dataSet, unsigned int minisetSize)
{
    std::cout << "Insertion sort mini-set start" << std::endl << std::flush;
    unsigned int size = dataSet.size();
    Type miniset(minisetSize);
    auto startTime = GetTimeMs64();
    for(unsigned int i = 0; i < size; i+=minisetSize)
    {
        std::copy(dataSet.begin()+i, dataSet.begin()+i+minisetSize, miniset.begin());
        insertionSort(miniset);
        //std::cout << i << std::endl;
        //assert(std::is_sorted(miniset);
    }
    std::cout << (GetTimeMs64() - startTime) << std::endl;
}


}
