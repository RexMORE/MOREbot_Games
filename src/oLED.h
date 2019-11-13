#ifndef oLED_h
#define oLED_h

#include "Arduino.h"
#include "ssd1306.h"

class Sprite
{
  public:
    Sprite();
    Sprite(int posX, int posY, int width, uint8_t* buffer);
    void draw();
    void erase();
    void setPosition(int posX, int posY);
    int getX();
    int getY();
    int getW();
    
  private:
    SPRITE sp;
};

class oLED 
{
  public:
    oLED();
    void load();
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