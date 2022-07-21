#ifndef main_hpp
#define main_hpp

//----------------------------------------------------------------------

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define NUMB_BUTTONS 6

const int ci_BUTTON[NUMB_BUTTONS] = {
  26,    // GPIO button up
  33,    // GPIO button down
  32,    // GPIO button left
  25,    // GPIO button right
  14,    // GPIO button extra_1
  27     // GPIO button extra_2
};

//---------------------------------------------------------------------

void IRAM_ATTR INTERRUPT_BUTTON_UP(void);
void IRAM_ATTR INTERRUPT_BUTTON_DOWN(void);
void IRAM_ATTR INTERRUPT_BUTTON_LEFT(void);
void IRAM_ATTR INTERRUPT_BUTTON_RIGHT(void);
void IRAM_ATTR INTERRUPT_BUTTON_EXTRA_1(void);
void IRAM_ATTR INTERRUPT_BUTTON_EXTRA_2(void);

#define DEF_UP        0
#define DEF_DOWN      1
#define DEF_LEFT      2
#define DEF_RIGHT     3
#define DEF_EXTRA_1   4
#define DEF_EXTRA_2   5
#define DEF_LOOKHORIZONTAL  6   // Left = 1, Right = 0
#define DEF_LOOKVERTICAL    7   // Up = 1, Down = 0


#endif //main_hpp
