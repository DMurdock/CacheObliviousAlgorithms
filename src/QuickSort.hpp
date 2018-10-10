#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <exception>
#include <iostream>

namespace QuickSort
{

template<typename Type>
int partition (Type& arr, int low, int high)
{
    // pivot (Element to be placed at right position)
    //int pivot = arr[(high+low)/2];
    int pivot = arr[high];

    int i = (low - 1);  // Index of smaller element
    //std::cout << "i" << i << std::endl;

    for(int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }
    int swap = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = swap;
    return (i + 1);
}

//#define IFPRINT(x) if(calls >= 43274) std::cout << x << std::endl;
#define IFPRINT(x) if(false) std::cout << x << std::endl;
template<typename Type>
void quickSort(Type& arr, int lowIndex, int highIndex)
{
    try
    {
        static int calls = 0;
        IFPRINT("START")
        calls++;

        if (lowIndex < highIndex)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            IFPRINT("A")
            int pi = partition(arr, lowIndex, highIndex);
            IFPRINT("B")
            //std::cout << pi << " " << lowIndex << " " << highIndex << std::endl <<std::flush;

            quickSort(arr, lowIndex, pi - 1);  // Before pi
            IFPRINT("C")
            quickSort(arr, pi + 1, highIndex); // After pi
            IFPRINT("D")
        }
    }
    catch(const std::exception & ex)
    {
        std::cerr << ex.what() << std::endl << std::flush;
    }
}

}

#endif
