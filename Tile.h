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
    void test_input(int _x, int _y);
 
    int id;
    int size;
    float dist;
    float dist2color;
    bool isGoal; //distance from the goal
    bool cDebug;
    bool isPassible;
    bool visited;
    float x,y;
    //float mouseX,mouseY;
};
#endif /* defined(__EmoFlux__Tile__) */
