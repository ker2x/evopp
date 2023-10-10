#include "ofMain.h"
#include "../simulation.h"

#pragma once
class cell
{
public:
	cell(ofVec2f position, ofColor color);
	void setup();
	void update();
	void draw();

	ofColor color;
	ofVec2f pos;
	float energy;
	bool alive = true;

private:
	void move(ofVec2f direction);
};

