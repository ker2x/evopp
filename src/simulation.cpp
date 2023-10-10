#include "simulation.h"

void simulation::setup()
{
	simulation::width = ofGetWidth();
	simulation::height = ofGetHeight();
	simulation::paused = false;
	simulation::render = true;
}

void simulation::update()
{
	simulation::width = ofGetWidth();
	simulation::height = ofGetHeight();
}

void simulation::draw()
{
	simulation::width = ofGetWidth();
	simulation::height = ofGetHeight();
}