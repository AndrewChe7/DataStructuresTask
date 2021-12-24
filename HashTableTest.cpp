//
// Created by godknows on 24.12.2021.
//

#include "HashTable.h"

namespace AndrewContainer {
    void hash_table_test(int data_count, int table_size) {
        char data[data_count * IDENTIFIER_SIZE];
        HashTable hashTable(table_size);
        std::cout << "Starting hash table test." << std::endl << "Random generated input data:" << std::endl;
        for (char* i = data; i < data + data_count * IDENTIFIER_SIZE; i+=IDENTIFIER_SIZE)
        {
            random_id_generator(i);
            printf("%.*s\n", IDENTIFIER_SIZE, i);
            hashTable.add(i);
        }
        std::cout << std::endl << "Data in hash table" << std::endl;
        std::cout << hashTable;
    }
}