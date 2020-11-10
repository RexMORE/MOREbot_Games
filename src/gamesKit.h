#ifndef gamesKit_h
#define gamesKit_h

#include "Arduino.h"
#include "oLED.h"

class gameController 
{
  public:
    oLED display;

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
    void drawRect(int posX, int posY, int width, int height);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawText(int posX, int posY, int height, char* text);
    void drawText(int posX, int posY, int height, char* text, char style);
    void drawPixel(int x, int y);
    void drawPixels(int x, int y, uint8_t pixels);
    void drawBitmap(int x, int y, int width, int height, uint8_t* buffer);
    Sprite createSprite(int posX, int posY, int width, uint8_t* buffer);
    void clear();
    void fill(uint8_t pixels);
};

#endif