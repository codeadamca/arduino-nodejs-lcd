/*
  
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  
  Serial.begin(9600);
  
}

void loop() {
  
  if (Serial.available() > 0) {
    
    String receivedString = "";
    
    while (Serial.available() > 0) {
      receivedString += char(Serial.read ());
      delay(20);
    }
    
    Serial.println(receivedString);
    
    // Serial.println(receivedString);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(receivedString);  
       
  }
  
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  
}