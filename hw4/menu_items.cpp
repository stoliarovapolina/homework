#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const polinom::MenuItem polinom::STUDY_DUB = {
    "1 - Хочу \"Дубровского\"!", polinom::study_dub, &polinom::STUDY_SUMM
};
const polinom::MenuItem polinom::STUDY_ONEGIN = {
    "2 - Хочу \"Евгения Онегина\"!", polinom::study_onegin, &polinom::STUDY_SUMM
};
const polinom::MenuItem polinom::STUDY_EVENING = {
    "3 - Хочу \"Зимний вечер\"!", polinom::study_evening, &polinom::STUDY_SUMM
};
const polinom::MenuItem polinom::STUDY_BACK = {
    "0 - Выйти в главное меню", polinom::study_go_back, &polinom::STUDY_SUMM
};

namespace {
    const polinom::MenuItem* const study_childrens[] = {
        &polinom::STUDY_BACK,
        &polinom::STUDY_DUB,
        &polinom::STUDY_ONEGIN,
        &polinom::STUDY_EVENING
    };
    const int study_size2 = sizeof(study_childrens) / sizeof(study_childrens[0]);
}

const polinom::MenuItem polinom::STUDY_SUMM = {
    "1 - Читать Пушкина!", polinom::study_summ, &polinom::STUDY, study_childrens,study_size2
};
const polinom::MenuItem polinom::STUDY_SUBSTRACT = {
    "2 - Читать Лермонтова!", polinom::study_substract, &polinom::STUDY
};
const polinom::MenuItem polinom::STUDY_MULTIPLY = {
    "3 - Читать Крылова!", polinom::study_multiply, &polinom::STUDY
};
const polinom::MenuItem polinom::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", polinom::study_go_back, &polinom::STUDY
};

namespace {
    const polinom::MenuItem* const study_children[] = {
        &polinom::STUDY_GO_BACK,
        &polinom::STUDY_SUMM,
        &polinom::STUDY_SUBSTRACT,
        &polinom::STUDY_MULTIPLY,
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const polinom::MenuItem polinom::STUDY = {
    "1 - Русские писатели!", polinom::show_menu, &polinom::MAIN, study_children, study_size
};
const polinom::MenuItem polinom::EXIT = {
    "0 - Я не умею читать...", polinom::exit, &polinom::MAIN
};

namespace {
    const polinom::MenuItem* const main_children[] = {
        &polinom::EXIT,
        &polinom::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const polinom::MenuItem polinom::MAIN = {
    nullptr, polinom::show_menu, nullptr, main_children, main_size
};