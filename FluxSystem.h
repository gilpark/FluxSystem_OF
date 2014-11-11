//
//  FluxSystem.h
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#ifndef __EmoFlux__FluxSystem__
#define __EmoFlux__FluxSystem__

#include <stdio.h>
#include "PotentialField.h"
#include "ofMain.h"

class FluxSystem{
public:
    FluxSystem();
    FluxSystem(int res,int w, int h);
    ~FluxSystem();
    
    void setup();
    void update();
    void draw();
    void test_input(int i);

    int resolution;
    int width,height;
    PotentialField pField;
};

#endif /* defined(__EmoFlux__FluxSystem__) */
