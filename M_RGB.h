#pragma once
#include <Arduino.h>

template<uint8_t Rpin, uint8_t Gpin, uint8_t Bpin>
struct LED {
  LED() {
    pinMode(Rpin, OUTPUT);
    pinMode(Gpin, OUTPUT);
    pinMode(Bpin, OUTPUT);
  }

  void setHUE(byte color) {                                    // пространство RGB
    if (color < 85) setRGB(85 - color, color, 0);              // если значение цвета меньше 85 то, установить такие цвета
    else if (color < 170) setRGB(0, 170 - color, color - 85);  // если значение цвета меньше 170 то, установить такие цвета
    else setRGB(color - 170, 0, 255 - color);                  // иначе такие цвета
  }

  void setRGB(uint8_t Rclr, uint8_t Gclr, uint8_t Bclr) {  // обновить цвет
    analogWrite(Rpin, Rclr);                               // уровень красново
    analogWrite(Gpin, Gclr);                               // уровень зелёного
    analogWrite(Bpin, Bclr);                               // уровень синего
  }
};
