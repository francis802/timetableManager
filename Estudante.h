#ifndef PROJECT_AED_ESTUDANTE_H
#define PROJECT_AED_ESTUDANTE_H

#include <string>
#include "UCTurma.h"

using namespace std;

class Estudante{
public:
    Estudante(int code, const string &name);

    Estudante();

    bool operator<(const Estudante &s) const;

    void addTurma(UCTurma turma);

    void removeTurma(UCTurma turma);

    const string &getName() const;

    const list<UCTurma> &getTurmas() const;

    void setCode(int code);

    int getCode() const;

private:
    int code;
    string name;
    list<UCTurma> turmas;
};

#endif //PROJECT_AED_ESTUDANTE_H
