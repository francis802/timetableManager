
#include "Pedido.h"

Pedido::Pedido() {}

int Pedido::getCode() const {
    return code;
}

const string &Pedido::getCodTurma() const {
    return codTurma;
}

const string &Pedido::getCodUc() const {
    return codUC;
}

void Pedido::setCode(int code) {
    Pedido::code = code;
}

void Pedido::setCodTurma(const string &codTurma) {
    Pedido::codTurma = codTurma;
}

void Pedido::setCodUc(const string &codUc) {
    codUC = codUc;
}
