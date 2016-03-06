#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int rows = 2; // counting 0 also (so 2 rows)
const int columns = 16; // counting 0 also (so 16 columns)

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  // position cursor top left
  lcd.home();
}

void loop() {
  // clear the screen
  lcd.clear();
  for(int x = 0;x < 5;x++) {
    char CHAR = random(65,91); // char in decimal (look it up on google, if you don't know)
    printRandom(CHAR);
  }
  delay(100);
}

void printRandom(char c) {
    // set cursor on random location on screen
    lcd.setCursor(random(columns),random(rows));
    // print the given char
    lcd.print(c);
}
