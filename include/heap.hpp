#pragma once
#include "node.hpp"

namespace heap{
// Parent abstract class
    template<typename T>
    class Heap {

    protected:

        std::vector<Node<T>> heap;     // Vector of elements    

        // To override
        virtual void heapify(std::vector<Node<T>> &heap, uint n, int i) = 0;

    public:
        void addElement(T n);

        // To override
        void erase(uint index);
        void eraseByValue(T value);
        void addVector(std::vector<T> &vec);
        void addHeap(Heap<T> &vector);
     
        // Constructors
        Heap (std::vector<T> input);

        // Return number of elements in heap
        uint getElements();

        std::vector<T> getVector();

        // "toString()" override
        friend std::ostream& operator<<(std::ostream& stream, Heap<T>& hp);
        
        T operator[](T n);

    };
} // namespace 'heap'Node

#include <impl/heap.i.hpp>