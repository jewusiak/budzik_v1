#ifndef BUDZIK_PAGES_H
#define BUDZIK_PAGES_H


#include <LiquidCrystal_I2C.h>

void LcdInit();


void ShowSplash(int delayTime);

void ShowMain();

void MainPageHandler();



#endif //BUDZIK_PAGES_H
