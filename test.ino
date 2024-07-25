#include "SimpleDuino.ino"

TwoMotors myrobot;

void setup() {
	myrobot.begin(2, 3, 4, 5, 9, 11);
}

void loop() {
	myrobot.forward();
	delay(500);
	myrobot.backward();
	delay(500);
}
