//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUOCUPACAO_H
#define PROJECT_AED_MENUOCUPACAO_H

#include "Menu.h"

class MenuOcupacao: public Menu {
public:
    explicit MenuOcupacao(const GestaoHor &gestao);

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
};


#endif //PROJECT_AED_MENUOCUPACAO_H
