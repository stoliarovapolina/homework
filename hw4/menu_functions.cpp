#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const polinom::MenuItem* polinom::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}
const polinom::MenuItem* polinom::study_summ(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const polinom::MenuItem* polinom::exit(const MenuItem* current) {
    std::exit(0);
}



const polinom::MenuItem* polinom::study_substract(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const polinom::MenuItem* polinom::study_multiply(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const polinom::MenuItem* polinom::study_divide(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const polinom::MenuItem* polinom::study_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}
const polinom::MenuItem* polinom::study_dub(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const polinom::MenuItem* polinom::study_onegin(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const polinom::MenuItem* polinom::study_evening(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
