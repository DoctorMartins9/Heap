#pragma once
#include "heap.hpp"

namespace hp{ 

    template<typename T>
    class MaxHeap : public Heap<T> {
    
    using Heap<T>::heap;
    using Heap<T>::getElements;
    using Heap<T>::addElement;
    using Heap<T>::getVector;

    private:  

        // Build the subtree
        void heapify(std::vector<Node<T>> &heap, uint n, int i) override;

        // Build the tree
        void maxHeapify();

    public:

        static void heapSort(std::vector<T> &vec);
        
        MaxHeap(std::vector<T> input);

        // Add an element in heap and then re-order
        void addElement(T n);

        void erase(uint index);

        void eraseByValue(T value);

        void addVector(std::vector<T> &vec);

        void addHeap(Heap<T> &vector);

        MaxHeap operator+(Heap<T> &input);

    };

}   // namespace 'heap'Node

#include <impl/max_heap.i.hpp>