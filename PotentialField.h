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
    void mReleased();
    void calculateVecs(int _id);
    void drawVectors();
    
    bool pDebug;
    int cols,
    rows,
    resolution,
    width,
    height,
    testID;
    int column;
    int row;
    vector<shared_ptr<Tile> > cells;
    vector<shared_ptr<Tile> > temp_cells;
    list<int> testList;
    
};
#endif /* defined(__EmoFlux__PotentialField__) */
