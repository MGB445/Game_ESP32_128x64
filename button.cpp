#include "arduino.h"
#include "main.hpp"
#include "button.hpp"

void init_Button(char Selection) {
  switch(Selection) {
  case 0:
    pinMode(ci_BUTTON[DEF_UP], INPUT_PULLUP);
    pinMode(ci_BUTTON[DEF_DOWN], INPUT_PULLUP);
    pinMode(ci_BUTTON[DEF_LEFT], INPUT_PULLUP);
    pinMode(ci_BUTTON[DEF_RIGHT], INPUT_PULLUP);
    pinMode(ci_BUTTON[DEF_EXTRA_1], INPUT_PULLUP);
    pinMode(ci_BUTTON[DEF_EXTRA_2], INPUT_PULLUP);
    break;
  case 1:
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_UP]), INTERRUPT_BUTTON_UP, FALLING);
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_DOWN]), INTERRUPT_BUTTON_DOWN, FALLING);
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_LEFT]), INTERRUPT_BUTTON_LEFT, FALLING);
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_RIGHT]), INTERRUPT_BUTTON_RIGHT, FALLING);
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_EXTRA_1]), INTERRUPT_BUTTON_EXTRA_1, FALLING);
    attachInterrupt(digitalPinToInterrupt(ci_BUTTON[DEF_EXTRA_2]), INTERRUPT_BUTTON_EXTRA_2, FALLING);
    break;
  }
}
