//
//  PotentialField.h
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#ifndef __EmoFlux__PotentialField__
#define __EmoFlux__PotentialField__

#include <stdio.h>
#include "ofMain.h"
#include "Tile.h"

class PotentialField{

public:
    PotentialField();
    PotentialField(int res, int w, int h);
    ~PotentialField();
    
    void setup();
    void update();
    void draw();
    void calculateField(int _id);
    void findNeighbors(int _x,int _y);
    bool pDebug;
    int cols,
        rows,
        resolution,
        width,
        height,
        testID;
    
    vector<shared_ptr<Tile> > cells;
    list<int> Neihbors;
    list<int> testList;

    //vector<shared_ptr<Tile> > testNeighbours;
 
};
#endif /* defined(__EmoFlux__PotentialField__) */
