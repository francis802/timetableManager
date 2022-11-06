
#ifndef PROJECT_AED_PEDIDO_H
#define PROJECT_AED_PEDIDO_H


#include "Estudante.h"

/**
 * \brief Classe Pedido
 *
 * Classe utilizada para criar um objeto "Pedido" que contém n parâmetros, de forma a organizar e armazenar a informação de forma mais elegante na alteração de horários.
 */
class Pedido {
private:
    int code;
    string codTurma;
    string codUC;

public:
    /**
     * \brief Default constructor da classe "Pedido".
     *
     * Complexidade O(1).
     */
    Pedido();

    /**
     * \brief Modifier do atributo "codUC".
     *
     * Complexidade O(1).
     *
     * @param codUc Código da UC.
     */
    void setCodUc(const string &codUc);

    /**
     * \brief Modifier do atributo "codTurma".
     *
     * Complexidade O(1).
     *
     * @param codTurma Código da turma.
     */
    void setCodTurma(const string &codTurma);

    /**
     * \brief Modifier do atributo "code".
     *
     * Complexidade O(1).
     *
     * @param code Código UP.
     */
    void setCode(int code);

    /**
     * \brief Accessor do atributo "codUC".
     *
     * Complexidade O(1)
     *
     * @return Código UC.
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
     * \brief Accessor do atributo "code".
     *
     * Complexidade O(1).
     *
     * @return Código UP.
     */
    int getCode() const;
};

#endif //PROJECT_AED_PEDIDO_H