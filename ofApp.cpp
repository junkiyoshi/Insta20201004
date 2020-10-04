#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor color;
	vector<int> hex_list = { 0xef476f, 0xffd166, 0x06d6a0, 0x118ab2, 0x073b4c };
	vector<ofColor> base_color_list;
	for (auto hex : hex_list) {

		color.setHex(hex);
		base_color_list.push_back(color);
	}

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.43);
	ofRotateY(ofGetFrameNum() * 0.65);
	
	int span = 20;
	for (int x = -200; x <= 200; x += span) {

		for (int y = -200; y <= 200; y += span) {

			for (int z = -200; z <= 200; z += span) {

				ofSetColor(base_color_list[(int)ofRandom(base_color_list.size())]);
				auto noise_value = ofNoise(glm::vec4(x * 0.0045, y * 0.0045, z * 0.0045, ofGetFrameNum() * 0.008));

				if (noise_value > 0.55) {

					ofDrawSphere(glm::vec3(x, y, z), noise_value < 0.65 ? span * ofMap(noise_value, 0.55, 0.65, 0, 0.45) : span * 0.45);
				}
			}
		}
	}

	this->cam.end();
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}