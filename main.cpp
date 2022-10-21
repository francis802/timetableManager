#include <iostream>
#include "GestaoHor.h"

using namespace std;

int main() {
    GestaoHor gestao = GestaoHor();
    list<UCTurma> turmas = gestao.getDataAula("../classes.csv");
    for (UCTurma uc: turmas){
        cout << uc.getCodUc() << '|' << uc.getCodTurma() << '\n';
    }
    return 0;
}
