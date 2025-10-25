#include <iostream>
#include <cassert>  // for assert()

template <typename T> class DynamicArray{
    private: 
        T * data; //dynamic array
        int length; // current # of elements
        int capacity; // allocated space

    public:
        DynamicArray(); // constructor 
        ~DynamicArray(); // destructor

        void resize(int new_capacity);
        void pushBack(const T& value);
        void popBack();
        T& operator[](size_t index);
        const T& operator[](size_t index) const; // for const object
        int size() const;
        int getCapacity() const;
        void print() const;

};


// Constructor 
template <typename T>
DynamicArray<T>::DynamicArray() {
    capacity = 2;           // init capacity
    length = 0;             // no data scored
    data = new T[capacity]; // array allocation
}

// Destructor
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data; // libera memoria
}

// Access operator, in this way we can controll the access and do the safety check
template <typename T>
T& DynamicArray<T>::operator[](size_t index){
    assert(index < length && "Indice fuori range!");
    return data[index];
}

// Resize 
template <typename T>
void DynamicArray<T>::resize(int new_capacity){
    // create a new array
    T * new_array = new T[new_capacity];
    for(int i=0; i<length; i++){
        // copy the old data
        new_array[i]=data[i];
    }
    // deallocate the old array 
    delete [] data; 
    data = new_array; 
    capacity = new_capacity;
}

// PushBack 
template <typename T>
void DynamicArray<T>::pushBack(const T& value){
    // check if I can add the element, if not resize
    if(length == capacity){
        // resize: double the capacity
        resize(capacity*2);
    }
    data[length]=value; 
    ++length; 
}

// Popback 
template <typename T>
void DynamicArray<T>::popBack(){
    assert(length > 0 && "popBack on empty array!");
    --length;
}

// Size 
template <typename T>
int DynamicArray<T>::size() const{
    return length;
}

// Capacity 
template <typename T>
int DynamicArray<T>::getCapacity() const {
    return capacity;
}

// Print 
template <typename T>
void DynamicArray<T>::print() const{
    for (int i=0; i<length; i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    assert(index < length && "Indice fuori range!");
    return data[index];
}
