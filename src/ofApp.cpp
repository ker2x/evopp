#include "ofApp.h"

//--------------------------------------------------------------
// Run once on startup, unless you call setup() again
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetBackgroundColor(ofColor::black);

	simulation::setup();

	cells.clear();
	foods.clear();

	for (int i = 0; i < 100; i++)
	{
		cells.push_back(cell(ofVec2f(ofRandom(0, simulation::width), ofRandom(0, simulation::height)), ofColor(ofRandom(0, 255), 0.0f, ofRandom(0, 255))));
		foods.push_back(food());
	}
}

//--------------------------------------------------------------
// Run every frame before drawing
void ofApp::update(){

	// do not update if paused
	if (!simulation::paused)
	{
		simulation::update();
		for (auto& c : cells) c.update();
		for (auto& f : foods) f.update();

		// remove cell from cells vector if cell is not alive
		cells.erase(
			std::remove_if(cells.begin(), cells.end(), [](cell& c) { return !c.alive; }), 
			cells.end()
		);

		if (cells.empty()) {
			std::cout << "All cells died. Stopping simulation." << std::endl;
			ofExit();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw even if paused but not if render is false
	if (simulation::render) {
		simulation::draw();
		for (auto c : cells) c.draw();
		for (auto f : foods) f.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_BACKSPACE) setup();
	if (key == 'p') {
		simulation::paused = !simulation::paused;
		std::cout << "Simulation is " << (simulation::paused ? "paused" : "running") << std::endl;
	}
	if (key == 'r') {
		simulation::render = !simulation::render;
		std::cout << "Rendering is " << (simulation::render ? "enabled" : "disabled") << std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
