#include <iostream>
void get_interesting(int* x, const int size) {   
    for (int i = 2; i < size; i++) {
        if (x[i - 2] < x[i - 1] && x[i - 1] < x[i]) {
            std::swap(x[i - 1], x[i]);
        } else if (x[i - 2] > x[i - 1] && x[i - 1] > x[i]) {
            std::swap(x[i - 1], x[i]);
        }
    }
}
