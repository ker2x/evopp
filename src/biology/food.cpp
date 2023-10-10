#include "food.h"

food::food() {
}

food::food(ofVec2f position)
{
}

void food::setup()
{
	pos = ofVec2f(ofRandom(0, simulation::width), ofRandom(0, simulation::height));
	energy = ofRandom(500,1000);
}

void food::update()
{
	energy--;
	if (energy <= 0) { this->setup(); }
}

void food::draw()
{
	ofSetColor(color);
	ofDrawCircle(pos, radius);
}