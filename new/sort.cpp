#include <iostream>
#include "sort.hpp"

void polinom::get_interesting(int* const x, const int size) {   
    for (int i = 2; i < size; i++) {
        if (x[i - 2] < x[i - 1] && x[i - 1] < x[i]) {
            std::swap(x[i - 1], x[i]);
        } else if (x[i - 2] > x[i - 1] && x[i - 1] > x[i]) {
            std::swap(x[i - 1], x[i]);
        }
    }
}
