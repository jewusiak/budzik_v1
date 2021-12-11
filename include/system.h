
#ifndef BUDZIK_SYSTEM_H
#define BUDZIK_SYSTEM_H

#include "alarm.h"



struct system_t {
    int all_alarms=0;
    int active_alarms=0;
    alarm_t *alarms;
    int page=0;
};

extern system_t sys;

#endif //BUDZIK_SYSTEM_H
