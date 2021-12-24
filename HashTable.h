//
// Created by godknows on 24.12.2021.
//

#ifndef TASK7_HASHTABLE_H
#define TASK7_HASHTABLE_H

#include <iostream>
#include "AndrewContainerUtils.h"

namespace AndrewContainer {
    struct LinkedListNode {
        char id[IDENTIFIER_SIZE];
        LinkedListNode* next;
        LinkedListNode(const char* id);
    };

    class LinkedList {
    private:
        LinkedListNode* first;
    public:
        LinkedList();
        void add(const char id[IDENTIFIER_SIZE]);
        bool operator[](const char id[IDENTIFIER_SIZE]);
        friend std::ostream& operator<< (std::ostream& output, const LinkedList& list);
        ~LinkedList();
    };

    class HashTable {
    private:
        int size;
        LinkedList** buckets;
    public:
        HashTable(int table_size);
        int hash(const char id[IDENTIFIER_SIZE]);
        void add(const char id[IDENTIFIER_SIZE]);
        bool operator[](const char id[IDENTIFIER_SIZE]);
        friend std::ostream& operator<< (std::ostream& output, const HashTable& table);
        ~HashTable();
    };
    void hash_table_test(int data_count, int table_size);

}

#endif //TASK7_HASHTABLE_H
