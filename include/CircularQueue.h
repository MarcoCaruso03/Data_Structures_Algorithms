#include <iostream>
#include <cassert>

template <typename T>
class CircularQueue {
private:
    T* arr;           // Pointer to the array storing queue elements
    size_t capacity;  // Maximum capacity of the array
    size_t head;      // Index of the first element (front)
    size_t tail;      // Index of the next free slot (where new element will be added)
    size_t count;     // Current number of elements in the queue

    // Doubles the capacity of the queue when it becomes full
    void resizeQueue() {
        size_t new_capacity = capacity * 2;
        T* new_arr = new T[new_capacity];

        // Copy elements in FIFO order into the new array
        for (size_t i = 0; i < count; ++i) {
            new_arr[i] = arr[(head + i) % capacity]; // handle wrap-around
        }

        delete[] arr;       // free old memory
        arr = new_arr;      // point to new array
        capacity = new_capacity;
        head = 0;           // reset head to start of new array
        tail = count;       // tail points to next free slot
    }

public:
    // Constructor: initializes the queue with a default or given initial capacity
    CircularQueue(size_t init_capacity = 4)
        : capacity(init_capacity), head(0), tail(0), count(0) {
        arr = new T[capacity]; // allocate memory for the array
    }

    // Destructor: free allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() const { return count == 0; }

    // Check if the queue is full
    bool isFull() const { return count == capacity; }

    // Add an element at the tail of the queue
    void enqueue(const T& value) {
        if (isFull()) resizeQueue(); // resize if full
        arr[tail] = value;           // insert element
        tail = (tail + 1) % capacity; // move tail forward, wrap-around if necessary
        ++count;                     // increase element count
    }

    // Remove the element at the front of the queue
    void dequeue() {
        assert(!isEmpty() && "dequeue on empty queue");
        head = (head + 1) % capacity; // move head forward, wrap-around if necessary
        --count;                       // decrease element count
    }

    // Access the element at the front of the queue
    T& front() {
        assert(!isEmpty() && "front on empty queue");
        return arr[head];
    }

    // Access the front element for a const queue
    const T& front() const {
        assert(!isEmpty() && "front on empty queue");
        return arr[head];
    }

    // Print the elements of the queue in FIFO order
    void print() const {
        std::cout << "Queue: ";
        for (size_t i = 0; i < count; ++i) {
            std::cout << arr[(head + i) % capacity] << " "; // handle wrap-around
        }
        std::cout << std::endl;
    }
};
