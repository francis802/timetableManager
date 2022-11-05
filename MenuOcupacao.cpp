//
// Created by francis802 on 05-11-2022.
//

#include <algorithm>
#include "MenuOcupacao.h"

bool MenuOcupacao::ocupacaoMenu(){
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

bool MenuOcupacao::ocupacaoTurmasMenu(){
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
            if (option2.size() != 8){
                cout << "invalid input\n\n";
                continue;
            }
            printOcupacaoTurmasUC(gestao.ocupacaoTurmasUC(option2),option2);
        }
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

int MenuOcupacao::ocupacaoDeterminadaTurmaUC(string turma, string uc){
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

void MenuOcupacao::printOcupacaoTurmasUC(vector<pair<int, string>> ocupacao, string uc){
    string s = "../" + uc + "_ocupacao_turmas.txt";
    ofstream out(s);
    cout << uc << endl;
    out << uc << endl;
    string sorting;
    cout << "Ordenação: 1) Turma, 2) Crescente, 3) Decrescente\n";
    getline(cin, sorting);
    switch (sorting[0]) {
        case '2':
            sort(ocupacao.begin(), ocupacao.end());
            break;
        case '3':
            sort(ocupacao.rbegin(), ocupacao.rend());
            break;
    }
    int counter = 0;
    for (pair<int,string> a : ocupacao){
        if (a.first != 0) {
            counter++;
            cout << '\t' << a.second << ": " << a.first << " alunos\n";
            out << '\t' << a.second << ": " << a.first << " alunos\n";
        }
    }
    if (counter == 0){
        cout << '\t' << "Sem alunos\n";
        out << '\t' << "Sem alunos\n";
    }
    out.close();
}

bool MenuOcupacao::ocupacaoAnosMenu(){
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

void MenuOcupacao::ocupacaoDeterminadoAno(string ano){
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

void MenuOcupacao::ocupacaoAnos(){
    for (int i = 1; i <= 3; i++){
        ocupacaoDeterminadoAno(to_string(i));
    }
}

bool MenuOcupacao::ocupacaoUCMenu(){
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
            out.close();
        }
        else if (option1 == "3") ocupacaoUCs();
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void MenuOcupacao::ocupacaoDeterminadaUC(string codUC) {
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

void MenuOcupacao::printOcupacaoUCs(vector<pair<int,string>> ocupacao, ofstream& out){
    string option;
    cout << "Ordenação: 1) UC, 2) Crescente, 3) Decrescente\n";
    getline(cin, option);
    switch (option[0]) {
        case '2':
            sort(ocupacao.begin(),ocupacao.end());
            break;
        case '3':
            sort(ocupacao.rbegin(), ocupacao.rend());
            break;
    }
    for (pair<int,string> a : ocupacao){
        if (a.first != 0) {
            cout << '\t' << a.second << ": " << a.first << " alunos\n";
            out << '\t' << a.second << ": " << a.first << " alunos\n";
        }
    }
}

void MenuOcupacao::ocupacaoUCs() {
    string s = "../ocupacao_uc.txt", option;
    ofstream out(s);
    cout << "Ordenação:\n";
    cout << "\t1 - Geral\n";
    cout << "\t2 - Por ano\n";
    getline(cin, option);
    vector<pair<int, string>> ocupacao, ocup;
    if (option == "1"){
        for (int i = 1; i <= 3; i++){
            ocup = ocupacaoUCsAno(to_string(i));
            for (pair<int,string> a : ocup)
                ocupacao.push_back(a);
        }
        cout << "Ordenação: 1) Turma, 2) Crescente, 3) Decrescente\n";
        getline(cin, option);
        switch (option[0]) {
            case '2':
                sort(ocupacao.begin(),ocupacao.end());
                break;
            case '3':
                sort(ocupacao.rbegin(), ocupacao.rend());
                break;
        }
        for (pair<int,string> a : ocupacao){
            if (a.first != 0) {
                cout << '\t' << a.second << ": " << a.first << " alunos\n";
                out << '\t' << a.second << ": " << a.first << " alunos\n";
            }
        }

    } else if (option == "2") {
        for (int i = 1; i <= 3; i++) {
            cout << i << "º ano\n";
            out << i << "º ano\n";
            printOcupacaoUCs(ocupacaoUCsAno(to_string(i)), out);
        }
    } else cout << "invalid input\n\n";
    out.close();
}

vector<pair<int,string>> MenuOcupacao::ocupacaoUCsAno(string ano) {
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

MenuOcupacao::MenuOcupacao(const GestaoHor &gestao) : Menu(gestao) {}
