#include <virtuabotixRTC.h>

#include "system.h"
#include "pages.h"








void setup() {
//myRTC.setDS1302Time(1,20,22, 4, 11, 12, 2021);
    Serial.begin(9600);
    LcdInit();
    showSplash(2000);

    readAlarmsFromEEPROM();
    /*newAlarm(&budzik, alarm_t {10, 33, 1, 10, 38});
    newAlarm(&budzik, alarm_t {12,30,0,12,35});*/


    //removeAlarm(&budzik, 2);

}

void loop() {
    switch (sys.page) {
        //Główna strona
        case 0:
            MainPageHandler();
            break;
        default:
            sys.page=0;
            break;
    }


}