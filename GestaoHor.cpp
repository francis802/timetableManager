#include "GestaoHor.h"

GestaoHor::GestaoHor() {}

void GestaoHor::addStudent(Estudante s) {
    students.insert(s);
}

void GestaoHor::getDataStudent(string filename1, string filename2) {
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
        getline(iss, classcode);
        UCTurma ucturma = UCTurma(uccode,classcode);
        if (first){
            temp = Estudante(stoi(num), name);
            temp.addTurma(ucturma);
            ucturma.getDataAula(filename2);
            first = false;
            continue;
        }
        if (temp.getName() == name){
            temp.addTurma(ucturma);
            ucturma.getDataAula(filename2)
        }
        else{
            students.insert(temp);
            temp = Estudante(stoi(num), name);
            temp.addTurma(ucturma);
            ucturma.getDataAula(filename2);
        }

    }
}

const set<Estudante> &GestaoHor::getStudents() const {
    return students;
}
