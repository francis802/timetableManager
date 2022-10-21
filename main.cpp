#include <iostream>
#include "GestaoHor.h"

using namespace std;

int main() {
    GestaoHor gestao = GestaoHor();
    gestao.getDataStudent("../students_classes.csv");
    set<Estudante> a = gestao.getStudents();
    for (Estudante e:a){
        cout << e.getName() << '\n';
        for (UCTurma c : e.getTurmas())
            cout << c.getCodUc() << '\n';
    }
    return 0;
}
