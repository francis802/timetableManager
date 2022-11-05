
#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <string>
#include <vector>
#include "Estudante.h"
#include "GestaoHor.h"
#include <iostream>

/**
 * \brief Classe Menu
 *
 * Classe que serve como parent class para outros tipos de menus (estudantes, horário e ocupação).
 */
class Menu {
protected:
    GestaoHor gestao;

public:
    /**
     * \brief Constructor da classe Menu.
     *
     * Complexidade O(1).
     *
     * @param gestao
     */
    explicit Menu(const GestaoHor &gestao);

    /**
     * Inicializa o menu principal (interface do utilizador para visualização/gestão de estudantes, horários e ocupação).
     */
    void start();

    /**
     * Inicializa o menu para alteracão de horários (interface do utilizador para gestão de horários).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu principal e 'true' se o utilizador decidiu terminar o processo.
     */
    bool alterarMenu();
};


#endif //PROJECT_AED_MENU_H
