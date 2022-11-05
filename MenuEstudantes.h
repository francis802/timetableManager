//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUESTUDANTES_H
#define PROJECT_AED_MENUESTUDANTES_H


#include "Menu.h"

class MenuEstudantes: public Menu {
public:
    explicit MenuEstudantes(const GestaoHor &gestao);
    bool estudantesMenu();
    void estudantesTurmaUC(string turma, string uc, char sort);
    void estudantesAno(string ano, char sort);
    void estudantesUC(string codUC, char sort);
    void estudantesMaisDeNUCs(string n, char sort);
};


#endif //PROJECT_AED_MENUESTUDANTES_H
