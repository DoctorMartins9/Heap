

#include <vector>
#include <iostream>
#include "max_heap.hpp"

int main(){

    // Integer test ---------------------------------------------------- 
    std::cout << std::endl << "Integer heap-sort test" << std::endl << std::endl;

    std::vector<int> heap;

    for(int i = 0; i < 10 ; i++)
        heap.push_back(10.0 / (i+1) ); 


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


    // floating point test ----------------------------------------------------
    std::cout << std::endl << "Float heap-sort test" << std::endl << std::endl;

    std::vector<float> heap_f;

    for(int i = 0; i < 10 ; i++)
        heap_f.push_back(10.0 / (i+1) ); 


    for(int i =  0; i < heap.size(); i++){
        std::cout << heap_f[i] << " ";
    }
    std::cout << std::endl;
   
    //heap::MaxHeap mc = heap::MaxHeap(heap);
    heap::MaxHeap<float>::heapSort(heap_f);
    //heap::MaxHeap my_heap;

    for(int i =  0; i < heap_f.size(); i++){
        std::cout << heap_f[i] << " ";
    }
    std::cout << std::endl;

    // floating point test ----------------------------------------------------
    std::cout << std::endl << "Char heap-sort test" << std::endl << std::endl;

    std::vector<char> heap_c;

    for(int i = 0; i < 10 ; i++)
        heap_c.push_back(static_cast<char>(i+40)); 


    for(int i =  0; i < heap.size(); i++){
        std::cout << heap_c[i] << " ";
    }
    std::cout << std::endl;
   
    //heap::MaxHeap mc = heap::MaxHeap(heap);
    //heap::MaxHeap<char>::heapSort(heap_f);
    //heap::MaxHeap my_heap;

    for(int i =  0; i < heap_c.size(); i++){
        std::cout << heap_c[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}