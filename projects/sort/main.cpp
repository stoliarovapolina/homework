#include "gen.hpp"
#include "io.hpp"
#include "sort.hpp"

int main() {
    polinom::set_rand();

    const int max_x_size = polinom::input("Введите не более какого числа будет длина массива: ");

    const int size = polinom::make_random(max_x_size);
    polinom::print("Элементов в массиве: ", size);

    int* x = new int(size);
    polinom::generate_arrange(x, size, 100000000);
    polinom::print("Исходный массив: ", x, size);

    polinom::get_interesting(x, size);
    polinom::print("Отсортированный массив: ", x, size);

    delete x;

    return 0;
}

