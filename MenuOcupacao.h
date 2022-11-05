//
// Created by francis802 on 05-11-2022.
//

#ifndef PROJECT_AED_MENUOCUPACAO_H
#define PROJECT_AED_MENUOCUPACAO_H

#include "Menu.h"

/**
 * \brief Classe MenuOcupacao
 *
 * Classe filha da classe Menu utilizada para facilitar a visualização da ocupação de diferentes turmas/anos/UCs por parte do utilizador.
 */
class MenuOcupacao: public Menu {
public:
    /**
     * \brief Constructor da classe MenuOcupacao.
     *
     * Complexidade O(1).
     *
     * @param gestao
     */
    explicit MenuOcupacao(const GestaoHor &gestao);

    /**
     * Inicializa o menu para visualização da ocupação de diferentes turmas/anos/UCs (interface do utilizador para visualização da ocupação de diferentes turmas/anos/UCs).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu principal e 'true' se o utilizador decidiu terminar o processo.
     */
    bool ocupacaoMenu();

    /**
     * Inicializa o menu para visualização da ocupação de diferentes turmas (interface do utilizador para visualização da ocupação de diferentes turmas).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu ocupação e 'true' se o utilizador decidiu terminar o processo.
     */
    bool ocupacaoTurmasMenu();

    /**
     * Determina a ocupação de uma turma de uma determinada UC. Complexidade O(n^2).
     *
     * @param turma Código da turma.
     * @param uc Código da UC.
     * @return Ocupação de uma turma de uma determinada UC.
     */
    int ocupacaoDeterminadaTurmaUC(string turma, string uc);

    /**
     * Imprime a ocupação das turmas de uma determinada UC. Complexidade O(n^2).
     *
     * @param ocupacao Vetor de pares constituídos pela ocupação de uma turma e o seu código.
     * @param uc Código da UC.
     */
    void printOcupacaoTurmasUC(vector<pair<int,string>> ocupacao, string uc);

    /**
     * Inicializa o menu para visualização da ocupação de diferentes anos (interface do utilizador para visualização da ocupação de diferentes anos).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu ocupação e 'true' se o utilizador decidiu terminar o processo.
     */
    bool ocupacaoAnosMenu();

    /**
     * Determina a ocupação de um determinado ano. Complexidade O(n^2).
     *
     * @param ano Ano (1, 2 ou 3).
     */
    void ocupacaoDeterminadoAno(string ano);

    /**
     * Determina a ocupação de todos os anos. Complexidade O(n^2).
     */
    void ocupacaoAnos();

    /**
     * Inicializa o menu para visualização da ocupação de diferentes UCs (interface do utilizador para visualização da ocupação de diferentes UCs).
     *
     * @return Retorna 'false' se o utilizador decidiu voltar ao menu ocupação e 'true' se o utilizador decidiu terminar o processo.
     */
    bool ocupacaoUCMenu();

    /**
     * Determina a ocupação de determinada UC. Complexidade O(n^2).
     *
     * @param codUC Código da UC.
     */
    void ocupacaoDeterminadaUC(std::string codUC);

    /**
     * Imprime a ocupação de um determinado conjunto de UCs. Complexidade O(n).
     *
     * @param ocupacao Vetor de pares constituídos pela ocupação de uma UC e o seu código.
     * @param out Stream onde vai ser colocado o resultado a imprimir.
     */
    void printOcupacaoUCs(vector<pair<int,string>> ocupacao, ofstream& out);

    /**
     * Determina a ocupação de cada UC. Complexidade O(n)
     */
    void ocupacaoUCs();

    /**
     * Determina a ocupação das UCs de um determinado ano. Complexidade O(n^2).
     *
     * @param ano Ano (1, 2 ou 3)
     * @return Vetor de pares constituídos pela ocupação de uma UC e o seu código.
     */
    vector<pair<int,string>> ocupacaoUCsAno(std::string ano);
};


#endif //PROJECT_AED_MENUOCUPACAO_H
