//
// Created by francis802 on 28-10-2022.
//

#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <string>
#include "Estudante.h"
#include "GestaoHor.h"
#include <iostream>

class Menu {
private:
    GestaoHor gestao;
public:
    explicit Menu(const GestaoHor &gestao);

    void start();

    int ocupacaoDeterminadaTurmaUC(string turma, string uc);
    void ocupacaoTurmasUC(string uc);
    bool ocupacaoTurmasMenu();
    void ocupacaoDeterminadoAno(string ano);
    void ocupacaoAnos();
    bool ocupacaoAnosMenu();
    void ocupacaoDeterminadaUC(std::string codUC);
    void ocupacaoUCsAno(std::string ano);
    void ocupacaoUCs();
    bool ocupacaoUCMenu();
    bool ocupacaoMenu();
    void printHorario(Estudante student);
    void searchHorarioByNum();
    void searchHorarioByName();
    bool horarioMenu();
    void estudantesTurmaUC(string turma, string uc);
    void estudantesAno(string ano);
    void estudantesUC(string codUC);
    bool estudantesMenu();
    bool alterarMenu();
};


#endif //PROJECT_AED_MENU_H
