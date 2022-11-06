#ifndef PROJECT_AED_AULA_H
#define PROJECT_AED_AULA_H

#include <string>

using namespace std;

/**
 * \brief Classe Aula
 *
 * Uma aula é definida pelo dia da semana em que é realizada, pela sua hora de começo, pela sua duração (em horas) e pelo seu tipo (T, TP ou PL).
 */
class Aula{
public:
    /**
     * \brief Constructor da classe "Aula".
     *
     * Complexidade O(1).
     *
     * @param weekday Dia da semana em que é realizada a aula.
     * @param startHour Hora de começo da aula.
     * @param duration Duração da aula (em horas).
     * @param type Tipo de aula (T, TP ou PL).
     */
    Aula(const string &weekday, float startHour, float duration, const string &type);

    /**
     * \brief Accessor do atributo "weekday".
     *
     * Complexidade O(1).
     *
     * @return Dia da semana em que é realizada a aula.
     */
    const string &getWeekday() const;

    /**
     * \brief Accessor do atributo "startHour".
     *
     * Complexidade O(1).
     *
     * @return Hora de começo da aula.
     */
    float getStartHour() const;

    /**
     * \brief Accessor do atributo "duration".
     *
     * Complexidade O(1).
     *
     * @return Duração da aula (em horas).
     */
    float getDuration() const;

    /**
     * \brief Accessor do atributo "type".
     *
     * Complexidade O(1).
     *
     * @return Tipo de aula (T, TP ou PL).
     */
    const string &getType() const;

private:
    string weekday;
    float startHour;
    float duration;
    string type;
};

#endif //PROJECT_AED_AULA_H
