//
// Created by godknows on 24.12.2021.
//

#include "BinaryTree.h"
#include <cstring>


namespace AndrewContainer {

    BinaryTreeNode::BinaryTreeNode(const char *_id) {
        memcpy(id, _id, IDENTIFIER_SIZE);
        left = nullptr;
        right = nullptr;
    }

    BinaryTreeNode::~BinaryTreeNode() {
        delete left;
        delete right;
    }

    std::ostream &operator<<(std::ostream &output, const BinaryTreeNode &node) {
        if (node.left != nullptr)
            output << *node.left << std::endl;

        char id_with_zero[IDENTIFIER_SIZE + 1];
        memcpy(id_with_zero, node.id, 32);
        id_with_zero[IDENTIFIER_SIZE] = 0;
        output << id_with_zero;

        if (node.right != nullptr)
            output << std::endl << *node.right;
        return output;
    }

    BinaryTree::BinaryTree() {
        root = nullptr;
    }

    BinaryTree::~BinaryTree() {
        delete root;
    }

    void BinaryTree::add(const char *id) {
        auto* newNode = new BinaryTreeNode(id);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        BinaryTreeNode* current = root;
        while  (((compare_identifiers(id, current->id) > 0) && (current->right != nullptr)) ||
                ((compare_identifiers(id, current->id) < 0) && (current->left != nullptr))) {
            if (compare_identifiers(id, current->id) > 0) {
                current = current->right;
            } else if (compare_identifiers(id, current->id) < 0) {
                current = current->left;
            }
        }
        if (compare_identifiers(id, current->id) > 0) {
            current->right = newNode;
        } else if (compare_identifiers(id, current->id) < 0) {
            current->left = newNode;
        } else {
            delete newNode;
        }
    }

    bool BinaryTree::operator[](const char *id) {
        if (root == nullptr)
            return false;
        auto* current = root;
        while (((compare_identifiers(id, current->id) > 0) && (current->right != nullptr)) ||
               ((compare_identifiers(id, current->id) < 0) && (current->left != nullptr))) {
            if (compare_identifiers(id, current->id) > 0) {
                current = current->right;
            } else if (compare_identifiers(id, current->id) < 0) {
                current = current->left;
            }
        }
        if (compare_identifiers(id, current->id) == 0) {
            return true;
        }
        return false;
    }

    std::ostream &operator<<(std::ostream &output, const BinaryTree &tree) {
        if (tree.root == nullptr)
        {
            output << "Tree is empty" << std::endl;
        } else {
            output << *tree.root;
        }
        return output;
    }
}


