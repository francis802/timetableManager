#ifndef PROJECT_AED_UCTURMA_H
#define PROJECT_AED_UCTURMA_H

#include <string>
#include <list>
#include "Aula.h"

using namespace std;

class UCTurma{
public:
    UCTurma(string codTurma, string codUC);

    UCTurma();

    bool operator<(const UCTurma &s) const;

    void addAula(Aula aula);
    const string &getCodUc() const;

    const string &getCodTurma() const;

    const list<Aula> &getTimetable() const;

private:
    string codUC;
    string codTurma;
    list<Aula> timetable;
};

#endif //PROJECT_AED_UCTURMA_H
