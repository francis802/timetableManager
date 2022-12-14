#include <iostream>
#include "codigo/GestaoHor.h"
#include "codigo/Menu.h"
#include <fstream>

using namespace std;

int main() {
    ofstream out("../log_failed_changes.txt");
    out.close();
    GestaoHor gestao = GestaoHor();
    gestao.getDataStudent("../ficheiros/csv/students_classes.csv", "../ficheiros/csv/classes.csv");
    Menu menu = Menu(gestao);
    menu.start();
    return 0;
}
