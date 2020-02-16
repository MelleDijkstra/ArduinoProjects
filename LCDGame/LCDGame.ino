#include <LiquidCrystal.h>
#include <QueueList.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int COLS = 15;
const int ROWS = 1;

class Player
{
  private:
    int score = 0;

  public:
    int col = 0;
    int row;

    Player(int x) {
      row = x;
    }

    void Draw() {
      lcd.setCursor(col, row);
      lcd.write(">");
    }

    void AddScore(int amount) {
      score += amount;
    }

    void SwitchSide() {
      if (row == 0) {
        row = 1;
      } else {
        row = 0;
      }
    }

    int GetScore() {
      return score;
    }

    String ToString() {
      return "Players score: " + String(score) + ", row: " + String();
    }
};

class Ship
{
  private:
    int col;
    int row;
    int _size = 2;

  public:
    Ship(int x, int y) {
      col = x;
      row = y;
    }

    void Draw() {
      if (col <= COLS && row <= ROWS && col >= 0 - _size && row >= 0) {
        lcd.setCursor(col, row);
        lcd.write("<-");
      }
    }

    void Update(Player p) {
      if (col > 0 - _size) {
        col--;
      }

      if (p.row == row) {
        Serial.println("Ship is on same row as player");
      }

      Serial.println(this->toString());
    }

    String toString() {
      return "[" + String(col) + "," + String(row) + "]";
    }
};

Player player(0);
QueueList<Ship> ships;

bool gameIsRunning;

int input = 0;

void setup() {

  Serial.begin(9600);

  Serial.println("Serial communication established!");
  lcd.begin(16, 2);
  gameIsRunning = true;
}

void loop() {

  if(Serial.available() > 0) {
    input = Serial.read();
    if(input == 112) {
      gameIsRunning = !gameIsRunning;  
    }
  }

  if (gameIsRunning) {
    if (Serial.available() > 0) {
      input = Serial.read();
      // space
      if (input == 32) {
        player.SwitchSide();
      }
      // r
      if (input == 114) {
        ships.push(Ship(COLS - 2, random(0, 2)));
      }
    }

    player.Draw();
    for(int i = 0;i < ships.count();i++) {
      ships[i].Draw();
      ships[i].Update(player);
    }
    delay(1000);
    lcd.clear();
  }
}
