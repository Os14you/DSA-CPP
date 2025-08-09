#include "sorting.hpp"

template <typename T>
void sort::insertionSort(T arr[], int len) {
    for(int i=1; i<len; ++i) {
        T element = arr[i];
        int j = i - 1;

        while(j >= 0 && element < arr[j]) 
            arr[j+1] = arr[j], j--;
        
        arr[j+1] = element;
    }
}