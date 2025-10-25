#include <iostream>
#include "../include/CircularQueue.h" 
int main() {
    CircularQueue<int> q;

    // Enqueue 5 elementi
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
        q.print();
    }

    std::cout << "Front: " << q.front() << std::endl;

    // Dequeue 2 elementi
    std::cout << "Dequeue 2 elementi:" << std::endl;
    q.dequeue(); q.print();
    q.dequeue(); q.print();

    // Enqueue altri 3 elementi
    for (int i = 6; i <= 8; ++i) {
        q.enqueue(i);
        q.print();
    }

    // Dequeue tutti
    std::cout << "Dequeue tutti gli elementi:" << std::endl;
    while (!q.isEmpty()) {
        std::cout << "Front: " << q.front() << " -> ";
        q.dequeue();
        q.print();
    }

    return 0;
}
