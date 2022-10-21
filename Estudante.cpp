#include "Estudante.h"

bool Estudante::operator<(const Estudante &s) const {
    return code < s.code;
}

Estudante::Estudante(int code, const string &name) : code(code), name(name) {}
