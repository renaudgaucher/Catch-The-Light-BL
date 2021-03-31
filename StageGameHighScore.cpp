#include "StageGameHighScore.h"

StageGameHighScore::StageGameHighScore(Gameboard* gameboard) :Stage(gameboard)
{
}

byte StageGameHighScore::run() {
	Serial.println(F("HighScore"));
	return EXIT;
}