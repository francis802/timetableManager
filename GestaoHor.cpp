#include <iostream>
#include "GestaoHor.h"

GestaoHor::GestaoHor() {}

void GestaoHor::addStudent(Estudante s) {
    students.insert(s);
}

list<UCTurma> GestaoHor::getDataAula(string filename){
    ifstream in(filename);
    string line;
    getline(in, line);
    bool first = true;
    bool exists;
    UCTurma temp;
    string last_uccode;
    list<UCTurma> classes;
    list<UCTurma> to_return;
    while(getline(in, line)) {
        istringstream iss(line);
        string uccode, classcode;
        string weekDay, startH, duration, type;
        getline(iss, classcode, ',');
        getline(iss, uccode, ',');
        getline(iss, weekDay, ',');
        getline(iss, startH, ',');
        getline(iss, duration, ',');
        getline(iss, type);
        Aula aula = Aula(weekDay,stof(startH),stof(duration),type);
        if (first){
            temp = UCTurma(classcode, uccode);
            temp.addAula(aula);
            classes.push_back(temp);
            last_uccode = uccode;
            first = false;
            continue;
        }
        if (last_uccode.compare(uccode) == 0){
            exists = false;
            for (UCTurma& ucclass: classes){
                if(ucclass.getCodTurma().compare(classcode) == 0) {
                    ucclass.addAula(aula);
                    exists = true;
                    break;
                }
            }
            if(!exists){
                temp = UCTurma(classcode, uccode);
                temp.addAula(aula);
                classes.push_back(temp);
            }
        }
        else{
            last_uccode = uccode;
            for (UCTurma ucclass: classes){
                to_return.push_back(ucclass);
            }
            classes.clear();
            temp = UCTurma(classcode, uccode);
            temp.addAula(aula);
            classes.push_back(temp);
        }
    }
    return to_return;
}

void GestaoHor::getDataStudent(string filename1, string filename2) {
    list<UCTurma> my_classes = getDataAula(filename2);
    ifstream in(filename1);
    string line;
    getline(in, line);
    bool first = true;
    Estudante temp;
    while(getline(in, line)) {
        istringstream iss(line);
        string num, name;
        string uccode, classcode;
        getline(iss, num, ',');
        getline(iss, name, ',');
        getline(iss, uccode, ',');
        getline(iss, classcode, '\r');
        if (first){
            temp = Estudante(stoi(num), name);
            for (UCTurma ucturma: my_classes){
                if ((ucturma.getCodTurma().compare(classcode) == 0) && (ucturma.getCodUc().compare(uccode) == 0))
                    temp.addTurma(ucturma);
            }
            first = false;
            continue;
        }

        if (temp.getName().compare(name) != 0){
            students.insert(temp);
            temp = Estudante(stoi(num), name);
        }
        for (UCTurma ucturma: my_classes){
            if ((ucturma.getCodTurma().compare(classcode) == 0) && (ucturma.getCodUc().compare(uccode) == 0)){
                temp.addTurma(ucturma);
            }
        }
    }
}

const set<Estudante> &GestaoHor::getStudents() const {
    return students;
}
