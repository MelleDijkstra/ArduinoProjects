#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int rows = 1; // counting 0 also (so 2 rows)
const int columns = 15; // counting 0 also (so 16 columns)

int currentRow = 0;
int currentCol = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);  
  lcd.print("Ask the");

  lcd.setCursor(0,1);
  lcd.print("Crystal Ball!");

  lcd.setCursor(0,0);
}

void loop() {
  // clear the screen
  lcd.clear();
  
  // calculate positions
  if(currentCol > columns) {
    currentCol = 0;
    currentRow++;
  }
  if(currentRow > rows) {
    currentRow = 0;
  }
  
  lcd.setCursor(currentCol,currentRow);
  lcd.print("O");
  currentCol++;
  delay(1000);
}
