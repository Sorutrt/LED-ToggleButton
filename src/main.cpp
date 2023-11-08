#include <Arduino.h>
#include <M5Core2.h>

#define BUTTON  13   //ボタンのONOFF検知
#define LED_PIN 14   //LEDのONOFFに

bool btnWasPress = false;  //前回ループ時のボタン状態
bool btnIsPress  = false;  //今回ループ時のボタン状態
bool ledIsOn     = false;  //現在のLEDの状態

void setup() {
  M5.begin();
  pinMode(BUTTON, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  btnIsPress = digitalRead(BUTTON);

  if (btnIsPress && !(btnWasPress)) {
    if (!(ledIsOn)) {
      ledIsOn = true;
      digitalWrite(LED_PIN, LOW);
    } else {
      ledIsOn = false;
      digitalWrite(LED_PIN, HIGH);
    }
  }

  btnWasPress = btnIsPress;
}