#pragma once

namespace heap{

    template<typename T>
    class Node{
    private:
        T value;
        // Set node value
        void setValue(T input);

    public:

        // Default constructor
        Node();

        // Constructor by value
        Node(T i);

        Node operator= (Node n);

        // Return Node value
        T getValue();

    };
}   // namespace 'heap'Node

#include "impl/node.i.hpp"
