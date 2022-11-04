#ifndef PROJECT_AED_UCTURMA_H
#define PROJECT_AED_UCTURMA_H

#include <string>
#include <list>
#include "Aula.h"

using namespace std;

/**
 * \brief Classe UCTurma
 *
 * A turma de uma UC (Unidade Curricular) é definida pelo código da UC, pelo código da turma e pelo horário.
 */
class UCTurma{
public:
    /**
     * \brief Constructor da classe "UCTurma".
     *
     * Complexidade O(1).
     *
     * @param codTurma Código da turma.
     * @param codUC Código da UC.
     */
    UCTurma(string codTurma, string codUC);

    /**
     * \brief Default constructor da classe "UCTurma".
     *
     * Complexidade O(1).
     */
    UCTurma();

    /**
     * \brief Modifier do atributo "timetable".
     *
     * Complexidade O(1).
     *
     * @param aula Aula a adicionar ao horário.
     */
    void addAula(Aula aula);

    /**
     * \brief Accessor do atributo "codUC".
     *
     * Complexidade O(1).
     *
     * @return Código da UC.
     */
    const string &getCodUc() const;

    /**
     * \brief Accessor do atributo "codTurma".
     *
     * Complexidade O(1).
     *
     * @return Código da turma.
     */
    const string &getCodTurma() const;

    /**
     * \brief Accessor do atributo "timetable".
     *
     * Complexidade O(1).
     *
     * @return Horário.
     */
    const list<Aula> &getTimetable() const;

private:
    string codUC;
    string codTurma;
    list<Aula> timetable;
};

#endif //PROJECT_AED_UCTURMA_H
