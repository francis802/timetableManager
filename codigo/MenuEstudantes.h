//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUESTUDANTES_H
#define PROJECT_AED_MENUESTUDANTES_H

#include "Menu.h"

/**
 * \brief Classe MenuEstudantes
 *
 * Classe filha da classe Menu utilizada para facilitar a visualização de diferentes estudantes por parte do utilizador.
 */
class MenuEstudantes: public Menu {
public:
    /**
     * Constructor da classe MenuEstudantes.
     *
     * Complexidade O(1).
     *
     * @param gestao
     */
    explicit MenuEstudantes(const GestaoHor &gestao);

    /**
     * Inicializa o menu para visualização de estudantes (interface do utilizador para visualização de estudantes).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu principal e 'true' se o utilizador decidiu terminar o processo.
     */
    bool estudantesMenu();

    /**
     * Procura estudantes pela turma em que estão numa determinada UC. Complexidade O(n^2).
     *
     * @param turma Código da turma.
     * @param uc Código da UC.
     * @param sort '1' para organizar os estudantes por código UP e '2' para organizar por ordem alfabética.
     */
    void estudantesTurmaUC(string turma, string uc, char sort);

    /**
     * Procura estudantes pelo ano em que estão. Complexidade O(n^2).
     *
     * @param ano Ano (1, 2 ou 3).
     * @param sort '1' para organizar os estudantes por código UP e '2' para organizar por ordem alfabética.
     */
    void estudantesAno(string ano, char sort);

    /**
     * Procura estudantes que estão inscritos numa determinada UC. Complexidade O(n^2).
     *
     * @param codUC Código da UC.
     * @param sort '1' para organizar os estudantes por código UP e '2' para organizar por ordem alfabética.
     */
    void estudantesUC(string codUC, char sort);

    /**
     * Procura estudantes que estão inscritos em mais de um determinado número de UCs. Complexidade O(n).
     *
     * @param n Número de UCs.
     * @param sort '1' para organizar os estudantes por código UP, '2' para organizar por ordem alfabética e '3' para organizar por número de UCs em que estão inscritos.
     */
    void estudantesMaisDeNUCs(string n, char sort);
};


#endif //PROJECT_AED_MENUESTUDANTES_H
