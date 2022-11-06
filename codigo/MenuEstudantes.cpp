//
// Created by francis802 on 05-11-2022.
//

#include "MenuEstudantes.h"

MenuEstudantes::MenuEstudantes(const GestaoHor &gestao) : Menu(gestao) {}

bool MenuEstudantes::estudantesMenu(){
    while (true) {
        cout << "-> ESTUDANTES\n\n";
        cout << "\t1 - Estudantes em determinada turma a determinada UC\n";
        cout << "\t2 - Estudantes em determinado ano\n";
        cout << "\t3 - Estudantes em determinada UC\n";
        cout << "\t4 - Estudantes com mais de n UCs\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1, option2, option3, sorting;
        getline(cin, option1);
        if (option1 == "1") {
            cout << "Turma: ";
            getline(cin, option2);
            cout << "UC: ";
            getline(cin, option3);
            cout << "Ordenação: 1) Nº Estudante, 2) Alfabética\n";
            getline(cin, sorting);
            estudantesTurmaUC(option2, option3,sorting[0]);
        }
        else if (option1 == "2") {
            cout << "Ano: ";
            getline(cin, option2);
            if (option2.size() != 1){
                cout << "invalid input\n\n";
                continue;
            }
            cout << "Ordenação: 1) Nº Estudante, 2) Alfabética\n";
            getline(cin, sorting);
            estudantesAno(option2, sorting[0]);
        }
        else if (option1 == "3"){
            cout << "Código UC: ";
            getline(cin, option2);
            cout << "Ordenação: 1) Nº Estudante, 2) Alfabética\n";
            getline(cin, sorting);
            estudantesUC(option2, sorting[0]);
        }
        else if (option1 == "4"){
            cout << "Nº limite de UCs: ";
            getline(cin, option2);
            cout << "Ordenação: 1) Nº Estudante, 2) Alfabética, 3) Nº UCs\n";
            getline(cin, sorting);
            estudantesMaisDeNUCs(option2, sorting[0]);
        }
        else if (option1 == "q") return true;
        else if (option1 == "r") return false;
        else {
            cout << "invalid input\n\n";
        }
    }
}

void MenuEstudantes::estudantesTurmaUC(string turma, string uc, char sort) {
    string s = "../ficheiros/estudantes" + turma + "_" + uc + ".txt";
    ofstream out(s);
    cout << uc << " | " << turma << '\n';
    out << uc << " | " << turma << '\n';
    bool found = false;
    switch (sort) {
        case '1':{
            for (Estudante e: gestao.getStudents()){
                for(UCTurma t: e.getTurmas()){
                    if (t.getCodUc() == uc && t.getCodTurma() == turma){
                        found = true;
                        cout << e.getCode() << " - " << e.getName() << '\n';
                        out << e.getCode() << " - " << e.getName() << '\n';
                        break;
                    }
                }
            }
            break;
        }
        default:{
            for (Estudante e: gestao.getStudentsByname()){
                for(UCTurma t: e.getTurmas()){
                    if (t.getCodUc() == uc && t.getCodTurma() == turma){
                        found = true;
                        cout << e.getName() << " - " << e.getCode() << '\n';
                        out << e.getName() << " - " << e.getCode() << '\n';
                        break;
                    }
                }
            }
        }
    }
    if (!found){
        cout << "No students found\n";
        out << "No students found\n";
    }
    out.close();
}

void MenuEstudantes::estudantesAno(string ano, char sort) {
    string s = "../ficheiros/estudantes_" + ano + "ano.txt";
    ofstream out(s);
    bool found = false;
    switch (sort) {
        case '1':{
            for (Estudante e: gestao.getStudents()){
                for (UCTurma t: e.getTurmas()){
                    if (t.getCodTurma()[0] == ano[0]){
                        found = true;
                        cout << e.getCode() << " - " << e.getName() << endl;
                        out << e.getCode() << " - " << e.getName() << endl;
                        break;
                    }
                }
            }
            break;
        } default:{
            for (Estudante e: gestao.getStudentsByname()){
                for (UCTurma t: e.getTurmas()){
                    if (t.getCodTurma()[0] == ano[0]){
                        found = true;
                        cout << e.getName() << " - " << e.getCode() << '\n';
                        out << e.getName() << " - " << e.getCode() << '\n';
                        break;
                    }
                }
            }
        }
    }
    if (!found){
        cout << "No students found\n";
        out << "No students found\n";
    }
    out.close();
}

void MenuEstudantes::estudantesUC(string codUC, char sort) {
    string s = "../ficheiros/estudantes_" + codUC + ".txt";
    ofstream out(s);
    bool found = false;
    switch (sort) {
        case '1':{
            for (Estudante e: gestao.getStudents()){
                for (UCTurma t: e.getTurmas()){
                    if (t.getCodUc() == codUC){
                        found = true;
                        cout << e.getCode() << " - " << e.getName() << endl;
                        out << e.getCode() << " - " << e.getName() << endl;
                        break;
                    }
                }
            }
            break;
        }default:{
            for (Estudante e: gestao.getStudentsByname()){
                for (UCTurma t: e.getTurmas()){
                    if (t.getCodUc() == codUC){
                        found = true;
                        cout << e.getName() << " - " << e.getCode() << '\n';
                        out << e.getName() << " - " << e.getCode() << '\n';
                        break;
                    }
                }
            }
        }
    }
    if (!found){
        cout << "No students found\n";
        out << "No students found\n";
    }
    out.close();
}

void MenuEstudantes::estudantesMaisDeNUCs(std::string n, char sort) {
    int num;
    try {
        num = stoi(n);
    } catch (invalid_argument) {
        cout << "invalid input\n\n";
        return;
    }
    string s = "../ficheiros/estudantes_mais_de_" + n + "_ucs.txt";
    ofstream out(s);
    bool found = false;
    switch (sort) {
        case '1':{
            for (Estudante e: gestao.getStudents()){
                int size = e.getTurmas().size();
                if (size > num){
                    found = true;
                    cout << size << " UCs -> " << e.getCode() << " - " << e.getName() << endl;
                    out << size << " UCs -> " << e.getCode() << " - " << e.getName() << endl;
                }
            }
            break;
        }
        case '2':{
            for (Estudante e: gestao.getStudentsByname()){
                int size = e.getTurmas().size();
                if (size > num){
                    found = true;
                    cout << size << " UCs -> " << e.getName() << " - " << e.getCode() << endl;
                    out << size << " UCs -> " << e.getName() << " - " << e.getCode() << endl;
                }
            }
            break;
        }
        default:{
            struct cmp {
                bool operator()(const Estudante lhs, const Estudante rhs) const{
                    if (lhs.getTurmas().size() != rhs.getTurmas().size())
                        return lhs.getTurmas().size() < rhs.getTurmas().size();
                    return lhs.getName() < rhs.getName();
                }
            };
            set<Estudante,cmp> estudantes_nucs;
            for (Estudante e: gestao.getStudents()){
                if (e.getTurmas().size() > num){
                    found = true;
                    estudantes_nucs.insert(e);
                }
            }
            int previous_size = 0;
            for (Estudante e: estudantes_nucs){
                int size = e.getTurmas().size();
                if (size != previous_size) {
                    cout << size << " UCs:\n";
                    out << size << " UCs:\n";
                    previous_size = size;
                }
                cout << '\t' << e.getCode() << " - " << e.getName() << endl;
                out << '\t' << e.getCode() << " - " << e.getName() << endl;
            }
        }
    }
    if (!found){
        cout << "No students found\n";
        out << "No students found\n";
    }
    out.close();
}