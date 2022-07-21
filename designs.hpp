#ifndef designs_hpp
#define designs_hpp


//---------------------------------------------------------------------------------------------
static const unsigned char cDesignPlayerLeft[] PROGMEM = {
  0b10100100,
  0b00111100,
  0b10010110,
  0b10111101,
  0b11111101,
  0b10111111,
  0b00111100,
  0b00100100
};
static const unsigned char cDesignPlayerRight[] PROGMEM = {
  0b00100101,
  0b00111100,
  0b01101001,
  0b10111101,
  0b10111111,
  0b11111101,
  0b00111100,
  0b00100100,
};

const unsigned char cDesignFireballLeft[] PROGMEM = {
  0b00000000,
  0b01110000,
  0b11001100,
  0b11111111,
  0b10011100,
  0b01100000,
  0b00000000,
  0b00000000
};
const unsigned char cDesignFireballRight[] PROGMEM = {
  0b00000000,
  0b00001110,
  0b00110011,
  0b11111111,
  0b00111001,
  0b00000110,
  0b00000000,
  0b00000000
};
//---------------------------------------------------------------------------------------------

const unsigned char cDesignDog[] PROGMEM = {
  0b00000000,
  0b00000000,
  0b01010000,
  0b01010000,
  0b01110001,
  0b11111101,
  0b00111110,
  0b00100010
};

const unsigned char cDesignSkull[] PROGMEM = {
  0b00000000,
  0b01111100,
  0b10010010,
  0b10010010,
  0b11111110,
  0b11101110,
  0b01111100,
  0b01010100
};

const unsigned char cDesignArcher[] PROGMEM = {
  0b01001111,
  0b10011110,
  0b10000110,
  0b10011110,
  0b11111111,
  0b10011111,
  0b10011110,
  0b01010010
};

const unsigned char cDesignKnight[] PROGMEM = {
  0b01001111,
  0b01011110,
  0b01000110,
  0b01011110,
  0b01111111,
  0b01011111,
  0b00011110,
  0b00010010
};


#endif //designs_hpp
