#include "hashtable.h"
#include <cmath>

#define OVERFLOW_SIZE 10

int naive_hashing::operator()(char* str, int N) {
    if (str == NULL) return 0;
    else return (str[0] + N) % N;
}

int bad_hashing::operator()(char* str, int N) {
    if (str == NULL)
        return 0;

    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        hash_value += str[i] * str[i];
    }

    return hash_value % N;
}

int good_hashing::operator()(char* str, int N) {
    if (str == NULL)
        return 0;

    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        hash_value = (hash_value * 151) + str[i];
    }

    return (hash_value & 0x7FFFFFFF) % N;
}

int linear_probe::operator()(hash_entry* Table, int table_size, int last_choice) {
    return (last_choice + 1) % table_size;
}

void linear_probe::init() {
    return;
}

int double_probe::operator()(hash_entry* Table, int table_size, int last_choice) {
    if (index == 0) {
        index++;
        return (index + last_choice) % table_size;
    } else if (index > 0) {
        index = -index;
        return (last_choice - 1 * index * index + table_size) % table_size;
    } else {
        index = -index + 1;
        return (last_choice + index * index) % table_size;
    }
    return 0;
}

void double_probe::init() {
    index = 0;
    return;
}

int overflow_probe::operator()(hash_entry* Table, int table_size, int last_choice) {
    index++;
    index %= table_size;
    return index + table_size;
}

void overflow_probe::init() {
    index = -1;
    return;
}