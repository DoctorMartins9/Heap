#include <cassert>      // Debug library        -> assert(...);
#include <iostream>     // I/O operations       -> std::cout , std::cin , ...
#include <vector>       // Vector manipulation  -> std::vector, ...

namespace heap{
    
    class Node{
    private:
        int value;

        // Set node value
        void setValue(int input){
            value = input;
        }

    public:
        // Default constructor
        Node() {}

        // Constructor by value
        Node(int i){
            setValue(i);
        }

        // Copy constructor
  /*      
        Node( Node& n){
            setValue(n.getValue());
        }
        
*/
       Node operator= (Node n){
           value = n.getValue();
       }

        // Return Node value
        int getValue(){
            return value;
        }
  
    };

    // Parent abstract class
    class Heap{

    protected:

        std::vector<Node> heap;     // Vector of elements    

        void addElement(int n){
            Node temp =  Node(n);
            heap.push_back(temp);
        }

        // To override
        virtual void erase(uint index){}
        virtual void eraseByValue(int value){}
        virtual void heapify(std::vector<Node> &heap, uint n, int i){}
        virtual void addVector(std::vector<int> &vec){}
        virtual void addHeap(Heap &vector){}

    public:
     
        // Constructors
        Heap (std::vector<int> input) {
            
            for(int i = 0; i < input.size(); i++)
                addElement(input[i]);
        }

        // Return number of elements in heap
        uint getElements(){
            return heap.size();
        }

        std::vector<int> getVector(){

            std::vector<int> vect;
            
            vect.resize(getElements());
            
            for(int i = 0; i < heap.size(); i++){
                vect[i] = heap[i].getValue();
            }

            return vect;
        }

        // "toString()" override
        friend std::ostream& operator<<(std::ostream& stream, Heap& hp){
            std::string result = "{ ";
                   
            auto heap = hp.getVector();
            for(uint i = 0 ; i < heap.size(); i++)
                result+= "(" + std::to_string(heap[i]) + ") ";
                
            result += "}";

            stream << result;
            return stream; 
        }
           
        int operator[](int n){
            
            return heap[n].getValue(); 
        }
           

    };


    class MaxHeap : public Heap {

    private:

      
  

        // Build the subtree
        void heapify(std::vector<Node> &heap, uint n, int i) override {
            
            int largest = i; 
            int l = 2*i + 1; 
            int r = 2*i + 2;
        
            if (l < n && heap[l].getValue() > heap[largest].getValue()) 
                largest = l; 
        
            if (r < n && heap[r].getValue() > heap[largest].getValue()) 
                largest = r;

            if (largest != i) 
            { 
                Node temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                
                heapify(heap, n, largest); 
            } 
        }

        // Build the tree
        void MaxHeapify(){
            for (int i = (getElements() / 2) - 1 ; i >= 0 ; i--)
                heapify(heap, getElements(), i);            
        }


    public:

        static void heapSort(std::vector<int> &vec){ 
            std::vector<int> res;
            uint size = vec.size();
            res.reserve(size);
            MaxHeap mh = MaxHeap(vec);
            for(uint i = 0; i < size; i++){
                
                res.insert(res.end() -i, mh[0]);
                mh.erase(0);
            }

            vec =res; 

        } 
        
        MaxHeap(std::vector<int> input) : Heap(input) {
            MaxHeapify();
        }

        // Add an element in heap and then re-order
        bool addElement(int n){
            Node temp =  Node(n);
            heap.push_back(temp);
            MaxHeapify();
        }

        void erase(uint index) override {
            heap.erase(heap.begin() + index);
            MaxHeapify();
        }

        void eraseByValue(int value) override {

            for(uint i = 0 ; i < getElements() ; i++)
                if(heap[i].getValue() == value ){
                    heap.erase(heap.begin() + i);
                    i = -1;
                }
            MaxHeapify();
        }

        void addVector(std::vector<int> &vec) override {
            
            for(int i = 0; i < vec.size() ; i++ )
                addElement(vec[i]);
            
        }

        MaxHeap operator+(Heap &input) {
            auto s = input.getVector();
            auto p = getVector();

            s.insert(s.end(), p.begin(), p.end());


            return MaxHeap(s);
        }

    };

}   // namespace 'heap'Node

int main(){

    std::vector<int> heap;

    for(int i = 0; i < 10 ; i++)
        heap.push_back(10 - i); 


    for(int i =  0; i < heap.size(); i++){
        printf("%i ", heap[i]);
    }

    printf("\n");

   
    //heap::MaxHeap mc = heap::MaxHeap(heap);
    heap::MaxHeap::heapSort(heap);

    for(int i =  0; i < heap.size(); i++){
            printf("%i ", heap[i]);
        }
  printf("\n");

   /* std::cout << mc << std::endl;

    std::vector<int> heap2;

    for(int i = 10; i < 20 ; i++)
        heap2.push_back(15);

    heap::MaxHeap mc2 = heap::MaxHeap(heap2);
    
    std::cout << mc2 << std::endl;

    heap::MaxHeap mc3 = mc + mc2;

    std::cout << mc3 << std::endl;*/




    return 0;
}