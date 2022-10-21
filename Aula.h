#ifndef PROJECT_AED_AULA_H
#define PROJECT_AED_AULA_H

#include <string>

using namespace std;

class Aula{
public:
    Aula(const string &weekday, float startHour, float duration, const string &type);

    const string &getWeekday() const;
    float getStartHour() const;
    float getDuration() const;
    const string &getType() const;

    void setWeekday(const string &weekday);
    void setStartHour(float startHour);
    void setDuration(float duration);
    void setType(const string &type);

private:
    string weekday;
    float startHour;
    float duration;
    string type;
};

#endif //PROJECT_AED_AULA_H
