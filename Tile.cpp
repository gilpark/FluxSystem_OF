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
    dist = 0;
    
    dist2color = ofMap(dist,-10,10,0,255);
    isGoal = false;
    cDebug = false;
    isPassible = true;
    visited = false;
    
}
Tile::Tile(int res){
}
Tile::~Tile(){}

void Tile::draw(float _x, float _y){
    dist2color = ofMap(dist,-10,10,0,255);
    x = _x;
    y = _y;
    if(isGoal){
        ofSetColor(255, 0,255, dist2color);
    }
    else{
        ofSetColor(0,0,200,dist2color);
    }
    ofFill();
    ofRect(x,y,size,size);
    if(isPassible){
        ofSetColor(255,255,0);
        ofRect(x+size/2,y+size/2,3,3);}


    ofSetColor(255);
    //ofDrawBitmapString(ofToString(id)+":", x+3,y+10); //id
    ofSetColor(255,50);
    ofDrawBitmapString(ofToString(dist), x+20,y+10); //id
    
  }

