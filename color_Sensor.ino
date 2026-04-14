#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define OUT 2
#define LED_PIN 13

int red = 0, green = 0, blue = 0;
int rVal, gVal, bVal;

String colorName = "";

void setup() {
  lcd.begin(16, 2);

  pinMode(S0, OUTPUT); pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT); pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(LED_PIN, HIGH);

  lcd.print("Color Sensor");
  delay(1000);
  lcd.clear();
}

void loop() {

  // 🔴 Read RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(OUT, LOW);
  delay(50);

  // 🟢 Read GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = pulseIn(OUT, LOW);
  delay(50);

  // 🔵 Read BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = pulseIn(OUT, LOW);
  delay(50);

  // 🔧 Mapping (adjusted for your sensor)
  rVal = constrain(map(red, 20, 300, 255, 0), 0, 255);
  gVal = constrain(map(green, 20, 300, 255, 0), 0, 255);
  bVal = constrain(map(blue, 20, 300, 255, 0), 0, 255);

  // 🎨 FINAL CALIBRATED COLOR DETECTION

  // BLACK
  if (rVal < 90 && gVal < 80 && bVal < 90) {
    colorName = "BLACK";
  }
  
  //wHITE
  else if (rVal > 240 && gVal > 240 && bVal > 240) {
    colorName = "WHITE";
  }

  // YELLOW
  else if (rVal > 240 && gVal > 230 && bVal > 210) {
    colorName = "YELLOW";
  }

  // ORANGE
  else if (rVal > 240 && gVal > 175 && gVal < 210 && bVal > 160 && bVal < 200) {
    colorName = "ORANGE";
  }

  // PINK
  else if (rVal > 235 && bVal > 220 && gVal > 170 && gVal < 200) {
    colorName = "PINK";
  }

  // RED
  else if (rVal > 230 && gVal > 120 && gVal < 160 && bVal > 140 && bVal < 180) {
    colorName = "RED";
  }

  // GREEN
  else if (gVal > 190 && rVal > 150 && bVal > 150) {
    colorName = "GREEN";
  }

  // BLUE
  else if (bVal > 200 && rVal < 150 && gVal < 150) {
    colorName = "BLUE";
  }

  // VIOLET
  else if (bVal > 210 && rVal > 200 && gVal < 170) {
    colorName = "VIOLET";
  }

  else {
    colorName = "UNKNOWN";
  }

  // 🖥️ DISPLAY (NO BLINK)

  lcd.setCursor(0, 0);
  lcd.print("Color:        ");
  lcd.setCursor(7, 0);
  lcd.print(colorName);

  lcd.setCursor(0, 1);
  lcd.print("R:");
  lcd.print(rVal);
  lcd.print(" G:");
  lcd.print(gVal);
  lcd.print(" B:");
  lcd.print(bVal);

  delay(300);
}