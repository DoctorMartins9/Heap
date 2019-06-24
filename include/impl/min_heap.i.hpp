
namespace hp { 

    // Build the subtree
    template<typename T>
    void MinHeap<T>::heapify(std::vector<Node<T>> &heap, uint64_t n, int i) {
        
        int largest = i; 
        int l = 2*i + 1; 
        int r = 2*i + 2;
    
        if (l < n && heap[l].getValue() > heap[largest].getValue()) 
            largest = l; 
    
        if (r < n && heap[r].getValue() > heap[largest].getValue()) 
            largest = r;

        if (largest != i) 
        { 
            Node<T> temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            
            heapify(heap, n, largest); 
        } 
    }

    // Build the tree
    template<typename T>
    void MinHeap<T>::minHeapify(){
        
        for (int i = ( getElements() / 2 ) - 1 ; i >= 0 ; i--)
            heapify(heap , getElements() , i);
    
    }

    template<typename T>
    void MinHeap<T>::heapSort(std::vector<T> &vec){ 
        std::vector<T> res;
        uint64_t size = vec.size();
        res.reserve(size);
        MinHeap mh = MinHeap(vec);
        for(uint64_t i = 0; i < size; i++){
            
            res.insert(res.end() -i, mh[0]);
            mh.erase(0);
        }

        vec = res; 

    } 
    
    template<typename T>
    MinHeap<T>::MinHeap(std::vector<T> input) : Heap<T>(input) {
        minHeapify();
    }

    // Add an element in heap and then re-order
    template<typename T>
    void MinHeap<T>::addElement(T n){
        Heap<T>::addElement(n);
        minHeapify();
    }

    template<typename T>
    void MinHeap<T>::erase(uint64_t index) {
        heap.erase(heap.begin() + index);
        minHeapify();
    }

    template<typename T>
    void MinHeap<T>::eraseByValue(T value) {

        for(uint64_t i = 0 ; i < getElements() ; i++)
            if(heap[i].getValue() == value ){
                heap.erase(heap.begin() + i);
                i = -1;
            }
        minHeapify();
    }

    template<typename T>
    void MinHeap<T>::addVector(std::vector<T> &vec) {
        
        for(int i = 0; i < vec.size() ; i++ )
            addElement(vec[i]);
        
    }

    template<typename T>
    void MinHeap<T>::addHeap(Heap<T> &vector) {
        // TODO
    }

    template<typename T>
    MinHeap<T> MinHeap<T>::operator+(Heap<T> &input) {
        auto s = input.getVector();
        auto p = getVector();

        s.insert(s.end(), p.begin(), p.end());


        return MinHeap(s);
    }

        // Virtual cannot implement template !!
        /*
        template<typename T>
        void erase(uint64_t index){}
        template<typename T>
        void eraseByValue(T value){}
        template<typename T>
        void addVector(std::vector<T> &vec){}
        template<typename T>
        void addHeap(Heap<T> &vector){}
         */
        
}   // namespace 'heap'

