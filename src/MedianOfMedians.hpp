#ifndef MEDIAN_OF_MEDIANS_HPP
#define MEDIAN_OF_MEDIANS_HPP

#include <algorithm>
#include <cmath>
#include <iterator>

#include "InsertionSort.hpp"

template <typename Type, typename Iter>
Iter select(Type& arr, const Iter& left, const Iter& right);


template <typename Type>
typename Type::iterator getMedianOfMedians(Type& arr)
{
    return select(arr, arr.begin(), arr.end());
}

template <typename Type, typename Iter>
Iter getMedianIteratorFromRange(Type&, const Iter& left, const Iter& right)
{
    unsigned int rangeDistance = std::distance(left,right);
    Type miniset(rangeDistance);
    std::copy(left, right, miniset.begin());
    InsertionSort::insertionSort(miniset);
    //return miniset.begin() + (rangeDistance/2);
    return std::find(left, right, miniset[rangeDistance/2]);
}

template <typename Type, typename Iter>
Iter pivot(Type& arr, Iter left, Iter right)
{
    unsigned int distance = std::distance(right, left);
    if(distance < 5)
    {
        Type miniset(distance);

    }

    Type miniset(5);
    for(auto subLeft = left; subLeft < right; subLeft+=5)
    {
        auto subRight = subLeft + 5;
        if(subRight > right)
        {
            subRight = right;
        }
        std::copy(subLeft, subRight, miniset.begin());
        InsertionSort::insertionSort(miniset);
        auto subMedian = getMedianIteratorFromRange(arr, subLeft, subRight);
        std::swap(subMedian, left + std::floor(std::distance(left,subLeft)/5)); //TODO see if swap invalidates iterators
    }
    return select(arr, left, left + std::floor(std::distance(right, left)/5), std::distance(right, left)/10 + 1);

}

template <typename Type, typename Iter>
Iter select(Type& arr, const Iter& left, const Iter& right)
{
    Iter pivotIter;
    while(true)
    {
        if(left == right)
        {
            return left;
        }

        pivotIter = pivot(arr, left, right);
        pivotIter = partition(arr, left, right, pivotIter);

        if(left == pivotIter)
        {
            return left;
        }
        else if(left < pivotIter)
        {
            right = --pivotIter;
        }
        else
        {
            left = ++pivotIter;
        }
    }
}



#endif
