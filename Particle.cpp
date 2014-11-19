//
//  Particle.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/18/14.
//
//

#include "Particle.h"

// Flow Field Following
// Daniel Shiffman <http://www.shiffman.net>
// The Nature of Code, Spring 2011

Particle::Particle(){}
Particle::Particle(float x,float y, float ms, float mf) {
    location = ofVec2f(x,y);
    r = 3.0;
    maxspeed = ms;
    maxforce = mf;
    acceleration = ofVec2f(0, 0);
    velocity = ofVec2f(0, 0);
    age = (int)ofRandom(50,200); //1sec
    ran = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
}
Particle::~Particle(){}

void Particle::run() {
    update();
    borders();
    //draw();
}


void Particle::follow(ofVec2f flow) {
    // What is the vector at that spot in the flow field?
    ofVec2f desired = flow;
    location = location+desired/10;
    // Scale it up by maxspeed
    
    //        desired.mult(maxspeed);
    //        // Steering is desired minus velocity
    //        PVector steer = PVector.sub(desired, velocity);
    //        steer.limit(maxforce);  // Limit to maximum steering force
    //        applyForce(steer);
}

void Particle::applyForce(ofVec2f force) {
    // We could add mass here if we want A = F / M
    //acceleration.add(force);
}

// Method to update location
void Particle::update() {
    // Update velocity
    //velocity.add(acceleration);
    // Limit speed
    velocity.limit(maxspeed);
    //location.add(velocity);
    // Reset accelertion to 0 each cycle
    //acceleration.mult(0);
    
    //        history.add(location.get());
    //    if (history.size() > 500) {
    //      history.remove(0);
    //    }
    //
    age--;
    if(age < 0 ) dead = !dead;
}

void Particle::draw() {
    //    // Draw a triangle rotated in the direction of velocity
    ofSetColor(255);
    //ofPushMatrix();

    ofCircle(location.x, location.y, 1);
    //ofPopMatrix();
    
}

// Wraparound
void Particle::borders() {
    if (location.x < -r) location.x = ofGetWindowWidth()+r;
    if (location.y < -r) location.y = ofGetWindowHeight()+r;
    if (location.x > ofGetWindowWidth()+r) location.x = -r;
    if (location.y > ofGetWindowHeight()+r) location.y = -r;
}


