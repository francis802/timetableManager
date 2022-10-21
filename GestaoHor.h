#ifndef PROJECT_AED_GESTAOHOR_H
#define PROJECT_AED_GESTAOHOR_H

#include <set>
#include "Estudante.h"

using namespace std;

class GestaoHor{
public:
    GestaoHor();

    void addStudent(Estudante s);

private:
    set<Estudante> students;
};

#endif //PROJECT_AED_GESTAOHOR_H
