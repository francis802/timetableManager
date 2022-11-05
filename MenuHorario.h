//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUHORARIO_H
#define PROJECT_AED_MENUHORARIO_H


#include "Estudante.h"
#include "Menu.h"

class MenuHorario: public Menu {
public:
    explicit MenuHorario(const GestaoHor &gestao);
    bool horarioMenu();
    void searchHorarioByNum();
    void searchHorarioByName();
    void searchHorarioTurma();
    void printHorario(Estudante student);
};


#endif //PROJECT_AED_MENUHORARIO_H
