#include "UCTurma.h"

UCTurma::UCTurma(string codUc, string codTurma) : codUC(codUc), codTurma(codTurma) {}

const string &UCTurma::getCodUc() const {
    return codUC;
}

