#include "io.hpp"

#include <iostream>

int polinom::input(const char* const comment){
    polinom::print(comment);
    int size;
    std::cin >> size;
    return size;
}

void polinom::print(const char* const comment, const int integer){
        std::cout << comment << integer << std::endl;        
}
void polinom::print(const char* const comment){
    std::cout << comment << std::endl;
}

void polinom::print(const char* const comment, const int* const x,  const int length){
    std::cout << comment;
    for(int i = 0; i < length; i++) std::cout << x[i] << ' ';
    std::cout << std::endl;
}
