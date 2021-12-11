
#include "alarm.h"
#include "system.h"
#include <EEPROM.h>
#include <Arduino.h>


void addAlarmToSys(alarm_t alarm){
    if(sys.alarms == NULL)
        sys.alarms=(alarm_t*)malloc(sizeof *sys.alarms);
    sys.alarms=(alarm_t*)realloc(sys.alarms, ++sys.all_alarms * sizeof (*(sys.alarms)));
    sys.alarms[sys.all_alarms - 1]=alarm;
    if(alarm.state==1||alarm.state==2)
        sys.active_alarms++;
}

void newAlarm(alarm_t alarm){
    addAlarmToSys( alarm);
    int i= sys.all_alarms - 1;
    EEPROM[1+5*i]=alarm.base_hour;
    EEPROM[2+5*i]=alarm.base_minute;
    EEPROM[3+5*i]=alarm.state;
    EEPROM[4+5*i]=alarm.snooze_hour;
    EEPROM[5+5*i]=alarm.snooze_minute;
    EEPROM[0]++;
}

void readAlarmsFromEEPROM(){
    if(EEPROM[0]==0xFF)
        EEPROM[0]=0;
    int to_read=min((int)EEPROM[0], 25);
    for(int i=0; i<to_read;i++)
        addAlarmToSys( (alarm_t){EEPROM[1+5*i], EEPROM[2+5*i],  static_cast<alarm_t::State>((int)EEPROM[3 + 5 * i]),
                                     EEPROM[4 + 5 * i], EEPROM[5 + 5 * i]});
}

void removeAlarm(int index){
    for(int i=index+1; i < sys.all_alarms; i++)
        sys.alarms[i - 1]=sys.alarms[i];
    sys.all_alarms--;
}
