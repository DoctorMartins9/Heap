#include <cassert>  // For debug only   -> assert(result == ...);
#include <iostream>
#include <vector>

namespace max_heap{
    
    class Node{
        
    public:
        int index;
        int value;

        Node() {}

        Node(int i){
            value = i;
        } 
        
        
  
    };

    class MaxHeap {
    private:
      
        uint elements;


        void heapify(std::vector<Node> &heap, uint n, int i){
            int largest = i; // Initialize largest as root 
            int l = 2*i + 1; // left = 2*i + 1 
            int r = 2*i + 2; // right = 2*i + 2 
       
            // If left child is larger than root 
            if (l < n && heap[l].value > heap[largest].value) 
                largest = l; 
        
            // If right child is larger than largest so far 
            if (r < n && heap[r].value > heap[largest].value) 
                largest = r;

                //printf("SWAPPATI %i con %i\n",i, largest); 
        
            // If largest is not root 
            if (largest != i) 
            { 
                Node temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                
        
                // Recursively heapify the affected sub-tree 
                heapify(heap, n, largest); 

            } 
        }

        void MaxHeapify(){
         for (int i = elements / 2 - 1; i >= 0; i--)
                heapify(heap, elements, i);
            }

    public:

        std::vector<Node> heap;
        MaxHeap(std::vector<Node> input) : heap(input){
            elements = input.size();
            MaxHeapify();
        }

        uint getElements(){
            return elements;
        }
        
        bool addElement(int n){
            Node temp =  Node(n);

            heap.push_back(temp);
            elements++;
            MaxHeapify();
        }

        
    };

}


int main(){

    std::vector<max_heap::Node> heap;
    heap.resize(10);
    for(int i = 0 ; i < 10; i++ ){
        heap[i].value = i;
    }

    max_heap::MaxHeap mh = max_heap::MaxHeap(heap);

    for(int i = 0 ; i < 10; i++ ){
        printf("%i\n", mh.heap[i].value);
    }
    printf("\n\n\n\n");
    mh.addElement(10);


   for(int i = 0 ; i < 11; i++ ){
        printf("%i\n", mh.heap[i].value);
    }


    mh.addElement(-15);
    printf("\n\n");

   for(int i = 0 ; i < 12; i++ ){
        printf("%i\n", mh.heap[i].value);
    }



    return 0;
}