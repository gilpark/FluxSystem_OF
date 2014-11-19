//
//  Particle.h
//  EmoFlux
//
//  Created by GILL PARK on 11/18/14.
//
//

#ifndef __EmoFlux__Particle__
#define __EmoFlux__Particle__

#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__EmoFlux__Particle__) */
class Particle{
    Particle(float x, float y, float ms, float mf);
    Particle();
    ~Particle();
    
    void run();
    void follow(ofVec2f flow);
    void applyForce(ofVec2f force);
    void update();
    void draw();
    void borders();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxforce;    // Maximum steering force
    float maxspeed;    // Maximum speed
    int age;
    bool dead = false;
    ofColor ran;
};