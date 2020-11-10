

gameController::gameController(){
	display.load();
	display.clear();

	inputs[0] = defLeft;
	inputs[1] = defRight;
	inputs[2] = defUp;
	inputs[3] = defDown;
	inputs[4] = defXaxis;
	inputs[5] = defYaxis;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}


gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown){
	display.load();
	display.clear();

	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = defXaxis;
	inputs[5] = defYaxis;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}

gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY){
	display.load();
	display.clear();

	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = joyX;
	inputs[5] = joyY;
	inputs[6] = defSaxis;

	for(int i = 0; i < 4){
		pinMode(inputs[i], INPUT_PULLUP);
	}
}

gameController::gameController(int buttonLeft, int buttonRight, int buttonUp, int buttonDown, int joyX, int joyY, int joyS){
	display.load();
	display.clear();

	inputs[0] = buttonLeft;
	inputs[1] = buttonRight;
	inputs[2] = buttonUp;
	inputs[3] = buttonDown;
	inputs[4] = joyX;
	inputs[5] = joyY;
	inputs[6] = joyS;

	for(int i = 0; i < 4){
		pinMode(inputs[i], INPUT_PULLUP);
	}
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

bool gameContoller::leftPressed(){
	return inputVals[0] == 1;
}

bool gameContoller::rightPressed(){
	return inputVals[1] == 1;
}

bool gameContoller::upPressed(){
	return inputVals[2] == 1;
}

bool gameContoller::downPressed(){
	return inputVals[3] == 1;
}

int gameContoller::joyXValue(){
	return inputVals[4];
}

int gameContoller::joyXValue(){
	return inputVals[5];
}

bool gameContoller::joyPressed(){
	return inputVals[7] == 1;
}

void gameController::fill(uint8_t pixels) {
	display.fill(pixels);
}

void gameController::clear() {
  display.clear();
}

void gameController::drawPixel(int x, int y) {
  display.drawPixel(int x, int y);
}

void gameController::drawPixels(int x, int y, uint8_t pixels) {
  display.drawPixels(int x, int y, uint8_t pixels);
}

void gameController::drawLine(int x1, int y1, int x2, int y2) {
  display.drawLine(int x1, int y1, int x2, int y2);
}

void gameController::drawRect(int x1, int y1, int x2, int y2) {
  display.drawRect(int x1, int y1, int x2, int y2);
}

void gameController::drawText(int posX, int posY, int height, char* text) {
  display.drawText(int posX, int posY, int height, char* text);
}

void gameController::drawText(int posX, int posY, int height, char* text, char style) {
  display.drawText(int posX, int posY, int height, char* text, char style);
}

void gameController::drawBitmap(int x1, int y1, int w, int h, uint8_t* buffer) {
  display.drawBitmap(int x1, int y1, int w, int h, uint8_t* buffer);
}

Sprite gameController::createSprite(int posX, int posY, int width, uint8_t* buffer) {
  return Sprite(posX, posY, width, buffer);
}