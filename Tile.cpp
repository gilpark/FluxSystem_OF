//
//  Tile.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "Tile.h"
Tile::Tile(){
    id =0;
    cost = 0;
    cost2color = ofMap(cost,-10,10,0,255);
    isGoal = false;
    cDebug = false;
    isPassible = true;
    Reset = false;

}
Tile::Tile(int _x,int _y){
    x = _x;
    y = _y;
    id =0;
    cost = 0;
    cost2color = ofMap(cost,-10,10,0,255);
    isGoal = false;
    cDebug = false;
    isPassible = true;
    Reset = false;
}

Tile::~Tile(){}

void Tile::update(){
    if(cost<0 && particles.size()<5){
            shared_ptr<Particle> particle(new Particle(x+ofRandom(size/2),y+ofRandom(size/2),3,0.01));
            particles.push_back(particle);
    }

}

void Tile::reset_val(){
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
    }else if(cost == 0){
        //ofSetColor(255, 0, 255);
        ofSetColor(0,0,200,cost2color);

    }else{
        ofSetColor(0,0,200,cost2color);
    }
    ofFill();
    ofRect(x,y,size,size);
    
//    ofSetColor(255);
//    ofDrawBitmapString(ofToString(id)+":", x+3,y+10); //id
//    ofSetColor(255,50);
//    ofDrawBitmapString(ofToString(cost), x+20,y+10); //id
 }

