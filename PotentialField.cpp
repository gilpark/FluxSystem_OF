//
//  PotentialField.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "PotentialField.h"


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

    for(int i=0; i < numCells; i++){
        shared_ptr<Tile> tempCell(new Tile());
        shared_ptr<Tile> Cell(new Tile());
        tempCell->size = resolution;
        tempCell->id = i;
        temp_cells.push_back(tempCell);
        
        Cell->size = resolution;
        Cell->id = i;
        Cell->direction = ofVec2f(0,0);
        cells.push_back(Cell);
    }
    
    cout<<"cell size : "<<cells.size()<<" temp_cell_size : "<<temp_cells.size()<<"\n";
  
}
void PotentialField::update(){
}
void PotentialField::mReleased(){

    
    column = int(ofClamp(ofGetMouseX()/resolution,0,cols-1));
    row = int(ofClamp(ofGetMouseY()/resolution,0,rows-1));
    int test_cell =  row * cols +column;
    
    int ran = ofRandom(-10,10);
    temp_cells[test_cell]->cost=ran; //add val into cell
    temp_cells[test_cell]->isGoal = true;
    testID = test_cell;
    
    calculateField(testID);
    for(int i=0; i < cells.size(); i++){
        if(cells[i]->cost==0 && !temp_cells[i]->isPassible)
        cells[i]->cost = temp_cells[i]->cost;
        cells[i]->isPassible = temp_cells[i]->isPassible;

        
        if(cells[i]->cost!=0&&!cells[i]->isPassible&&!temp_cells[i]->isPassible){
            cells[i]->cost =(cells[i]->cost+ temp_cells[i]->cost*0.5)*0.5;

        }
        temp_cells[i]->reset_val();
        calculateVecs(i);
    }

}
void PotentialField::calculateVecs(int _id){
    
    int _x = _id%cols;
    int _y = _id/cols;
    int _column = int(ofClamp(_x,0,cols-1));
    int _row = int(ofClamp(_y,0,rows-1));
    //int testingID = row * cols + column;
    
    int N,E,S,W;
    N = (_row-1) * cols + _column;
    E = _row * cols + _column+1;
    S = (_row+1) * cols + _column;
    W = _row * cols + _column-1;
    
    int vecX,vecY;
    if(W>0 && E<rows-1)
    vecX = cells[E]->cost - cells[W]->cost;
    if(N>0&&S<cols-1)
    vecY = cells[S]->cost - cells[N]->cost;

    cells[_id]->direction.set(vecX,vecY);
}

void PotentialField::findNeighbors(int _x, int _y){
    int _column = int(ofClamp(_x,0,cols-1));
    int _row = int(ofClamp(_y,0,rows-1));
    int testingID = _row * cols + _column;
    //cout <<"testingID : "<<testingID<<" x : "<<column<<" y :"<<row<<"\n";
    
    int N,E,S,W;
    N = (_row-1) * cols + _column;
    E = _row * cols + _column+1;
    S = (_row+1) * cols + _column;
    W = _row * cols + _column-1;
    
    
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

