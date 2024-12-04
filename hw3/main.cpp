<<<<<<< HEAD
//#include <conio.h>

#include "io.hpp"
=======
#include <iostream>
>>>>>>> d282728985ab3ba0030d015dbf72cf9aa3251643
#include "sort.hpp"

int main() {
    const int size = 9;
    int x[size] = {10, 13, 14, 19, 23, 21, 2, 5, 1};
<<<<<<< HEAD

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
=======
   
    for (int i = 0; i < size; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    
    get_interesting(x, size);
    
    for (int num : x) {
        std::cout << num << " ";
    }
>>>>>>> d282728985ab3ba0030d015dbf72cf9aa3251643
    return 0;
}

