#include <iostream>
#include "sort.hpp"

int main() {
    const int size = 9;
    int x[size] = {10, 13, 14, 19, 23, 21, 2, 5, 1};
   
    for (int i = 0; i < size; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    
    get_interesting(x, size);
    
    for (int num : x) {
        std::cout << num << " ";
    }
    return 0;
}

