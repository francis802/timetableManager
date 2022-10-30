//
// Created by francis802 on 28-10-2022.
//

#include "Menu.h"


void Menu::start() {
    bool exit = false;
    string option;
    while (!exit) {
        std::cout << "====================VISUALIZAR====================\n";
        cout << "1 - OCUPAÇÃO\n";
        cout << "2 - HORÁRIO\n";
        cout << "3 - ESTUDANTES\n";

        cout << "\n type 'q' to quit\n";
        cout << "==================================================\n";

        getline(cin, option);
        if (option == "1") exit = ocupacaoMenu();
        else if (option == "2") exit = horarioMenu();
        else if (option == "3") exit = estudantesMenu();
        else if (option == "q") break;
        else cout << "invalid input\n\n";
    }
}

Menu::Menu(const GestaoHor &gestao) : gestao(gestao) {}

int Menu::ocupacaoDeterminadaTurmaUC(string turma, string uc){
    int ocupacao = 0;
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodUc() == uc && t.getCodTurma() == turma)
                ocupacao++;
        }
    }
    cout << uc << '\n';
    cout << '\t' << turma << ": " << ocupacao << " alunos\n";
    return ocupacao;
}

void Menu::ocupacaoTurmasAno(){
    /*
     * SAME AS ABOVE
     */
    //NAO USAR OCUPACAO DETERMINADATURMA AQUI DENTRO
    //VECTORS<Pair>
}

void Menu::ocupacaoTurmas(){
    /*
     * SAME AS ABOVE
     */
}

bool Menu::ocupacaoTurmasMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Turmas\n";
        cout << "\t\t 1 - Determinada Turma a determinada UC\n";
        cout << "\t\t 2 - Turmas de um determinado ano\n";
        cout << "\t\t 3 - Todas as turmas\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1, option2, option3;
        getline(cin, option1);
        if (option1 == "1") {
            cout << "Turma: ";
            getline(cin, option2);
            cout << "UC: ";
            getline(cin, option3);
            ocupacaoDeterminadaTurmaUC(option2, option3);
        }
        else if (option1 == "2") ocupacaoTurmasAno();
        else if (option1 == "3") ocupacaoTurmas();
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void Menu::ocupacaoDeterminadoAno(){
    //TODO
    // como identificar quem pertence a um determinado ano?
    // um aluno pode pertencer a mais que um ano? (acho que sim)
}

void Menu::ocupacaoAnos(){
    //TODO
    //SAME AS ABOVE
}

bool Menu::ocupacaoAnosMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Anos\n";
        cout << "\t\t 1 - Determinado Ano\n";
        cout << "\t\t 2 - Todos os Anos\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        getline(cin, option);
        if (option == "1") ocupacaoDeterminadoAno();
        else if (option == "2") ocupacaoAnos();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void Menu::ocupacaoDeterminadaUC(string codUC) {
    int ocupacao = 0;
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodUc() == codUC){
                ocupacao++;
                break;
            }
        }
    }
    if (ocupacao == 0){
        cout << "UC not found\n";
        return;
    }
    cout << codUC << ": " << ocupacao << " alunos\n";
}

void Menu::ocupacaoUCsAno(string ano) {
    //TODO
    // ver como saber que ucs pertencem a cada ano
}

void Menu::ocupacaoUCs() {
    //TODO
}

bool Menu::ocupacaoUCMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Unidades Curriculares\n";
        cout << "\t\t 1 - Determinada Unidade Curricular\n";
        cout << "\t\t 2 - Unidades Curriculares de um determinado ano\n";
        cout << "\t\t 3 - Todas as Unidades Curriculares\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1, option2;
        getline(cin, option1);
        if (option1 == "1") {
            cout << "Código UC: ";
            getline(cin, option2);
            ocupacaoDeterminadaUC(option2);
        }
        else if (option1 == "2") {
            cout << "Ano: ";
            getline(cin, option2);
            ocupacaoUCsAno(option2);
        }
        else if (option1 == "3") ocupacaoUCs();
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

bool Menu::ocupacaoMenu(){
    bool exit = false;
    while (!exit) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t1 - Turmas\n";
        cout << "\t2 - Anos\n";
        cout << "\t3 - Unidades Curriculares\n";

        cout << "\ntype 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        getline(cin, option);
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

void Menu::printHorario(Estudante student){
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

void Menu::searchHorarioByNum(){
    string num;
    cout << "Número de Estudante: ";
    getline(cin, num);
    Estudante temp = Estudante();
    auto student = gestao.getStudents().find(temp);
    if (student == gestao.getStudents().end()){
        cout << "Student not found\n";
    }
    else{
        printHorario(*student);
    }
}

void Menu::searchHorarioByName(){
    string name;
    cout << "Nome do Estudante: ";
    getline(cin, name);
    for (Estudante student : gestao.getStudents()){
        if (student.getName() == name){
            printHorario(student);
            return;
        }
    }
    cout << "Student not found\n";
}

bool Menu::horarioMenu(){
    while (true) {
        cout << "-> HORÁRIO\n\n";
        cout << "\t1 - Pesquisa por número de estudante (recomendado)\n";
        cout << "\t2 - Pesquisa por nome\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option;
        getline(cin, option);
        if (option == "1") searchHorarioByNum();
        else if (option == "2") searchHorarioByName();
        else if (option == "q") return true;
        else if (option == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void Menu::estudantesTurmaUC(string turma, string uc) {
    cout << uc << " | " << turma << '\n';
    for (Estudante e: gestao.getStudents()){
        for(UCTurma t: e.getTurmas()){
            if (t.getCodUc() == uc && t.getCodTurma() == turma){
                cout << e.getCode() << " - " << e.getName() << '\n';
                break;
            }
        }
    }
}

void Menu::estudantesAno(string ano) {
    if (ano.size() != 1){
        cout << "invalid input\n";
        return;
    }
    bool found = false;
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodTurma()[0] == ano[0]){
                found = true;
                cout << e.getCode() << " - " << e.getName() << endl;
                break;
            }
        }
    }
    if (!found) cout << "No students found\n";
}

void Menu::estudantesUC(string codUC) {
    bool found = false;
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodUc() == codUC){
                found = true;
                cout << e.getCode() << " - " << e.getName() << endl;
                break;
            }
        }
    }
    if (!found) cout << "No students found\n";
}

bool Menu::estudantesMenu(){
    while (true) {
        cout << "-> ESTUDANTES\n\n";
        cout << "\t1 - Estudantes em determinada turma a determinada UC\n";
        cout << "\t2 - Estudantes em determinado ano\n";
        cout << "\t3 - estudantes em determinada UC\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1, option2, option3;
        getline(cin, option1);
        if (option1 == "1") {
            cout << "Turma: ";
            getline(cin, option2);
            cout << "UC: ";
            getline(cin, option3);
            estudantesTurmaUC(option2, option3);
        }
        else if (option1 == "2") {
            cout << "Ano: ";
            getline(cin, option2);
            estudantesAno(option2);
        }
        else if (option1 == "3"){
            cout << "Código UC: ";
            getline(cin, option2);
            estudantesUC(option2);
        }
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}