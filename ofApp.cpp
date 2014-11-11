#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    ofBackground(0);
    

    flux = FluxSystem(100,width,height);
    flux.setup();
    //cout<< "flux.res :  " <<flux.resolution <<"\n";
    mPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    flux.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    flux.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    mPressed = !mPressed;

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
