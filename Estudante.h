#ifndef PROJECT_AED_ESTUDANTE_H
#define PROJECT_AED_ESTUDANTE_H

#include <string>
#include "UCTurma.h"

using namespace std;

class Estudante{
public:
    Estudante(int code, const string &name);

    bool operator<(const Estudante &s) const;

private:
    int code;
    string name;
    list<UCTurma> turmas;
};

#endif //PROJECT_AED_ESTUDANTE_H
