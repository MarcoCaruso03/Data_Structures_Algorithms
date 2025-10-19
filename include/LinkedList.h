#include <iostream>
#include <cassert> 

template <typename T> class LinkedList{
    private: 
        // define the structure Node: a linkedlist is made by Node
        struct Node{
            T data; 
            Node * next; 
            Node(const T&value) : data(value), next(nullptr) {}
        };
        // pointer to the head of the list
        Node * head;
        size_t length;

    public:
        LinkedList();
        ~LinkedList();
        void print() const;
        void pushfront(const T& value);
        void pushback(const T& value);
        void popFront();
        void popBack();
        T& operator[](size_t index);
};

// this can also be implemented by init list : LinkedList<T>::LinkedList() : head(nullptr), length(0) {}
template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr; 
    length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    // have to delete all the pointers
    Node * current =  head; 
    while(current){
        Node * temp = current; 
        current = current->next; 
        delete temp;
    }
}

// insert in the head: a->b. If pushfront(c) => c->a->b
template <typename T>
void LinkedList<T>::pushfront(const T& value){
    // new allocation
    Node * new_node = new Node(value);
    new_node->next = head; 
    head = new_node;
    ++length;  
}

template <typename T>
void LinkedList<T>::print() const {
    Node * current = head; 
    while(current){
        std::cout<<current->data<<"->";
        current = current->next; 
    }
    std::cout << "nullptr" << std::endl;
}
template <typename T>
void LinkedList<T>::pushback(const T& value){
    
    Node * new_node = new Node(value);
    
    if(!head){ // the list is empty
        head = new_node; 
    }
    else{
        Node * current = head; 
        while(current->next){
            current = current->next; 
        }
        // the prev. while has to stopped in the last node, otherwise current will be nullptr and you cannor -> with a nullptr, will crash
        current->next = new_node;
    }
    ++length;
}

// delete the first node
template <typename T>
void LinkedList<T>::popFront(){
    if(!head){
        return; 
    }
    Node * tmp = head; 
    head = head->next; 
    delete tmp; 
    --length; 
}

// delete the last node
template <typename T>
void LinkedList<T>::popBack(){
    // empty list
    if(!head){
        return; 
    }
    // just one node
    if(!head->next){
        delete head;
        head = nullptr;
        --length;
        return;
    }
    Node * current = head; 
    // stop in the last -1 node
    while(current->next->next){
        current = current->next; 
    }
    Node * tmp = current->next; 
    delete tmp; 
    current->next = nullptr; 
    --length;

}

template <typename T>
T& LinkedList<T>::operator[](size_t index){
    assert(index < length && "Indice fuori range!");
    Node * current = head; 
    for (size_t i = 0; i<index; ++i){
        current = current->next;
    }
    return current->data;
}