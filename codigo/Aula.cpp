#include "Aula.h"


Aula::Aula(const string &weekday, float startHour, float duration, const string &type) : weekday(weekday),
                                                                                         startHour(startHour),
                                                                                         duration(duration),
                                                                                         type(type) {}

const string &Aula::getWeekday() const {return weekday;}
float Aula::getStartHour() const {return startHour;}
float Aula::getDuration() const {return duration;}
const string &Aula::getType() const {return type;}
