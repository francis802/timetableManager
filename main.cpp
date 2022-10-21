#include <iostream>
#include "GestaoHor.h"

using namespace std;

int main() {
    GestaoHor gestao = GestaoHor();
    gestao.getDataStudent("students_classes.csv");
    set<Estudante> a = gestao.getStudents();
    for (Estudante e:a){
        cout << e.getName() << '\n';
    }
    return 0;
}
