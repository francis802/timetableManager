#include "Estudante.h"

bool Estudante::operator<(const Estudante &s) const {
    return code < s.code;
}

Estudante::Estudante(int code, const string &name) : code(code), name(name) {}

Estudante::Estudante() {

}

void Estudante::addTurma(UCTurma turma) {
    turmas.push_back(turma);
}

const string &Estudante::getName() const {
    return name;
}

const list<UCTurma> &Estudante::getTurmas() const {
    return turmas;
}

void Estudante::setCode(int code) {
    Estudante::code = code;
}
