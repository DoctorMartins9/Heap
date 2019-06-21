

#include <vector>
#include <iostream>
#include "max_heap.hpp"

int main(){

    std::vector<int> heap;

    for(int i = 0; i < 10 ; i++)
        heap.push_back(10 - i); 


    for(int i =  0; i < heap.size(); i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
   
    //heap::MaxHeap mc = heap::MaxHeap(heap);
    heap::MaxHeap<int>::heapSort(heap);
    //heap::MaxHeap my_heap;

    for(int i =  0; i < heap.size(); i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}