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
[...]

```

## Run the example (Release mode)
For running an example, in build directory type:

```
cmake ..
make release
../bin/my_heap

```

## Testing
Using the [catch2](https://github.com/catchorg/Catch2) library for testing, in build directory type:

```
cmake ..
make heap_test
./heap_test
```

## Documentation
Using doxigen, in build directory type:
```
cmake ..
make doc
```
After this, go to doc/html directory and open with browser "index.html".

## Complexity informations
Using [lizard](https://pypi.org/project/lizard/) library for complexity informations, in build directory type:

```

cmake ..
make cyclo

```

