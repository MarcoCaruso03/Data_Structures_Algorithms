#include "../include/Stack.h"
#include <iostream>

int main() {
    Stack<int> s;

    std::cout << "Stack test\n";

    std::cout << "\nPushing elements: 10, 20, 30\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Current stack: ";
    s.print();

    std::cout << "Top element: " << s.top() << "\n";

    std::cout << "\nPopping top element\n";
    s.pop();
    std::cout << "Current stack: ";
    s.print();
    std::cout << "Top element now: " << s.top() << "\n";

    std::cout << "\nPopping all elements\n";
    while(!s.isEmpty()) {
        std::cout << "Top: " << s.top() << " -> popping\n";
        s.pop();
    }

    std::cout << "Stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}