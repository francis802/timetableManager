
#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <string>
#include <vector>
#include "Estudante.h"
#include "GestaoHor.h"
#include <iostream>

class Menu {
protected:
    GestaoHor gestao;

public:
    explicit Menu(const GestaoHor &gestao);

    void start();

    //TODO ALTERAR MENU
    bool alterarMenu();
};


#endif //PROJECT_AED_MENU_H
