#include "Arduino.h"
#include "gamesKit.h"
#include "oLED.h"
#include "ssd1306.h"

dispMem::dispMem(){
	for(int i = 0; i < 128; i++){
		for(int j = 0; j < 64; j++){
			memArray[i][j] = 0b00000000;
		}
	}
}

uint8_t dispMem::setMemBit(int x, int y){
	int byteY = y / 8;
	int bitY  = y % 8;

	uint8_t newBit = 0b00000001 << bitY;

	return memArray[x][byteY] = memArray[x][byteY] | newBit;
}

uint8_t dispMem::setMemByte(int x, int y, uint8_t b){
	return memArray[x][y] = b;
}

bool dispMem::getMemBit(int x, int y){
	int byteY = y / 8;
	int bitY  = y % 8;
	uint8_t compareBit = 1 - (0b00000001 << bitY);

	return memArray[x][y] | compareBit;
}

uint8_t dispMem::getMemByte(int x, int y){
	return memArray[x][y];
}

bool dispMem::clearMem(){
	for(int i = 0; i < 128; i++){
		for(int j = 0; j < 64; j++){
			memArray[i][j] = 0b00000000;
		}
	}
}

void dispMem::getFullArray(uint8_t outArray[][8]){
	outArray = memArray;
}

gameController::gameController(){
	inputs[0] = defLeft;
	inputs[1] = defRight;
	inputs[2] = defUp;
	inputs[3] = defDown;
	inputs[4] = defXaxis;
	inputs[5] = defYaxis;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4; i++){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}


gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown){
	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = defXaxis;
	inputs[5] = defYaxis;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4; i++){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}

gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY){
	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = joyX;
	inputs[5] = joyY;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4; i++){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}

gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY, int joyS){
	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = joyX;
	inputs[5] = joyY;
	inputs[6] = joyS;

	for(int i = 0; i < 4; i++){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}

void gameController::load(){
	display.load();
	display.clear();
}

void gameController::useMemory(){
	memFlag = true;
	scrnMem = new dispMem();
}

void gameController::dumpMemory(){
	memFlag = false;
	delete scrnMem;
}

void gameController::loadInputs(){
	for(int i = 0; i < 7; i++){
		int newin = 0;
		if(i>3 && i < 6){
			newin = analogRead(inputs[i]);
		}else{
			newin = digitalRead(inputs[i]);
		}

		if(inputVals[i] != newin){
			inputVals[i] = newin;
		}
	}
}

bool gameController::leftPressed(){
	return inputVals[0] == 0;
}

bool gameController::rightPressed(){
	return inputVals[1] == 0;
}

bool gameController::upPressed(){
	return inputVals[2] == 0;
}

bool gameController::downPressed(){
	return inputVals[3] == 0;
}

int gameController::joyXValue(){
	return inputVals[4];
}

int gameController::joyYValue(){
	return inputVals[5];
}

bool gameController::joyPressed(){
	return inputVals[7] == 1;
}

void gameController::fill(uint8_t pixels) {
	for(int i = 0; i < 128; i++){
		for(int j = 0; j < 8; j++){
			drawPixels(i, j, pixels);
		}
	}
}

void gameController::clear() {
	if(memFlag) scrnMem->clearMem();
  	display.clear();
}

void gameController::drawPixel(int x, int y) {
  	if(memFlag) display.drawPixels(x, 8*(y/8), scrnMem->setMemBit(x, y));
  	else display.drawPixel(x, y);
}

void gameController::drawPixels(int x, int y, uint8_t pixels) {
	if(memFlag){
		if(y % 8 == 0){
			display.drawPixels(x, y, scrnMem->setMemByte(x, y, pixels));
		}else{
			uint8_t comp = 0b00000001;
			for(int i = 0; i < 8; i++){
				if(1-comp | pixels) drawPixel(x, y+i);
				comp << 1;
			}
		}
	}else{
		display.drawPixels(x, y, pixels);
	}
}

void gameController::drawLine(int x1, int y1, int x2, int y2) {
  	display.drawLine(x1, y1, x2, y2);
}

void gameController::drawRect(int x1, int y1, int x2, int y2) {
	if(memFlag){
		if(x1 > x2){
			int tx = x1;
			x1 = x2;
			x2 = tx;
		}
		if(y1 > y2){
			int ty = y1;
			y1 = y2;
			y2 = ty;
		}

		for(int x = x1; x < x2; x++){
			drawPixel(x, y1);
			drawPixel(x, y2);
		}
		for(int y = y1; y < y2; y++){
			drawPixel(x1, y);
			drawPixel(x2, y);		
		}
	}else{
		display.drawRect(x1, y1, x2, y2);
	}
}

void gameController::drawText(int posX, int posY, int height, char* text) {
  	display.drawText(posX, posY, height, text);
}

void gameController::drawText(int posX, int posY, int height, char* text, char style) {
  	display.drawText(posX, posY,  height, text, style);
}

void gameController::drawBitmap(int x1, int y1, int w, int h, uint8_t* buffer) {
  	display.drawBitmap(x1, y1, w, h, buffer);
}

Sprite gameController::createSprite(int posX, int posY, int width, uint8_t* buffer) {
  	return Sprite(posX, posY, width, buffer);
}