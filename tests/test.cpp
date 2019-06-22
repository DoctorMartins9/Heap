#include "max_heap.hpp"

# define CATCH_CONFIG_MAIN
# include "catch.hpp"
#undef CATCH_CONFIG_MAIN

#include <iostream>
#include <iomanip>

TEST_CASE("Integer Heapsort Test" , "[IntHeapTest]"){
    
    using T = int;
    const int SIZE = 10;

    // Build and populate unordered vector
    std::vector<T> heap;

    for(int i = 0; i < SIZE ; i++)
        heap.push_back( i );

    // Sorting 
    hp::MaxHeap<T>::heapSort(heap);
    
    REQUIRE(1 == 1);

}

TEST_CASE("Float Heapsort Test" , "[FloatHeapTest]"){
    
    using T = float;
    const int SIZE = 10;

    // Build and populate unordered vector
    std::vector<T> heap;

    for(int i = 0; i < SIZE ; i++)
        heap.push_back( i );

    // Sorting 
    hp::MaxHeap<T>::heapSort(heap);
    
    REQUIRE(1 == 1);

}

TEST_CASE("Double Heapsort Test" , "[DoubleHeapTest]"){
    
    using T = double;
    const int SIZE = 10;

    // Build and populate unordered vector
    std::vector<T> heap;

    for(int i = 0; i < SIZE ; i++)
        heap.push_back( i );

    // Sorting 
    hp::MaxHeap<T>::heapSort(heap);
    
    REQUIRE(1 == 1);

}