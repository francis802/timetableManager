
#include <vector>
#include <algorithm>
#include "Menu.h"
#include "MenuOcupacao.h"
#include "MenuHorario.h"


void Menu::start() {
    //! Inicializar menu
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
        if (option == "1") {
            MenuOcupacao menu = MenuOcupacao(gestao);
            exit = menu.ocupacaoMenu();
        }
        else if (option == "2"){
            MenuHorario menu = MenuHorario(gestao);
            exit = menu.horarioMenu();
        }
        else if (option == "3") exit = estudantesMenu();
        else if (option == "4") exit = alterarMenu();
        else if (option == "q") break;
        else cout << "invalid input\n\n";
    }
}

Menu::Menu(const GestaoHor &gestao) : gestao(gestao) {}

void Menu::estudantesTurmaUC(string turma, string uc, char sort) {
    string s = "../estudantes" + turma + "_" + uc + ".txt";
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

void Menu::estudantesAno(string ano, char sort) {
    string s = "../estudantes_" + ano + "ano.txt";
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

void Menu::estudantesUC(string codUC, char sort) {
    string s = "../estudantes_" + codUC + ".txt";
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

void Menu::estudantesMaisDeNUCs(std::string n, char sort) {
    int num;
    try {
        num = stoi(n);
    } catch (invalid_argument) {
        cout << "invalid input\n\n";
        return;
    }
    string s = "../estudantes_mais_de_" + n + "_ucs.txt";
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

bool Menu::estudantesMenu(){
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

bool Menu::alterarMenu() {
    while (true){
        cout << "-> ALTERAR HORÁRIOs\n\n";
        cout << "\t1 - Remover estudante de uma turma/UC\n";
        cout << "\t2 - Adicionar estudante a uma turma/UC\n";
        cout << "\t3 - Alterar turma/UC de um estudante\n";
        cout << "\t4 - Alterar conjunto de turmas/UCs de um estudante\n";

        cout << "\n type 'q' to quit, 'r' to return\n";
        cout << "==================================================\n";

        string option1, numStudent, classStudent, codUCStudent;
        Pedido pedido;
        vector<pair<char,Pedido>> waiting;
        getline(cin, option1);
        if (option1 == "1") {
            cout << "Nºestudante:";
            getline(cin, numStudent);
            cout << "Turma:";
            getline(cin, classStudent);
            cout << "Código UC:";
            getline(cin, codUCStudent);
            pedido.setCode(stoi(numStudent)); pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
            waiting.push_back({'r',pedido});
            gestao.addPedidos(waiting);
        }
        else if (option1 == "2") {
            cout << "Nºestudante:";
            getline(cin, numStudent);
            cout << "Turma:";
            getline(cin, classStudent);
            cout << "Código UC:";
            getline(cin, codUCStudent);
            try {
                pedido.setCode(stoi(numStudent));
            }catch (invalid_argument){
                cout << "invalid input\n\n";
                continue;
            }
            pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
            waiting.push_back({'a',pedido});
            gestao.addPedidos(waiting);
        }
        else if (option1 == "3"){
            cout << "Nºestudante:";
            getline(cin, numStudent);
            try {
                pedido.setCode(stoi(numStudent));
            } catch (invalid_argument) {
                cout << "invalid input\n\n";
                continue;
            }
            cout << "Turma/UC a remover:\n";
            cout << "\tTurma:";
            getline(cin, classStudent);
            cout << "\tCódigo UC:";
            getline(cin, codUCStudent);
            pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
            waiting.push_back({'r',pedido});
            cout << "Turma/UC a adicionar:\n";
            cout << "\tTurma:";
            getline(cin, classStudent);
            cout << "\tCódigo UC:";
            getline(cin, codUCStudent);
            pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
            waiting.push_back({'a',pedido});
            gestao.addPedidos(waiting);
        }
        else if (option1 == "4"){
            cout << "Nºestudante:";
            getline(cin, numStudent);
            try {
                pedido.setCode(stoi(numStudent));
            } catch (invalid_argument) {
                cout << "invalid input\n\n";
                continue;
            }
            while (true){
                cout << "Turma/UC a remover (Press Enter to continue):\n";
                cout << "\tTurma:";
                getline(cin, classStudent);
                if (classStudent == "") break;
                cout << "\tCódigo UC:";
                getline(cin, codUCStudent);
                pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
                waiting.push_back({'r',pedido});
            }
            cout << "------------------------------------------------------\n";
            while (true){
                cout << "Turma/UC a adicionar (Press Enter to continue):\n";
                cout << "\tTurma:";
                getline(cin, classStudent);
                if (classStudent == "") break;
                cout << "\tCódigo UC:";
                getline(cin, codUCStudent);
                pedido.setCodTurma(classStudent); pedido.setCodUc(codUCStudent);
                waiting.push_back({'a',pedido});
            }
            if (!waiting.empty())
                gestao.addPedidos(waiting);
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