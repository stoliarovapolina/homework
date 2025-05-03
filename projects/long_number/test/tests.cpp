#include <iostream>
#include "long_number.hpp"

int main() {
    polinom::LongNumber num1("12345");
    polinom::LongNumber num2("67890");
    polinom::LongNumber sum = num1 + num2;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}