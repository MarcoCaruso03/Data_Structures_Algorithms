#include "../include/DynamicArray.h"
#include <iostream>
#include <string>

int main() {
    // --- Test con int ---
    DynamicArray<int> arr;

    std::cout << "Inserimento elementi (int):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        arr.pushBack(i * 10);
        arr.print(); // stampa dopo ogni inserimento
    }

    std::cout << "Accesso tramite operator[]:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Rimozione elementi:" << std::endl;
    arr.popBack();
    arr.popBack();
    arr.print();

    std::cout << "Size: " << arr.size() << ", Capacity: " << arr.getCapacity() << std::endl;

    // --- Test con std::string ---
    DynamicArray<std::string> strArr;
    strArr.pushBack("Hello");
    strArr.pushBack("World");
    strArr.pushBack("DynamicArray");

    std::cout << "\nElementi stringa:" << std::endl;
    strArr.print();

    std::cout << "Accesso singolo: " << strArr[1] << std::endl; // deve stampare "World"

    return 0;
}
