
namespace heap{

    template<typename T>
    void Heap<T>::addElement(T n){
        Node<T> temp =  Node<T>(n);
        heap.push_back(temp);
    }

    // Constructors
    template<typename T>
    Heap<T>::Heap (std::vector<T> input) {
        
        for(uint i = 0; i < input.size(); i++)
            addElement(input[i]);
    }

    // Return number of elements in heap
    template<typename T>
    uint Heap<T>::getElements(){
        return heap.size();
    }

    template<typename T>
    std::vector<T> Heap<T>::getVector(){

        std::vector<T> vect;
        
        vect.resize(getElements());
        
        for(uint i = 0; i < heap.size(); i++){
            vect[i] = heap[i].getValue();
        }

        return vect;
    }

    // "toString()" override
    template<typename T>
    std::ostream& operator<<(std::ostream& stream, Heap<T>& hp){
        std::string result = "{ ";
                
        auto heap = hp.getVector();
        for(uint i = 0 ; i < heap.size(); i++)
            result+= "(" + std::to_string(heap[i]) + ") ";
            
        result += "}";

        stream << result;
        return stream; 
    }

    template<typename T>
    T Heap<T>::operator[](T n){
        
        return heap[n].getValue(); 
    }

} // namespace 'heap'Node
