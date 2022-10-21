#include "GestaoHor.h"

GestaoHor::GestaoHor() {}

void GestaoHor::addStudent(Estudante s) {
    students.insert(s);
}

void GestaoHor::getDataStudent(string filename) {
    ifstream in(filename);
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
        getline(iss, classcode);
        UCTurma ucturma = UCTurma(uccode,classcode);
        if (first){
            temp = Estudante(stoi(num), name);
            temp.addTurma(ucturma);
            first = false;
            continue;
        }
        if (temp.getName() == name){
            temp.addTurma(ucturma);
        }
        else{
            students.insert(temp);
            temp = Estudante(stoi(num), name);
            temp.addTurma(ucturma);
        }

    }
}

const set<Estudante> &GestaoHor::getStudents() const {
    return students;
}
