#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "HashTable.h"

int main ()
{
    std::string buffer;
    std::ifstream input_file;
    input_file.open("input.txt");
    AndrewContainer::BinaryTree binaryTree;
    AndrewContainer::HashTable hashTable(10);
    if (input_file.is_open())
    {
        while (getline(input_file, buffer)) {
            binaryTree.add(buffer.c_str());
            hashTable.add(buffer.c_str());
        }
        input_file.close();
    }
    std::cout << binaryTree << std::endl << std::endl;
    std::cout << hashTable << std::endl;
    return 0;
}
