/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
/******************************
******************************/
ofApp::ofApp()
: check_id(0)
{
}

/******************************
******************************/
ofApp::~ofApp()
{
}

/******************************
******************************/
void ofApp::exit(){
	printf("> Good bye\n");
}

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("shader study");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	ofEnableSmoothing();
	
	/********************
	********************/
	img.load("image.png");
	shader.load( "sample.vert", "sample.frag");
	fbo.allocate(WIDTH, HEIGHT, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
/******************************
description
******************************/
void ofApp::draw(){
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	fbo.begin();
	shader.begin();
	ofPushMatrix();
	ofTranslate(ofGetWidth(), 0);
	ofScale(-1, 1, 1);
	
		shader.setUniform1i( "check_id", check_id );
		
		shader.setUniform2f( "u_resolution", ofGetWidth(), ofGetHeight() );
		shader.setUniform2f( "u_mouse", mouseX, mouseY );
		// ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		img.draw(0, 0, ofGetWidth(), ofGetHeight());
		
	ofPopMatrix();
	shader.end();
	fbo.end();
	
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
			check_id = key - '0';
			break;
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
