#include <iostream>
#include "queuearray.h"

int main() {
    qarray<int> q(5);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    qarray<int> q2 = q;   // copy constructor
    q2.Dequeue();

    std::cout << "q size: " << q.Size() << std::endl;
    std::cout << "q2 size: " << q2.Size() << std::endl;

    qarray<int> q3(2);
    q3 = q;                // copy assignment

    std::cout << "q3 size: " << q3.Size() << std::endl;
    std::cout << "q3 front: " << q3.Front() << std::endl;

    return 0;
}