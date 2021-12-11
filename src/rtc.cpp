#include "rtc.h"

virtuabotixRTC myRTC(6,7,8);

String GetFormattedTime(){
    myRTC.updateTime();
    char *result = (char *)(malloc(17 * sizeof *result));
    sprintf(result, "%02d:%02d  %s, %02d.%02d", myRTC.hours, myRTC.minutes, daysOfWeek[ myRTC.dayofweek].c_str(), myRTC.dayofmonth, myRTC.month);
    return result;
}
