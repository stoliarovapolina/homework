//#include <conio.h>

#include "io.hpp"
#include "sort.hpp"

int main() {
    const int size = 9;
    int x[size] = {10, 13, 14, 19, 23, 21, 2, 5, 1};

    /*std::cout << "" << endl;
    for (int i = 0; i < size; i++) {
        std::cout <<  x[i] << format;
    }*/
    polinom::print_arrange("Первоначальный массив:", x, size);
    
    polinom::get_interesting(x, size);
    
    /*for (int num : x) {
	const char format =  ' ';
        std::cout << num << format;
    }*/
	polinom::print_arrange("Интересно отсортированный массив:", x, size);
  //   _getch();
    return 0;
}

