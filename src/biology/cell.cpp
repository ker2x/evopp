#include "cell.h"

cell::cell(ofVec2f position, ofColor color)
{
	this->pos = position;
	this->color = color;
	this->alive = true;
}

void cell::setup()
{
	energy = ofRandom(50, 1000);
	alive = true;
}

void cell::update()
{

	if (alive)
	{
		// pick a random direction & spend energy according to movement distance
		ofVec2f direction = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
		energy -= direction.length() / 1000;
		move(direction);
	}
		
}

void cell::draw()
{
	ofSetColor(color);
	ofDrawRectangle(pos, 10, 10);
}

void cell::move(ofVec2f direction)
{
	// if we run out of energy, die and return
	if (energy <= 0) {
		alive = false;
		return;
	}
	else // if we didn't run out of energy, move
	{
		// move in the direction
		pos += direction;
		// stay within bounds
		if (pos.x < 0) pos.x = 0;
		if (pos.x > simulation::width) pos.x = 0;
		if (pos.y < 0) pos.y = 0;
		if (pos.y > simulation::height) pos.y = simulation::height;
	}
}