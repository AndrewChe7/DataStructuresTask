//
// Created by godknows on 24.12.2021.
//

#include "HashTable.h"
#include <cstring>

namespace AndrewContainer {

    LinkedListNode::LinkedListNode(const char *id) {
        memcpy(this->id, id, IDENTIFIER_SIZE);
        next = nullptr;
    }

    LinkedList::LinkedList() {
        first = nullptr;
    }

    void LinkedList::add(const char *id) {
        auto* newNode = new LinkedListNode(id);
        if (first == nullptr)
        {
            first = newNode;
            return;
        }
        auto* current = first;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    bool LinkedList::operator[](const char *id) {
        if (first == nullptr)
        {
            return false;
        }
        auto* current = first;
        while (compare_identifiers(current->id, id) != 0 && current->next != nullptr)
            current = current->next;
        if (compare_identifiers(current->id, id) == 0)
        {
            return true;
        }
        return false;
    }

    std::ostream &operator<<(std::ostream &output, const LinkedList &list) {
        for (auto* i = list.first; i != nullptr; i = i->next) {
            char identifier_with_zero[IDENTIFIER_SIZE + 1];
            memcpy(identifier_with_zero, i->id, IDENTIFIER_SIZE);
            identifier_with_zero[IDENTIFIER_SIZE] = 0;
            output << identifier_with_zero << std::endl;
        }
        return output;
    }

    LinkedList::~LinkedList() {
        if (first == nullptr)
            return;
        auto* current = first;
        LinkedListNode* prev;
        while (current != nullptr)
        {
            prev = current;
            current = current->next;
            delete prev;
        }
    }

    HashTable::HashTable(int table_size) {
        size = table_size;
        buckets = new LinkedList*[table_size];
        for (auto* i = buckets; i < buckets + table_size; i++) {
            *i = nullptr;
        }
    }

    int HashTable::hash(const char *id) {
        int res = 0;
        for (char* i = (char*)id; i < id + IDENTIFIER_SIZE; i++) {
            res += *i;
        }
        res %= size;
        return res;
    }

    void HashTable::add(const char *id) {
        int hashed_id = hash(id);
        if (buckets[hashed_id] == nullptr)
            buckets[hashed_id] = new LinkedList;
        buckets[hashed_id]->add(id);
    }

    bool HashTable::operator[](const char *id) {
        int hashed_id = hash(id);
        if (buckets[hashed_id] == nullptr)
            return false;
        return (*buckets[hashed_id])[id];
    }

    std::ostream &operator<<(std::ostream &output, const HashTable &table) {
        for (int i = 0; i < table.size; i++)
        {
            if (table.buckets[i] != nullptr) {
                output << *table.buckets[i];
            }
        }
        return output;
    }

    HashTable::~HashTable() {
        for (int i = 0; i < size; i++) {
            delete buckets[i];
        }
    }
}
