#ifndef PROJECT_AED_GESTAOHOR_H
#define PROJECT_AED_GESTAOHOR_H

#include <set>
#include <fstream>
#include <sstream>
#include <queue>
#include "Estudante.h"
#include "Pedido.h"

using namespace std;

class GestaoHor{
public:
    GestaoHor();

    void addStudent(Estudante s);
    void getDataStudent(string filename1, string filename2);
    void getDataAula(string filename);
    const set<Estudante> &getStudents() const;
    vector<pair<int,string>> ocupacaoTurmasUC(string uc);
    void addPedidos(pair<char,Pedido> pedido);
    void processPedidos();

private:
    set<UCTurma> aulas;
    set<Estudante> students;
    queue<pair<char,Pedido>> pedidos;
    list<pair<char,Pedido>> failed;
    const static int cap = 30;
};

#endif //PROJECT_AED_GESTHOR_H
