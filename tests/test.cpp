#include "max_heap.hpp"
#include "min_heap.hpp"

# define CATCH_CONFIG_MAIN
# include "catch.hpp"
#undef CATCH_CONFIG_MAIN
  
template<typename T>
bool isIncreasing ( std::vector<T> vec){
    
    T prev;

    for(uint i = 1 ; i < vec.size() ; i++)
        if(vec[i-1] > vec[i] )
            return false;
    
    return true;
}

TEST_CASE("Integer Heapsort Test" , "[IntHeapTest]"){
    
    using T = int;
    const int SIZE = 10;

    // Build and populate unordered vector
    std::vector<T> heap;

    for(int i = 0; i < SIZE ; i++)
        heap.push_back( i );

    // Sorting 
    hp::MaxHeap<T>::heapSort(heap);
    
    // Check values lost
    REQUIRE( heap.size() == SIZE  );

    // Check if is ordered
    REQUIRE( isIncreasing(heap) );
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
    
    // Check values lost
    REQUIRE( heap.size() == SIZE  );

    // Check if is ordered
    REQUIRE( isIncreasing(heap) );

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
    
    // Check values lost
    REQUIRE( heap.size() == SIZE  );

    // Check if is ordered
    REQUIRE( isIncreasing(heap) );

}