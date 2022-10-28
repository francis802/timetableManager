#include <iostream>
#include "GestaoHor.h"
#include <fstream>

using namespace std;

GestaoHor gestao = GestaoHor();

void ocupacaoDeterminadaTurma(){

}

void ocupacaoTurmasAno(){

}

void ocupacaoTurmas(){

}

bool ocupacaoTurmasMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Turmas\n";
        cout << "\t\t 1 - Determinada Turma\n";
        cout << "\t\t 2 - Turmas de um determinado ano\n";
        cout << "\t\t 3 - Todas as turmas\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") ocupacaoDeterminadaTurma();
        else if (option == "2") ocupacaoTurmasAno();
        else if (option == "3") ocupacaoTurmas();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void ocupacaoDeterminadoAno(){

}

void ocupacaoAnos(){

}

bool ocupacaoAnosMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Anos\n";
        cout << "\t\t 1 - Determinado Ano\n";
        cout << "\t\t 2 - Todos os Anos\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") ocupacaoDeterminadoAno();
        else if (option == "2") ocupacaoAnos();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void ocupacaoDeterminadaUC() {

}

void ocupacaoUCsAno() {

}

void ocupacaoUCs() {

}

bool ocupacaoUCMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Unidades Curriculares\n";
        cout << "\t\t 1 - Determinada Unidade Curricular\n";
        cout << "\t\t 2 - Unidades Curriculares de um determinado ano\n";
        cout << "\t\t 3 - Todas as Unidades Curriculares\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") ocupacaoDeterminadaUC();
        else if (option == "2") ocupacaoUCsAno();
        else if (option == "3") ocupacaoUCs();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

bool ocupacaoMenu(){
    bool exit = false;
    while (!exit) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t1 - Turmas\n";
        cout << "\t2 - Anos\n";
        cout << "\t3 - Unidades Curriculares\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") exit = ocupacaoTurmasMenu();
        else if (option == "2") exit = ocupacaoAnosMenu();
        else if (option == "3") exit = ocupacaoUCMenu();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
    return true;
}

void printHorario(Estudante student){
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

void searchHorarioByNum(){
    int num;
    cout << "Número de Estudante: ";
    cin >> num;
    Estudante temp = Estudante();
    temp.setCode(num);
    auto student = gestao.getStudents().find(temp);
    if (student == gestao.getStudents().end()){
        cout << "Student not found\n";
    }
    else{
        printHorario(*student);
    }
}

void searchHorarioByName(){
    string name;
    cout << "Nome do Estudante: ";
    cin >> name;
    for (Estudante student : gestao.getStudents()){
        if (student.getName() == name){
            printHorario(student);
            break;
        }
    }
}

bool horarioMenu(){
    while (true) {
        cout << "-> HORÁRIO\n\n";
        cout << "\t1 - Pesquisa por número de estudante (recomendado)\n";
        cout << "\t2 - Pesquisa por nome\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") searchHorarioByNum();
        else if (option == "2") searchHorarioByName();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void estudantesTurma() {

}

void estudantesAno() {

}

void estudantesUC() {

}

bool estudantesMenu(){
    while (true) {
        cout << "-> ESTUDANTES\n\n";
        cout << "\t1 - Estudantes em determinada turma\n";
        cout << "\t2 - Estudantes em determinado ano\n";
        cout << "\t3 - estudantes em determinada UC\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        cin >> option;
        if (option == "1") estudantesTurma();
        else if (option == "2") estudantesAno();
        else if (option == "3") estudantesUC();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

int main() {
    gestao.getDataStudent("../students_classes.csv", "../classes.csv");
    bool exit = false;
    string option;
    while (!exit){
        cout << "====================VISUALIZAR====================\n";
        cout << "1 - OCUPAÇÃO\n";
        cout << "2 - HORÁRIO\n";
        cout << "3 - ESTUDANTES\n";

        cout << "\n type 'q' to quit\n";
        cout << "==================================================\n";

        cin >> option;
        if (option == "1") exit = ocupacaoMenu();
        else if (option == "2") exit = horarioMenu();
        else if (option == "3") exit = estudantesMenu();
        else if (option == "q") break;
        else cout <<"invalid input\n\n";
    }
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
