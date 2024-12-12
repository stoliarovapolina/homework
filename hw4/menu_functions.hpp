#pragma once

#include "menu.hpp"

namespace polinom {
    extern const MenuItem* show_menu(const MenuItem* current);

    extern const MenuItem* exit(const MenuItem* current);

    extern const MenuItem* study_summ(const MenuItem* current);
    extern const MenuItem* study_substract(const MenuItem* current);
    extern const MenuItem* study_multiply(const MenuItem* current);
    extern const MenuItem* study_divide(const MenuItem* current);
    extern const MenuItem* study_go_back(const MenuItem* current);

    extern const MenuItem* study_dub(const MenuItem* current);
    extern const MenuItem* study_onegin(const MenuItem* current);
    extern const MenuItem* study_evening(const MenuItem* current);
}