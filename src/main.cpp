#include <vector>           // vector utils     |   std::vector , ...
#include <iostream>         // I/O operations   |   std::cout , ...
#include <chrono>           // time keeping     |   std::chrono, ... 

#include "max_heap.hpp"     // Build max heap   |   hp::MaxHeap, ...
#include "min_heap.hpp"     // Build min heap   |   hp::MinHeap, ...

#define DIM 9999              // Number of nodes

int main(){

    // Max Heap ---------------------------------------------------------------------

    std::cout << std::endl << "Integer heap-sort test (MaxHeap)" << std::endl << std::endl;

    std::vector<int> heap;

    for(uint64_t i = 0; i < DIM ; i++)
        heap.push_back( i ); 

    auto start = std::chrono::system_clock::now();
    hp::MaxHeap<int>::heapSort(heap);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << "Time elapsed: " << diff.count() << " seconds" << std::endl << std::endl;
    std::cout << "****************************************************" << std::endl;



    // Min Heap ---------------------------------------------------------------------

    std::cout << std::endl << "Integer heap-sort test (MinHeap)" << std::endl << std::endl;

    std::vector<int> min_heap;

    for(uint64_t i = 0 ; i < DIM ; i++)
        min_heap.push_back(DIM - i); 
    
    start = std::chrono::system_clock::now();
    hp::MinHeap<int>::heapSort(min_heap);
    end = std::chrono::system_clock::now();

    diff = end - start;

    std::cout << "Time elapsed: " << diff.count() << " seconds" << std::endl << std::endl;


    return 0;
}