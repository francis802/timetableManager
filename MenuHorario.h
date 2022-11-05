//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUHORARIO_H
#define PROJECT_AED_MENUHORARIO_H

#include "Estudante.h"
#include "Menu.h"

/**
 * \brief Classe MenuHorario
 *
 * Classe filha da classe Menu utilizada para facilitar a visualização de diferentes horários por parte do utilizador.
 */
class MenuHorario: public Menu {
public:
    /**
     * \brief Constructor da classe MenuHorario.
     *
     * Complexidade O(1).
     *
     * @param gestao
     */
    explicit MenuHorario(const GestaoHor &gestao);

    /**
     * Inicializa o menu para visualização de horários (interface do utilizador para visualização de horários).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu principal e 'true' se o utilizador decidiu terminar o processo.
     */
    bool horarioMenu();

    /**
     * Procura horário de um determinado estudante pelo seu código UP. Complexidade O(n).
     */
    void searchHorarioByNum();

    /**
     * Procura horário de um determinado estudante pelo seu nome. Complexidade O(n).
     */
    void searchHorarioByName();

    /**
     * Procura o horário de uma determinada turma. Complexidade O(n^2).
     */
    void searchHorarioTurma();

    /**
     * Imprime o horário de um determinado estudante. Complexidade O(n^2).
     *
     * @param student Estudante cujo horário se quer imprimir.
     */
    void printHorario(Estudante student);
};

#endif //PROJECT_AED_MENUHORARIO_H
