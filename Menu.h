
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

    int ocupacaoDeterminadaTurmaUC(string turma, string uc);
    void printOcupacaoTurmasUC(vector<pair<int,string>> ocupacao, string uc);
    bool ocupacaoTurmasMenu();
    void ocupacaoDeterminadoAno(string ano);
    void ocupacaoAnos();
    bool ocupacaoAnosMenu();
    void ocupacaoDeterminadaUC(std::string codUC);
    void printOcupacaoUCs(vector<pair<int,string>> ocupacao, ofstream& out);
    vector<pair<int,string>> ocupacaoUCsAno(std::string ano);
    void ocupacaoUCs();
    bool ocupacaoUCMenu();
    bool ocupacaoMenu();
    void printHorario(Estudante student);
    void searchHorarioByNum();
    void searchHorarioByName();
    bool horarioMenu();
    void estudantesTurmaUC(string turma, string uc, char sort);
    void estudantesAno(string ano, char sort);
    void estudantesUC(string codUC, char sort);
    bool estudantesMenu();
    bool alterarMenu();
};


#endif //PROJECT_AED_MENU_H
