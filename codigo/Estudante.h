#ifndef PROJECT_AED_ESTUDANTE_H
#define PROJECT_AED_ESTUDANTE_H

#include <string>
#include "UCTurma.h"

using namespace std;

/**
 * \brief Classe Estudante
 *
 * Um estudante é definido pelo seu código UP, pelo seu nome e pelas turmas em que está inscrito.
 */
class Estudante{
public:
    /**
     * \brief Constructor da classe "Estudante".
     *
     * Complexidade O(1).
     *
     * @param code Código UP do estudante.
     * @param name Nome do estudante.
     */
    Estudante(int code, const string &name);

    /**
     * \brief Default constructor da classe "Estudante".
     *
     * Complexidade O(1).
     */
    Estudante();

    /**
     * \brief Overloader do operator "<".
     *
     * Retorna "true" se o código UP do primeiro estudante for menor que o do segundo, se não retorna "false". Complexidade O(1).
     *
     * @param s Segundo estudante.
     * @return 'true' ou 'false'.
     */
    bool operator<(const Estudante &s) const;

    /**
     * Adiciona uma turma à lista de turmas em que o estudante está inscrito. Complexidade O(1).
     *
     * @param turma Turma a adicionar.
     */
    void addTurma(UCTurma turma);

    /**
     * Remove uma turma da lista de turmas em que o estudante está inscrito. Complexidade O(n).
     *
     * @param turma Turma a remover.
     */
    void removeTurma(UCTurma turma);

    /**
     * \brief Accessor do atributo "name".
     *
     * Complexidade O(1).
     *
     * @return Nome do estudante.
     */
    const string getName() const;

    /**
     * \brief Accessor do atributo "turmas".
     *
     * Complexidade O(1).
     *
     * @return Lista de turmas em que o estudante está inscrito.
     */
    const list<UCTurma> &getTurmas() const;

    /**
     * \brief Modifier do atributo "code".
     *
     * Complexidade O(1).
     *
     * @param code Código UP do estudante.
     */
    void setCode(int code);

    /**
     * \brief Accessor do atributo "code".
     *
     * Complexidade O(1).
     *
     * @return Código UP do estudante.
     */
    int getCode() const;

    /**
     * \brief Modifier do atrivuto "name".
     *
     * Complexidade O(1).
     *
     * @param name Nome do estudante.
     */
    void setName(const string &name);

private:
    int code;
    string name;
    list<UCTurma> turmas;
};

#endif //PROJECT_AED_ESTUDANTE_H
