#pragma once
#include "heap.hpp"

namespace heap{ 

    template<typename T>
    class MaxHeap : public Heap<T> {

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

        void erase(uint index) override;

        void eraseByValue(T value) override;

        void addVector(std::vector<T> &vec) override;

        void addHeap(Heap<T> &vector) override;

        MaxHeap operator+(Heap<T> &input);

    };

}   // namespace 'heap'Node

#include <impl/max_heap.i.hpp>