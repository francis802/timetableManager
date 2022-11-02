#ifndef PROJECT_AED_GESTAOHOR_H
#define PROJECT_AED_GESTAOHOR_H

#include <set>
#include <fstream>
#include <sstream>
#include <queue>
#include "Estudante.h"

using namespace std;

class GestaoHor{
public:
    GestaoHor();

    void addStudent(Estudante s);
    void getDataStudent(string filename1, string filename2);
    list<UCTurma> getDataAula(string filename);
    const set<Estudante> &getStudents() const;
    void addPedidos(pair<char,string> pedido);
    void processPedidos();

private:
    set<Estudante> students;
    queue<pair<char,string>> pedidos;
};

#endif //PROJECT_AED_GESTHOR_H
