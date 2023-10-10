#pragma once

#include "ofMain.h"


class simulation
{
public:
	static void setup();
	static void update();
	static void draw();

	inline static int width;
	inline static int height;
	inline static bool paused;
	inline static bool render;

};

