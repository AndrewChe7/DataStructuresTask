//
// Created by godknows on 24.12.2021.
//

#ifndef TASK7_BINARYTREE_H
#define TASK7_BINARYTREE_H

#include <iostream>
#include "AndrewContainerUtils.h"

namespace AndrewContainer {
    struct BinaryTreeNode {
        char id[32];
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        BinaryTreeNode(const char _id[IDENTIFIER_SIZE]);
        friend std::ostream& operator<< (std::ostream& output, const BinaryTreeNode& node);
        ~BinaryTreeNode();
    };

    class BinaryTree {
    private:
        BinaryTreeNode *root;
    public:
        BinaryTree();
        void add(const char id[IDENTIFIER_SIZE]);
        bool operator[](const char id[IDENTIFIER_SIZE]);
        friend std::ostream& operator<< (std::ostream& output, const BinaryTree& tree);
        ~BinaryTree();
    };

    void binary_tree_test(int data_count);
}

#endif //TASK7_BINARYTREE_H
