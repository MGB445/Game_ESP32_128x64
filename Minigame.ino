#include <Adafruit_SSD1306.h>
#include <splash.h>

//---------------------------------------
// Test_3
//---------------------------------------


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "main.hpp"
#include "button.hpp"
#include "designs.hpp"
#include "design_objects.hpp"
#include "data_worlds.hpp"


struct sMovements {
  int ucPosX;
  int ucPosY;
  unsigned char ucMovement;
};

sMovements Player = {10, 10, 0};
sMovements Fireball;

unsigned char ucAnimation;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  
  Serial.begin(115200);

  init_Button(0);   // init without interrupt

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Startup   owo");
  display.display();
  
  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH);

  delay(1000);

  Player.ucPosX = 20;
  init_Button(1);   // init interrupt
}

void loop() {
  
  display.clearDisplay();

  /*ucAnimation++;

  if(ucAnimation == 30) {
    Player.ucPosY++;
  }
  else if(ucAnimation == 60) {
    Player.ucPosY--;
    ucAnimation = 0;
  }*/

  if(Player.ucMovement&0x3F) {
    if(digitalRead(ci_BUTTON[DEF_UP])) {
      Player.ucMovement &= ~(1<<DEF_UP);
    }
    if(digitalRead(ci_BUTTON[DEF_DOWN])) {
      Player.ucMovement &= ~(1<<DEF_DOWN);
    }
    if(digitalRead(ci_BUTTON[DEF_LEFT])) {
      Player.ucMovement &= ~(1<<DEF_LEFT);
    }
    if(digitalRead(ci_BUTTON[DEF_RIGHT])) {
      Player.ucMovement &= ~(1<<DEF_RIGHT);
    }
    if(digitalRead(ci_BUTTON[DEF_EXTRA_1])) {
      Player.ucMovement &= ~(1<<DEF_EXTRA_1);
    }
    if(digitalRead(ci_BUTTON[DEF_EXTRA_2])) {
      Player.ucMovement &= ~(1<<DEF_EXTRA_2);
    }
    
    switch(Player.ucMovement & 0x03) {
    case 1<<DEF_UP:
      if(!(cWorlddata[(Player.ucPosY-1) / 8][Player.ucPosX / 8] & 0x80)) {
        if(Player.ucPosY > 0) {
          Player.ucPosY--;
        }
      }
      break;
    case 1<<DEF_DOWN:
      if(!(cWorlddata[(Player.ucPosY+8) / 8][Player.ucPosX / 8] & 0x80)) {
        if(Player.ucPosY < SCREEN_HEIGHT-1-8) {
          Player.ucPosY++;
        }
      }
      break;
    }
    switch(Player.ucMovement & 0x0C) {
    case 1<<DEF_LEFT:
      Player.ucMovement |= 1<<DEF_LOOKHORIZONTAL;
      if(!(cWorlddata[Player.ucPosY / 8][(Player.ucPosX-1) / 8] & 0x80)) {
        if(Player.ucPosX > 0) {
          Player.ucPosX--;
        }
      }
      break;
    case 1<<DEF_RIGHT:
      Player.ucMovement &= ~(1<<DEF_LOOKHORIZONTAL);
      if(!(cWorlddata[Player.ucPosY / 8][(Player.ucPosX+8) / 8] & 0x80)) {
        if(Player.ucPosX < SCREEN_WIDTH-1-8) {
          Player.ucPosX++;
        }
      }
      break;
    }
    switch(Player.ucMovement & 0x30) {
    case 1<<DEF_EXTRA_1:
      if(!(Fireball.ucMovement & 0x04)) {
        Fireball.ucMovement |= 0x04;    // Fireball active
        Fireball.ucMovement |= Player.ucMovement & (1<<DEF_LOOKHORIZONTAL);
        Fireball.ucPosY = Player.ucPosY;
        if(Player.ucMovement & (1<<DEF_LOOKHORIZONTAL)) {
          Fireball.ucPosX = Player.ucPosX-6;
        }
        else {
          Fireball.ucPosX = Player.ucPosX+6;
        }
      }
      break;
    case 1<<DEF_EXTRA_2:

      break;
    }
  }


  if(Fireball.ucMovement) {
    if(Fireball.ucMovement & (1<<DEF_LOOKHORIZONTAL)) {
      if(Fireball.ucPosX > 1) {
        display.drawBitmap(Fireball.ucPosX, Fireball.ucPosY, cDesignFireballLeft, 8, 8, WHITE);
        Fireball.ucPosX -= 2;
      }
      else {
        Fireball.ucMovement = 0;
      }
    }
    else {
      if(Fireball.ucPosX < SCREEN_WIDTH-1-8) {
        display.drawBitmap(Fireball.ucPosX, Fireball.ucPosY, cDesignFireballRight, 8, 8, WHITE);
        Fireball.ucPosX += 2;
      }
      else {
        Fireball.ucMovement = 0;
      }
    }
  } 

  if(Player.ucMovement & (1<<DEF_LOOKHORIZONTAL)) {
    display.drawBitmap(Player.ucPosX, Player.ucPosY, cDesignPlayerLeft, 8, 8, WHITE);
  }
  else {
    display.drawBitmap(Player.ucPosX, Player.ucPosY, cDesignPlayerRight, 8, 8, WHITE);
  }
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 16; j++) {
      if(cWorlddata[i][j] != 0) {
        if(cWorlddata[i][j] & 0x40) {
          display.drawBitmap(j*8, i*8, &cInteraction[cWorlddata[i][j]&0x3F][0], 8, 8, WHITE);
        }
        else {
          display.drawBitmap(j*8, i*8, &cObjects[cWorlddata[i][j]&0x3F][0], 8, 8, WHITE);
        }
      }
    }
  }

  display.display();
}


void IRAM_ATTR INTERRUPT_BUTTON_UP() {
  Player.ucMovement |= 1<<DEF_UP;
}

void IRAM_ATTR INTERRUPT_BUTTON_DOWN() {
  Player.ucMovement |= 1<<DEF_DOWN;
}

void IRAM_ATTR INTERRUPT_BUTTON_LEFT() {
  Player.ucMovement |= 1<<DEF_LEFT;
}

void IRAM_ATTR INTERRUPT_BUTTON_RIGHT() {
  Player.ucMovement |= 1<<DEF_RIGHT;
}

void IRAM_ATTR INTERRUPT_BUTTON_EXTRA_1() {
  Player.ucMovement |= 1<<DEF_EXTRA_1;
}

void IRAM_ATTR INTERRUPT_BUTTON_EXTRA_2() {
  Player.ucMovement |= 1<<DEF_EXTRA_2;
}
