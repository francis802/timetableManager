//
// Created by francis802 on 03-11-2022.
//

#ifndef PROJECT_AED_PEDIDO_H
#define PROJECT_AED_PEDIDO_H


#include "Estudante.h"

class Pedido {
private:
    int code;
    string codTurma;
    string codUC;

public:
    Pedido();

    void setCodUc(const string &codUc);
    void setCodTurma(const string &codTurma);
    void setCode(int code);

    const string &getCodUc() const;
    const string &getCodTurma() const;
    int getCode() const;


};


#endif //PROJECT_AED_PEDIDO_H
