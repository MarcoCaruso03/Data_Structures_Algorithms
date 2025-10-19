#include "../include/LinkedList.h"
#include <iostream>
#include <string>

int main(){
    // declaration of a linkedlist of integer
    LinkedList<int> l;

    // pushfront 
    l.pushfront(5);
    l.pushfront(1);
    // pushback
    l.pushback(3);

    // print 
    std::cout << "Lista: ";
    l.print(); //1->5->3->nullptr

    //popback 
    l.popBack();
    std::cout << "Lista after pop back: ";
    l.print(); //1->5->nullptr

    //popfront
    l.popFront();
    std::cout << "Lista after pop front: ";
    l.print(); //5->nullptr

    l.pushback(4);
    l.pushback(5);
    l.pushback(6);

    std::cout << "Lista: ";
    l.print(); //5->4->5->6->nullptr
    std::cout<<"Test operator: [1]: "<<l[1]<<std::endl; //4
    return 0;
}