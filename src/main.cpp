#include <vector>           // vector utils     |   std::vector , ...
#include <iostream>         // I/O operations   |   std::cout , ...
#include <chrono>           // time keeping     |   std::chrono, ... 

#include "max_heap.hpp"     // Build max heap   |   hp::MaxHeap, ...
#include "min_heap.hpp"     // Build min heap   |   hp::MinHeap, ...

#define DIM 9              // Number of nodes

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

    for(uint64_t i = 0; i < DIM ; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
    std::cout << "Time elapsed: " << diff.count() << " seconds" << std::endl << std::endl;

    return 0;
}