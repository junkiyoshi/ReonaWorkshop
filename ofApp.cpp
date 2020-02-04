#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);

	this->shader.load("shader/shader.vert", "shader/shader.frag");
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<glm::vec2> targets;
	for (int i = 0; i < 100; i++) {

		float R = 180 + 90 * abs(sin((i * 100 + ofGetFrameNum() + i) * DEG_TO_RAD));
		float x = R * cos((360 * i / 100 + ofGetFrameNum() * 0.1) * DEG_TO_RAD);
		float y = R * sin((360 * i / 100 + ofGetFrameNum() * 0.1) * DEG_TO_RAD);

		targets.push_back(glm::vec2(x, y) + glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5));
	}

	this->shader.begin();
	this->shader.setUniform1f("time", ofGetElapsedTimef());
	this->shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	this->shader.setUniform2fv("targets", &targets[0].x, targets.size());

	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	this->shader.end();
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(720, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}