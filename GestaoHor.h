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

    struct cmp {
        bool operator()(const Estudante lhs, const Estudante rhs) const{
            return lhs.getName() < rhs.getName();
        }
    };
    void addStudent(Estudante s);
    void getDataStudent(string filename1, string filename2);
    void getDataAula(string filename);
    const set<Estudante> &getStudents() const;
    const set<Estudante, cmp> &getStudentsByname() const;
    const set<UCTurma> &getAulas() const;

    void setAulas(const set<UCTurma> &aulas);

    vector<pair<int,string>> ocupacaoTurmasUC(string uc);
    void addPedidos(vector<pair<char,Pedido>> pedido);
    void processPedidos();

    bool classConflict(Estudante estudante, UCTurma new_uct);

    void removeStudentUCClass(Pedido pedido);
    bool addStudentUCClass(Pedido pedido);
private:
    set<UCTurma> aulas;
    set<Estudante> students;
    set<Estudante, cmp>students_byname;
    queue<vector<pair<char,Pedido>>> pedidos;
    list<vector<pair<char,Pedido>>> failed;
    const static int cap = 30;

};

#endif //PROJECT_AED_GESTHOR_H
