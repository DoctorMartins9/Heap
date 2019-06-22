#include <vector>
#include <iostream>
#include <chrono>

#include "max_heap.hpp"

#define DIM 10000

int main(){

    // Integer test ---------------------------------------------------- 
    std::cout << std::endl << "Integer heap-sort test" << std::endl << std::endl;

    std::vector<int> heap;

    for(int i = 0; i < DIM ; i++)
        heap.push_back( i ); 

    auto start = std::chrono::system_clock::now();
    hp::MaxHeap<int>::heapSort(heap);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << "Time elapsed: " << diff.count() << " seconds" << std::endl;

/*

    // floating point test ----------------------------------------------------
    std::cout << std::endl << "Float heap-sort test" << std::endl << std::endl;

    std::vector<float> heap_f;

    for(int i = 0; i < DIM ; i++)
        heap_f.push_back(static_cast<float>(DIM) / (i+1) ); 


    heap::MaxHeap<float>::heapSort(heap_f);


    // double test ----------------------------------------------------

    std::cout << std::endl << "Double heap-sort test" << std::endl << std::endl;
    std::vector<double> heap_d;

    for(int i = 0; i < DIM ; i++)
        heap_d.push_back(static_cast<double>(DIM) / (i+1) ); 

    heap::MaxHeap<double>::heapSort(heap_d);

*/

    return 0;
}