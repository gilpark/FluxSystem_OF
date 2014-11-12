//
//  FluxSystem.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "FluxSystem.h"

FluxSystem::FluxSystem(){
    
}

FluxSystem::FluxSystem(int res, int w, int h){
    resolution = res;
    width = w;
    height = h;
    
    //cout << "Fluxsystme- resolution : "<< resolution << "\n";
}

FluxSystem::~FluxSystem(){
}

void FluxSystem::setup(){
    pField = PotentialField( resolution, width, height); //matching up the size of cell
    pField.setup();
}
void FluxSystem::update(){
    pField.update();
}
void FluxSystem::draw(){
    pField.draw();
}
void FluxSystem::mReleased(){
    pField.mReleased();
}