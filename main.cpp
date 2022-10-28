#include <iostream>
#include "GestaoHor.h"
#include "Menu.h"
#include <fstream>

using namespace std;

int main() {
    GestaoHor gestao = GestaoHor();
    gestao.getDataStudent("../students_classes.csv", "../classes.csv");
    Menu menu = Menu(gestao);
    menu.start();


    /*
    list<UCTurma> turmas = gestao.getDataAula("../classes.csv");
    for (UCTurma uc: turmas){
        cout << uc.getCodUc() << '|' << uc.getCodTurma() << '\n';
        for (Aula a: uc.getTimetable()){
            cout << '\t' << a.getWeekday();
            cout << ' ' << a.getStartHour();
            cout << ' ' << a.getDuration();
            cout << ' ' << a.getType() << '\n';
        }
    }

    cout << "----------------------------------------------------\n----------------------------------------------------\n";

    gestao.getDataStudent("../students_classes.csv","../classes.csv");
    for (Estudante e : gestao.getStudents()) {
        cout << e.getName() << '\n';
        for (UCTurma turma : e.getTurmas()){
            cout << turma.getCodUc() << " -- " << turma.getCodTurma() << '\n';
            for (Aula a : turma.getTimetable()){
                cout << '\t' << a.getWeekday();
                cout << ' ' << a.getStartHour();
                cout << ' ' << a.getDuration();
                cout << ' ' << a.getType() << '\n';
            }
        }
    }
     */
    return 0;
}
