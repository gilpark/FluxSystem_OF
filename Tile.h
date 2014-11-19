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
class Tile{
public:
    Tile();
    Tile(int res);
    ~Tile();
    void draw(float x, float y);
    void reset_val();
    
    
    int id;
    int size;
    float cost;
    float cost2color;
    bool isGoal; //distance from the goal
    bool cDebug;
    bool isPassible;
    bool Reset;
    float x,y;
    ofVec2f direction;
    //float mouseX,mouseY;
};
#endif /* defined(__EmoFlux__Tile__) */
