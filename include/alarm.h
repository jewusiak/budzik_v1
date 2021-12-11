#ifndef BUDZIK_ALARM_H
#define BUDZIK_ALARM_H


struct alarm_t {
    enum State {OFF, ON, SNOOZE, REMOVED, EMPTY_EE=0xFF};
    int base_hour;
    int base_minute;
    State state;          //state: 0 - off, 1 - on, 2 - snooze, 3/255/0xFF - disabled/removed
    int snooze_hour;
    int snooze_minute;

};


void addAlarmToSys(alarm_t alarm);

void newAlarm(alarm_t alarm);

void readAlarmsFromEEPROM();

void removeAlarm(int index);


#endif //BUDZIK_ALARM_H
