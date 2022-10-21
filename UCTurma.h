#ifndef PROJECT_AED_UCTURMA_H
#define PROJECT_AED_UCTURMA_H

#include <string>
#include <list>
#include "Aula.h"

using namespace std;

class UCTurma{
public:
    UCTurma(string codUc, string codTurma);

    const string &getCodUc() const;

private:
    string codUC;
    string codTurma;
    list<Aula> timetable;
};

#endif //PROJECT_AED_UCTURMA_H
