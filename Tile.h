//
//  Tile.h
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#ifndef __EmoFlux__Tile__
#define __EmoFlux__Tile__

#include <stdio.h>
#include "ofMain.h"
#include "Particle.h"

class Tile{
public:
    Tile();
    Tile(int _x, int _y);
    ~Tile();
    void draw(float x, float y);
    void reset_val();
    void update();
    
    int id;
    int size;
    int p_counter;
    float cost;
    float cost2color;
    bool isGoal; //distance from the goal
    bool cDebug;
    bool isPassible;
    bool Reset;
    float x,y;
    ofVec2f direction;
    
    vector<shared_ptr<Particle> > particles;
};
#endif /* defined(__EmoFlux__Tile__) */
