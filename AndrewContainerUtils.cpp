//
// Created by godknows on 24.12.2021.
//

#include "AndrewContainerUtils.h"

namespace AndrewContainer {
    int compare_identifiers(const char* left, const char* right) {
        int i;
        for (i = 0; i < IDENTIFIER_SIZE; i++) {
            if (left[i] > right[i])
            {
                return 1;
            }
            if (left[i] < right[i]) {
                return -1;
            }
        }
        return 0;
    }
    int random_id_generator(char* id) {
        for (char* i = id; i < id + IDENTIFIER_SIZE; i++)
        {
            *i = 'A' + (random() % 26);
        }
        return 0;
    }
}