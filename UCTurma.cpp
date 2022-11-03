#include "UCTurma.h"

UCTurma::UCTurma(string codTurma, string codUC) : codTurma(codTurma), codUC(codUC) {}

bool UCTurma::operator<(const UCTurma &s) const {
    if (this->codUC == s.codUC)
        return this->codTurma < s.codTurma;
    return this->codUC < s.codUC;
}

const string &UCTurma::getCodUc() const {
    return codUC;
}

UCTurma::UCTurma() {}

void UCTurma::addAula(Aula aula) {
    timetable.push_back(aula);
}

const string &UCTurma::getCodTurma() const {
    return codTurma;
}

const list<Aula> &UCTurma::getTimetable() const {
    return timetable;
}
