//
//  PotentialField.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "PotentialField.h"
int column;
int row;

PotentialField::PotentialField(){
}
PotentialField::PotentialField(int res, int w, int h){
    resolution = res;
    width = w;
    height = h;
    testID =-1;
    pDebug = false;
    //cout <<"cells size : "<<cells.size()<<"\n";
}
PotentialField::~PotentialField(){}

void PotentialField::setup(){
    
    cols = width/resolution;
    rows = height/resolution;
    int numCells = cols * rows;
    //cells.resize(numCells);
    
    for(int i=0; i < numCells; i++){
        shared_ptr<Tile> tempCell(new Tile());
        shared_ptr<Tile> Cell(new Tile());
        tempCell->size = resolution;
        tempCell->id = i;
        temp_cells.push_back(tempCell);
        cells.push_back(Cell);

        cells[i]->id = temp_cells[i]->id;
    }
    cout<<"cell size : "<<cells.size()<<" temp_cell_size : "<<temp_cells.size()<<"\n";
    //cout<<"what's in the temp cell? : " <<temp_cells[400]<<"\n";
    //cout<<"what's in the cell? : " <<cells[0]<<"\n";
    

}
void PotentialField::update(){
}
void PotentialField::mReleased(){
    
    column = int(ofClamp(ofGetMouseX()/resolution,0,cols-1));
    row = int(ofClamp(ofGetMouseY()/resolution,0,rows-1));
    int test_cell =  row * cols +column;
    
    int ran = ofRandom(1,5);
    temp_cells[test_cell]->cost=10; //add val into cell
    temp_cells[test_cell]->isGoal = true;
    testID = test_cell;
    
    calculateField(testID);

    
}

void PotentialField::findNeighbors(int _x, int _y){
    int column = int(ofClamp(_x,0,cols-1));
    int row = int(ofClamp(_y,0,rows-1));
    int testingID = row * cols + column;
    //cout <<"testingID : "<<testingID<<" x : "<<column<<" y :"<<row<<"\n";
    
    int N,E,S,W;
    N = (row-1) * cols + column;
    E = row * cols + column+1;
    S = (row+1) * cols + column;
    W = row * cols + column-1;
    
    
    if(temp_cells[N]->isPassible){
        if(temp_cells[testingID]->cost>0) //when the input val is positive
            temp_cells[N]->cost = temp_cells[testingID]->cost-1;
        if(temp_cells[testingID]->cost<0) //when the input val is negative
            temp_cells[N]->cost = temp_cells[testingID]->cost+1;
        testList.push_back(N);
    }
    
    if(temp_cells[E]->isPassible){
        if(temp_cells[testingID]->cost>0) //when the input val is positive
            temp_cells[E]->cost = temp_cells[testingID]->cost-1;
        if(temp_cells[testingID]->cost<0) //when the input val is negative
            temp_cells[E]->cost = temp_cells[testingID]->cost+1;
        testList.push_back(E);
    }
    
    if(temp_cells[S]->isPassible){
        if(temp_cells[testingID]->cost>0) //when the input val is positive
            temp_cells[S]->cost = temp_cells[testingID]->cost-1;
        if(temp_cells[testingID]->cost<0) //when the input val is negative
            temp_cells[S]->cost = temp_cells[testingID]->cost+1;
        testList.push_back(S);
    }
    
    
    if(temp_cells[W]->isPassible){
        if(temp_cells[testingID]->cost>0) //when the input val is positive
            temp_cells[W]->cost = temp_cells[testingID]->cost-1;
        if(temp_cells[testingID]->cost<0) //when the input val is negative
            temp_cells[W]->cost = temp_cells[testingID]->cost+1;
        testList.push_back(W);
    }
    
}
void PotentialField::calculateField(int _id){
    
    testList.push_back(_id);
    
    while(testList.size()){
        testList.unique();
        int targetN = testList.front();
        testList.pop_front(); //delete target one
        int CurrentX = targetN%cols;
        int CurrentY = targetN/cols;
        //cout << "X : "<<CurrentX<<" Y :"<<CurrentY<<"\n";
        if(temp_cells[targetN]->isPassible){
            temp_cells[targetN]->isPassible = false;
            if(CurrentY<=0||CurrentX<=0||CurrentY>=rows-1||CurrentX>=cols-1)continue;
            if(temp_cells[targetN]->cost != 0){
                findNeighbors(CurrentX, CurrentY);
            }
            
        }
    }
    
}

void PotentialField::draw(){
    
    
    for(int x=0; x < cols; x++){
        for(int y=0; y < rows; y++){
            int id = y * cols +x;
            cells[id]->draw(x*resolution,y*resolution);
        }
    }
}

