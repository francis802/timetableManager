
#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <string>
#include <vector>
#include "Estudante.h"
#include "GestaoHor.h"
#include <iostream>

class Menu {
private:
    GestaoHor gestao;

public:
    explicit Menu(const GestaoHor &gestao);

    void start();

    //TODO OCUPAÇÃO MENU
    bool ocupacaoMenu();
    bool ocupacaoTurmasMenu();
        int ocupacaoDeterminadaTurmaUC(string turma, string uc);
        void printOcupacaoTurmasUC(vector<pair<int,string>> ocupacao, string uc);
    bool ocupacaoAnosMenu();
        void ocupacaoDeterminadoAno(string ano);
        void ocupacaoAnos();
    bool ocupacaoUCMenu();
        void ocupacaoDeterminadaUC(std::string codUC);
        void printOcupacaoUCs(vector<pair<int,string>> ocupacao, ofstream& out);
        void ocupacaoUCs();
    vector<pair<int,string>> ocupacaoUCsAno(std::string ano);


    //TODO HORÁRIO MENU
    bool horarioMenu();
        void searchHorarioByNum();
        void searchHorarioByName();
        void printHorario(Estudante student);

    //TODO ESTUDANTES MENU
    bool estudantesMenu();
        void estudantesTurmaUC(string turma, string uc, char sort);
        void estudantesAno(string ano, char sort);
        void estudantesUC(string codUC, char sort);
        void estudantesMaisDeNUCs(string n, char sort);

    //TODO ALTERAR MENU
    bool alterarMenu();
};


#endif //PROJECT_AED_MENU_H
