#include <iostream>
#include "GestaoHor.h"

using namespace std;

int main() {
    GestaoHor gestao = GestaoHor();
    gestao.getDataStudent("../students_classes.csv","../classes.csv");

    return 0;
}
