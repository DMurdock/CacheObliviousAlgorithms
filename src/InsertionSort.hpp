#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_

namespace InsertionSort
{

template<typename Type>
void insertionSort(Type& arr)
{
    for(unsigned int i = 1; i < arr.size(); ++i)
    {
        for(unsigned int j = i; j > 0 && arr[j-1] > arr[j];--j)
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }

    }
}

}

#endif
