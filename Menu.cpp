//
// Created by francis802 on 28-10-2022.
//

#include <vector>
#include "Menu.h"


void Menu::start() {
    bool exit = false;
    string option;
    while (!exit) {
        std::cout << "====================VISUALIZAR====================\n";
        cout << "1 - OCUPAÇÃO\n";
        cout << "2 - HORÁRIO\n";
        cout << "3 - ESTUDANTES\n";

        cout << "\n4 - ALTERAR HORÁRIOS\n";
        cout << "\n type 'q' to quit\n";
        cout << "==================================================\n";

        getline(cin, option);
        if (option == "1") exit = ocupacaoMenu();
        else if (option == "2") exit = horarioMenu();
        else if (option == "3") exit = estudantesMenu();
        else if (option == "4") exit = alterarMenu();
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

void Menu::ocupacaoTurmasUC(string uc){
    if (uc.size() != 8){
        cout << "UC not found\n";
    }
    string basis;
    basis.push_back(uc[6]);
    basis.push_back(uc[7]);
    int aux = stoi(basis);
    if (aux < 10) basis = "1LEIC";
    else if (aux < 20) basis = "2LEIC";
    else basis = "3LEIC";
    vector<pair<int, string>> ocupacao;
    for (int i = 1; i <= 15; i++){
        if (i < 10){
            ocupacao.push_back({0,basis + "0" + to_string(i)});
        } else ocupacao.push_back({0,basis + to_string(i)});
    }

    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodUc() == uc){
                string turma;
                turma.push_back(t.getCodTurma()[5]);
                turma.push_back(t.getCodTurma()[6]);
                int num_turma = stoi(turma);
                ocupacao[num_turma - 1].first++;
                break;
            }
        }
    }
    string s = "../" + uc + "_ocupacao_turmas.txt";
    ofstream out(s);
    cout << uc << endl;
    out << uc << endl;
    for (pair<int,string> a : ocupacao){
        if (a.first != 0) {
            cout << '\t' << a.second << ": " << a.first << " alunos\n";
            out << '\t' << a.second << ": " << a.first << " alunos\n";
        }
    }
}

bool Menu::ocupacaoTurmasMenu(){
    while (true) {
        cout << "-> OCUPAÇÃO\n\n";
        cout << "\t-> Turmas\n";
        cout << "\t\t 1 - Determinada Turma a determinada UC\n";
        cout << "\t\t 2 - Turmas de uma determinada UC\n";

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
        else if (option1 == "2"){
            cout << "UC: ";
            getline(cin, option2);
            ocupacaoTurmasUC(option2);
        }
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void Menu::ocupacaoDeterminadoAno(string ano){
    if (ano.size() != 1){
        cout << "invalid input\n";
        return;
    }
    int ocupacao = 0;
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodTurma()[0] == ano[0]) {
                ocupacao++;
                break;
            }
        }
    }
    cout << ano << "º ano: " << ocupacao << " alunos\n";
}

void Menu::ocupacaoAnos(){
    for (int i = 1; i <= 3; i++){
        ocupacaoDeterminadoAno(to_string(i));
    }
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
        if (option == "1") {
            cout << "Ano: ";
            getline(cin, option);
            ocupacaoDeterminadoAno(option);
        }
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
    cout << codUC << ": " << ocupacao << " alunos\n";
}

void Menu::printOcupacaoUCs(vector<pair<int,string>> ocupacao, ofstream& out){
    for (pair<int,string> a : ocupacao){
        if (a.first != 0) {
            cout << '\t' << a.second << ": " << a.first << " alunos\n";
            out << '\t' << a.second << ": " << a.first << " alunos\n";
        }
    }
}

vector<pair<int,string>> Menu::ocupacaoUCsAno(string ano) {
    int lower, upper;
    if (ano == "1"){
        lower = 1;
        upper = 10;
    } else if (ano == "2"){
        lower = 11;
        upper = 20;
    } else if (ano == "3"){
        lower = 21;
        upper = 30;
    } else return {{}};
    vector<pair<int,string>> ocupacao;
    for (lower; lower < upper; lower++){
        if (lower < 10) ocupacao.push_back({0, "L.EIC00" + to_string(lower)});
        else ocupacao.push_back({0, "L.EIC0" + to_string(lower)});
    }
    for (Estudante e: gestao.getStudents()){
        for (UCTurma t: e.getTurmas()){
            if (t.getCodTurma()[0] == ano[0]){
                string uc;
                uc.push_back(t.getCodUc()[6]);
                uc.push_back(t.getCodUc()[7]);
                ocupacao[stoi(uc)%10 - 1].first++;
            }
        }
    }
    return ocupacao;
}

void Menu::ocupacaoUCs() {
    string s = "../ocupacao_uc.txt";
    ofstream out(s);
    for (int i = 1; i <= 3; i++){
        cout << i << "º ano\n";
        out << i << "º ano\n";
        printOcupacaoUCs(ocupacaoUCsAno(to_string(i)),out);
    }
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
            string s = "../ocupacao_ucs_" + option2 + "_ano.txt";
            ofstream out(s);
            out << option2 << "ª ano:\n";
            printOcupacaoUCs(ocupacaoUCsAno(option2),out);
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

bool Menu::alterarMenu() {
    while (true){
        cout << "-> ALTERAR HORÁRIOs\n\n";
        cout << "\t1 - Remover estudante de uma turma/UC\n";
        cout << "\t2 - Adicionar estudante a uma turma/UC\n";
        cout << "\t3 - \n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1;
        getline(cin, option1);
        if (option1 == "1") {
            gestao.addPedidos({'r',"abc"});
        }
        else if (option1 == "2") {
            gestao.addPedidos({'a',"abc"});
        }
        else if (option1 == "3"){

        }
        else if (option1 == "q") {
            gestao.processPedidos();
            return true;
        }
        else if (option1 == "r"){
            gestao.processPedidos();
            return false;
        }
        else {
            cout << "invalid input\n\n";
        }
    }
}