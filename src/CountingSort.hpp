#ifndef COUNTINGSORT_HPP_
#define COUNTINGSORT_HPP_

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

namespace CountingSort
{

template<typename Type>
void countingSort(Type& arr)
{
    int lowestValue = *(std::min_element(arr.begin(), arr.end()));
    int highestValue = *(std::max_element(arr.begin(), arr.end()));
    std::vector<unsigned int> count(highestValue - lowestValue + 1);
    try
    {
        for(auto x : arr)
        {
            count[x-lowestValue]++;
        }

        //calculate the starting index for each key:
        unsigned int total = 0;
        for(auto& each : count)
        {
            int oldCount = each;
            each = total;
            total += oldCount;
        }

        //copy to output array, preserving order of inputs with equal keys:
        std::vector<int> output(arr.size());
        for(auto x : arr)
        {
            unsigned int xCount = count[x-lowestValue]++;
            output[xCount] = x;
        }
        arr = std::move(output);
    }
    catch(const std::exception & ex)
    {
        std::cerr << ex.what() << std::endl << std::flush;
    }
}

}

#endif
