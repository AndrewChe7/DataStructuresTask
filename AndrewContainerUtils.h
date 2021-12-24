//
// Created by godknows on 24.12.2021.
//

#ifndef TASK7_ANDREWCONTAINERUTILS_H
#define TASK7_ANDREWCONTAINERUTILS_H
#define IDENTIFIER_SIZE 32
#include <random>

namespace AndrewContainer {
    int compare_identifiers(const char* left, const char* right);
    int random_id_generator(char* id);
}

#endif //TASK7_ANDREWCONTAINERUTILS_H
