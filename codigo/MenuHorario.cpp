//
// Created by francis802 on 05-11-2022.
//

#include "MenuHorario.h"

MenuHorario::MenuHorario(const GestaoHor &gestao) : Menu(gestao) {}

bool MenuHorario::horarioMenu(){
    while (true) {
        cout << "-> HORÁRIO\n\n";
        cout << "\t1 - Estudante (pesquisa por número)\n";
        cout << "\t2 - Estudante (pesquisa por nome)\n";
        cout << "\t3 - Turma\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        getline(cin, option);
        if (option == "1") searchHorarioByNum();
        else if (option == "2") searchHorarioByName();
        else if (option == "3") searchHorarioTurma();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void MenuHorario::searchHorarioByNum(){
    string num;
    cout << "Número de Estudante: ";
    getline(cin, num);
    Estudante temp = Estudante();
    try {
        temp.setCode(stoi(num));
    } catch (invalid_argument) {
        cout << "invalid input\n\n";
        return;
    }
    auto student = gestao.getStudents().find(temp);
    if (student == gestao.getStudents().end()){
        cout << "Student not found\n";
    }
    else{
        printHorario(*student);
    }
}

void MenuHorario::searchHorarioByName(){
    string name;
    cout << "Nome do Estudante: ";
    getline(cin, name);
    Estudante temp = Estudante();
    temp.setName(name);
    auto student = gestao.getStudentsByname().find(temp);
    if (student == gestao.getStudentsByname().end()){
        cout << "Student not found\n";
    }
    else{
        printHorario(*student);
    }
}

void MenuHorario::searchHorarioTurma() {
    string turma;
    cout << "Turma: ";
    getline(cin, turma);
    string s = "../" + turma + "_horario.txt";
    ofstream out(s);
    cout << turma << endl;
    out << turma << endl;
    for (UCTurma t : gestao.getAulas()){
        if (t.getCodTurma() == turma){
            ofstream out(s,std::ios_base::app);
            cout << "- " << t.getCodUc() << endl;
            out << "- " << t.getCodUc() << endl;
            for (Aula a : t.getTimetable()){
                cout << '\t' << a.getWeekday();
                cout << ' ' << a.getStartHour();
                cout << ' ' << a.getDuration();
                cout << ' ' << a.getType() << '\n';
                out << '\t' << a.getWeekday();
                out << ' ' << a.getStartHour();
                out << ' ' << a.getDuration();
                out << ' ' << a.getType() << '\n';
            }
            out.close();
        }
    }
}

void MenuHorario::printHorario(Estudante student){
    string s = "../" + student.getName() + "_horario.txt";
    ofstream out(s);
    for (UCTurma turma : student.getTurmas()){
        cout << "UC: " << turma.getCodUc() << " | Turma: " << turma.getCodTurma() << endl;
        out << "UC: " << turma.getCodUc() << " | Turma: " << turma.getCodTurma() << endl;
        for (Aula aula : turma.getTimetable()){
            cout << '\t' << aula.getWeekday();
            cout << ' ' << aula.getStartHour();
            cout << ' ' << aula.getDuration();
            cout << ' ' << aula.getType() << '\n';
            out << '\t' << aula.getWeekday();
            out << ' ' << aula.getStartHour();
            out << ' ' << aula.getDuration();
            out << ' ' << aula.getType() << '\n';
        }
    }
    cout << '\n';
    out.close();
}