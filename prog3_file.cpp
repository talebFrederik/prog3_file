// prog3_file.cpp
//

#include "NodeQueue.h"
#include <iostream>

int main()
{
    NodeQueue file;

    file.enqueue(67);
    file.enqueue(39);
    file.enqueue(83);
    file.enqueue(42);
    std::cout << "Premier element : " << file.getFront() << "\n";
    std::cout << "Dernier element : " << file.getBack() << "\n";
    std::cout << "La file : \n";
    file.afficherFile();

    file.dequeue();
    std::cout << "\n\nLa file avec 1 element de moins : \n";
    file.afficherFile();

    std::cout << "\n\nVider la file\n";
    while(!file.isEmpty())
    {
        file.dequeue();
    }

    std::cout << "\nEssayer front, back et dequeue avec une file vide : \n";
    file.getFront();
    file.getBack();
    file.dequeue();
}


