#include <ctime>
#include <random>

#include "gen.hpp"


void polinom::generate_arrange(int * const x, const int size, const int depth){
    for(int i = 0; i < size; i++) x[i] = polinom::make_random(depth);
}

void polinom::set_rand(){
    srand(time(0));
}

int polinom::make_random(const int depth){
    return rand() % depth;
}
