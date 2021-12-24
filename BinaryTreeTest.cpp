//
// Created by godknows on 24.12.2021.
//

#include "BinaryTree.h"

namespace AndrewContainer {
    void binary_tree_test(int data_count)
    {
        char data[data_count * IDENTIFIER_SIZE];
        BinaryTree tree;
        std::cout << "Starting binary tree test." << std::endl << "Random generated input data:" << std::endl;
        for (char* i = data; i < data + data_count * IDENTIFIER_SIZE; i+=IDENTIFIER_SIZE)
        {
            random_id_generator(i);
            printf("%.*s\n", IDENTIFIER_SIZE, i);
            tree.add(i);
        }
        std::cout << std::endl << "Sorted data in binary tree:" << std::endl;
        std::cout << tree;
    }
}
