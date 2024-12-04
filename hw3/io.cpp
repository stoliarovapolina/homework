#include "io.hpp"

#include <iostream>

void polinom::print(const char* const comment, const int integer){
    switch (integer > -1)
    {
    case true:
        std::cout << comment << integer << std::endl;        
        break;
    
    default:
        std::cout << comment << std::endl;
        break;
    }
}

void polinom::print_arrange(const char* const comment, const int* const arr,  const int length){
    std::cout << comment;
    for(int i = 0; i < length; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}
