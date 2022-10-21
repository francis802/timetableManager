#include "Aula.h"


Aula::Aula(const string &weekday, float startHour, float duration, const string &type) : weekday(weekday),
                                                                                         startHour(startHour),
                                                                                         duration(duration),
                                                                                         type(type) {}

const string &Aula::getWeekday() const {return weekday;}
float Aula::getStartHour() const {return startHour;}
float Aula::getDuration() const {return duration;}
const string &Aula::getType() const {return type;}

void Aula::setWeekday(const string &weekday) {Aula::weekday = weekday;}
void Aula::setStartHour(float startHour) {Aula::startHour = startHour;}
void Aula::setDuration(float duration) {Aula::duration = duration;}
void Aula::setType(const string &type) {Aula::type = type;}
