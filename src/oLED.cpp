#include "Arduino.h"
#include "oLED.h"
#include "ssd1306.h"

Sprite::Sprite(){}

Sprite::Sprite(int posX, int posY, int width, uint8_t* buffer){
  sp = ssd1306_createSprite(posX, posY, width, buffer);
}

void Sprite::draw() {
  sp.draw();
}

void Sprite::erase() {
  sp.erase();
}

void Sprite::setPosition(int posX, int posY) {
  sp.setPos(posX, posY);
}

int Sprite::getX() {
  return sp.x;
}

int Sprite::getY() {
  return sp.y;
}

int Sprite::getW() {
  return sp.w;
}

oLED::oLED() {}

void oLED::load() {
  ssd1306_128x64_i2c_init();
  ssd1306_setFixedFont(ssd1306xled_font6x8);
}

void oLED::fill(uint8_t pixels) {
  ssd1306_fillScreen(pixels);
}

void oLED::clear() {
  ssd1306_clearScreen();
}

void oLED::drawPixel(int x, int y) {
  ssd1306_putPixel(x, y);
}

void oLED::drawPixels(int x, int y, uint8_t pixels) {
  ssd1306_putPixels(x, y, pixels);
}

void oLED::drawLine(int x1, int y1, int x2, int y2) {
  ssd1306_drawLine(x1, y1, x2, y2);
}

void oLED::drawRect(int x1, int y1, int x2, int y2) {
  ssd1306_drawRect(x1, y1, x2, y2);
}

void oLED::drawText(int posX, int posY, int height, char* text) {
  if (height < 0 || height > 4) return;
  ssd1306_printFixedN(posX, posY, text, STYLE_NORMAL, height);
}

void oLED::drawText(int posX, int posY, int height, char* text, char style) {
  if (height < 0 || height > 4) return;
  switch (style) {
    case 'i':
      ssd1306_printFixedN(posX, posY, text, STYLE_ITALIC, height);
      break;
    case 'b':
      ssd1306_printFixedN(posX, posY, text, STYLE_BOLD, height);
      break;
    default:
      ssd1306_printFixedN(posX, posY, text, STYLE_NORMAL, height);
  }
}

void oLED::drawBitmap(int x1, int y1, int w, int h, uint8_t* buffer) {
  ssd1306_drawBitmap(x1, y1, w, h, buffer);
}

Sprite oLED::createSprite(int posX, int posY, int width, uint8_t* buffer) {
  return Sprite(posX, posY, width, buffer);
}