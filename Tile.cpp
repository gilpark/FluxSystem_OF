//
//  Tile.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "Tile.h"
//#include "ofBaseApp.h"
Tile::Tile(){
    id =0;
    cost = 0;
    cost2color = ofMap(cost,-10,10,0,255);
    isGoal = false;
    cDebug = false;
    isPassible = true;
    Reset = false;
}
Tile::Tile(int res){
}

Tile::~Tile(){}

void Tile::reset(){
    cost = 0;
    cost2color = ofMap(cost,-10,10,0,255);
    isGoal = false;
    cDebug = false;
    isPassible = true;
    Reset = false;
    
}
void Tile::draw(float _x, float _y){
    cost2color = ofMap(cost,-10,10,0,255);
    x = _x;
    y = _y;
    if(isGoal){
        ofSetColor(255, 0,255, cost2color);
    }
    else{
        ofSetColor(0,0,200,cost2color);
    }
    ofFill();
    ofRect(x,y,size,size);
    if(isPassible){
        ofSetColor(255,255,0);
        ofRect(x+size/2,y+size/2,3,3);}
    
    
    ofSetColor(255);
    //ofDrawBitmapString(ofToString(id)+":", x+3,y+10); //id
    ofSetColor(255,50);
    ofDrawBitmapString(ofToString(cost), x+20,y+10); //id
    
}

