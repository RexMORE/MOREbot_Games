#ifndef gamesKit_h
#define gamesKit_h

#include "Arduino.h"
#include "oLED.h"

class dispMem
{
private:
    uint8_t memArray[128][8];

public:
    dispMem();

    uint8_t setMemBit(int x, int y);
    uint8_t setMemByte(int x, int y, uint8_t b);

    bool    getMemBit(int x, int y);
    uint8_t getMemByte(int x, int y);

    bool    clearMem();
    void    getFullArray(uint8_t outArray[][8]);
};

class gameController 
{
private:
    oLED display;
    dispMem* scrnMem;

    bool memFlag = false;


public:
    int defLeft = 7;
    int defRight = 6;
    int defUp = 5;
    int defDown = 4;
    int defXaxis = A0;
    int defYaxis = A1;
    int defSaxis = A2;
    int inputs[7];
    int inputVals[7];

    gameController();
    gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown);
    gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY);
    gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY, int joyS);

    void load();

    void loadInputs();
    bool leftPressed();
    bool rightPressed();
    bool upPressed();
    bool downPressed();
    int joyXValue();
    int joyYValue();
    bool joyPressed();

    oLED getDisplay();

    void useMemory();
    void dumpMemory();

    void drawPixel(int x, int y);
    void drawPixels(int x, int y, uint8_t pixels);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawRect(int x1, int y1, int x2, int y2);
    void drawText(int x, int y, int h, char* text);
    void drawText(int x, int y, int h, char* text, char style);

    void drawBitmap(int x, int y, int w, int h, uint8_t* buffer);
    Sprite createSprite(int x, int y, int w, uint8_t* buffer);

    void clear();
    void fill(uint8_t pixels);
};

#endif