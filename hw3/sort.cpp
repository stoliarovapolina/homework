#include <iostream>
<<<<<<< HEAD
#include "sort.hpp"

void polinom::get_interesting(int* x, const int size) {   
=======
void get_interesting(int* x, const int size) {   
>>>>>>> d282728985ab3ba0030d015dbf72cf9aa3251643
    for (int i = 2; i < size; i++) {
        if (x[i - 2] < x[i - 1] && x[i - 1] < x[i]) {
            std::swap(x[i - 1], x[i]);
        } else if (x[i - 2] > x[i - 1] && x[i - 1] > x[i]) {
            std::swap(x[i - 1], x[i]);
        }
    }
}
