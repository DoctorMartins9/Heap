# Heap-implementation
Heap is a open source library usefull for building an heap, an almost complete binary tree in which each node corresponds to an element of the array.

## Building
First, in build directory, type:
```
cmake ..
make install
```
The final binary executable now is placed in bin directory:
```
./my_heap
``` 

## Usage
```
#include "max_heap.hpp"

std::vector<T> vec;

// Sorting 
hp::MaxHeap<T>::heapSort(vec);

```

## Testing
Using the [catch.hpp](https://github.com/catchorg/Catch2) library for testing, in build directory you have to type:

```
cmake ..
make heap_test
make test
```

