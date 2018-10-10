#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>

#include "QuickSort.hpp"

#include "utils/timers.hpp"

namespace QuickSort
{

template<typename Type>
void testQuickSort(Type dataSet)
{
    std::cout << "Quick sort start" << std::endl << std::flush;
    auto startTime = GetTimeMs64();
    quickSort(dataSet, 0, dataSet.size()-1);
    std::cout << (GetTimeMs64() - startTime) << std::endl;
    assert(std::is_sorted(dataSet.begin(), dataSet.end()));
}

template<typename Type>
void testQuickSortMiniSets(Type dataSet, unsigned int minisetSize)
{
    std::cout << "Quick sort mini-set start" << std::endl << std::flush;
    unsigned int size = dataSet.size();
    Type miniset(minisetSize);
    auto startTime = GetTimeMs64();
    for(unsigned int i = 0; i < size; i+=minisetSize)
    {
        //std::cout << i << " " << std::flush;
        std::copy(dataSet.begin()+i, dataSet.begin()+i+minisetSize, miniset.begin());
        quickSort(miniset, 0, minisetSize-1);
        //std::cout << i << std::endl << std::flush;
        //assert(std::is_sorted(dataSet.begin(), dataSet.begin()+i+minisetSize-1));
    }
    std::cout << (GetTimeMs64() - startTime) << std::endl;
}


}
