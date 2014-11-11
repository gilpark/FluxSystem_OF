//
//  PotentialField.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "PotentialField.h"
std::list<int>::iterator findIter;
list<int> visitedList;

PotentialField::PotentialField(){
//    pDebug = false;
}
PotentialField::PotentialField(int res, int w, int h){
    resolution = res;
    width = w;
    height = h;
    testID =-1;
    pDebug = false;
    cout <<"cells size : "<<cells.size()<<"\n";
}
PotentialField::~PotentialField(){}

void PotentialField::setup(){
    
    cols = width/resolution;
    rows = height/resolution;
    int numCells = cols * rows;
    
    for(int i=0; i < numCells; i++){
        shared_ptr<Tile> pCell(new Tile());
        pCell->size = resolution;
        pCell->id = i;
//cout<<i<<"\n";
        cells.push_back(pCell);
    }
}
void PotentialField::update(){

    //testing input field
    int column = int(ofClamp(ofGetMouseX()/resolution,0,cols-1));
    int row = int(ofClamp(ofGetMouseY()/resolution,0,rows-1));
    int test_cell =  row * cols +column;
    //cout<< "C : " << column<<" row : "<<row<<" ID : "<<test_cell<<"\n";

    if(ofGetMousePressed()){
        int ran = ofRandom(-10,10);
        cells[test_cell]->dist=ran; //add val into cell
        cells[test_cell]->isGoal = true;
        testID = test_cell;
        //visitedList.clear();

        calculateField(testID);
    }
    
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
 
    visitedList.push_back(N);
    visitedList.push_back(S);
    //visitedList.push_back(E);
    //visitedList.push_back(W);

    findIter = std::find(visitedList.begin(), visitedList.end(), N);

    if(cells[N]->isPassible){
        if(cells[testingID]->dist>0) //when the input val is positive
        cells[N]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0) //when the input val is negative
            cells[N]->dist = cells[testingID]->dist+1;
        testList.push_back(N);
    }
    if(!cells[N]->isPassible && *findIter==N){
        cells[N]->dist = int((cells[testingID]->dist+cells[N]->dist)*0.5);
    }
    
    findIter = std::find(visitedList.begin(), visitedList.end(), E);
    
    if(cells[E]->isPassible){
        if(cells[testingID]->dist>0)
            cells[E]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
                cells[E]->dist = cells[testingID]->dist+1;
        testList.push_back(E);
    }
    if(!cells[E]->isPassible && *findIter==E){
        cells[E]->dist = int((cells[testingID]->dist+cells[E]->dist)*0.5);
    }
    
    findIter = std::find(visitedList.begin(), visitedList.end(), S);
    
    if(cells[S]->isPassible){
        if(cells[testingID]->dist>0)
        cells[S]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
            cells[S]->dist = cells[testingID]->dist+1;
        testList.push_back(S);
    }
    if(!cells[S]->isPassible && *findIter==S){
        cells[S]->dist = int((cells[testingID]->dist+cells[S]->dist)*0.5);
    }
    
    findIter = std::find(visitedList.begin(), visitedList.end(), W);
    
    if(cells[W]->isPassible){
        if(cells[testingID]->dist>0)
        cells[W]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
            cells[W]->dist = cells[testingID]->dist+1;
        testList.push_back(W);
    }
    if(!cells[W]->isPassible && *findIter==W){
        cells[W]->dist = int((cells[testingID]->dist+cells[W]->dist)*0.5);
    }
//    cout<< " N : "<<N<< " E : "<<E<< " S : "<<S<< " W : "<<W<<"\n";
//    cout<<"test id : "<<testID<<"'s val :"<<cells[testID]->dist<<" and passible : "<<cells[testID]->isPassible<<"\n";
    
}
void PotentialField::calculateField(int _id){

    if(!cells[_id]->isPassible){ //if the value is already set
        visitedList.push_back(_id); //add to visited list

        while(visitedList.size()){
            visitedList.unique();
            int targetN = visitedList.front();
            cout<< "visit : target : "<<targetN<<"\n";
            visitedList.pop_front(); //delete target one
            int CurrentX = targetN%cols;
            int CurrentY = targetN/cols;
            //cout << "X : "<<CurrentX<<" Y :"<<CurrentY<<"\n";
            findIter = std::find(visitedList.begin(), visitedList.end(), targetN);
            if(!cells[targetN]->isPassible&& *findIter==targetN ){
                if(CurrentY<=0||CurrentX<=0||CurrentY>=rows-1||CurrentX>=cols-1)continue;
                if(cells[targetN]->dist != 0){
                    findNeighbors(CurrentX, CurrentY);
                }
            cout<<"vlist--- size : "<<visitedList.size()<<"\n";
            }
        }
        cout<<"1st while loop is done\n";
 
    }
    
    
    
    if(cells[_id]->isPassible){
        testList.push_back(_id);
        //cout<<"testlist size : "<<testList.size()<<"\n";
        
        while(testList.size()){
            testList.unique();
            int targetN = testList.front();
            testList.pop_front(); //delete target one
            int CurrentX = targetN%cols;
            int CurrentY = targetN/cols;
            //cout << "X : "<<CurrentX<<" Y :"<<CurrentY<<"\n";
            if(cells[targetN]->isPassible){
                cells[targetN]->isPassible = false;
                if(CurrentY<=0||CurrentX<=0||CurrentY>=rows-1||CurrentX>=cols-1)continue;
                if(cells[targetN]->dist != 0){
                    findNeighbors(CurrentX, CurrentY);
                }

            }
        }
        cout<<"2nd while loop is done\n";
    }

    cout <<"v list size : "<<visitedList.size()<<"\n";

}

void PotentialField::draw(){
    
    
    for(int x=0; x < cols; x++){
        for(int y=0; y < rows; y++){
            int id = y * cols +x;
            cells[id]->draw(x*resolution,y*resolution);
        }
    }
}

