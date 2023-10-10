#pragma once
#include "ofMain.h"
#include "../simulation.h"

class food
{
public:
	food();
	food(ofVec2f position);

	void setup();
	void update();
	void draw();

	const ofColor color = ofColor(ofColor::green);
	const int radius = 5;

	ofVec2f pos;
	float energy;
};

