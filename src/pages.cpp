#include "pages.h"
#include "system.h"
#include "rtc.h"

LiquidCrystal_I2C lcd(0x27, 20,4);

void LcdInit(){
    lcd.init();
    lcd.backlight();
}

void ShowMain(){
    lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
    lcd.print(GetFormattedTime());
    lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
    lcd.print("Aktywne:");
    lcd.setCursor(11-String(sys.active_alarms).length(), 1);

    lcd.print(sys.active_alarms);
}

void ShowSplash(int delayTime){
    lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
    lcd.print("Alarm");
    lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
    lcd.print("Grzegorz Jewusiak");
    delay(delayTime);
}


void MainPageHandler(){
    while(true){

    }
}
