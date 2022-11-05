
#include <vector>
#include <algorithm>
#include "Menu.h"


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

void Menu::printOcupacaoTurmasUC(vector<pair<int, string>> ocupacao, string uc){
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

void Menu::searchHorarioByName(){
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

void Menu::searchHorarioTurma() {
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

bool Menu::horarioMenu(){
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