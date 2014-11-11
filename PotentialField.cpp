//
//  PotentialField.cpp
//  EmoFlux
//
//  Created by GILL PARK on 11/5/14.
//
//

#include "PotentialField.h"

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
    if(cells[N]->isPassible){
        if(cells[testingID]->dist>0) //when the input val is positive
        cells[N]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0) //when the input val is negative
            cells[N]->dist = cells[testingID]->dist+1;
        testList.push_back(N);
    }
    E = row * cols + column+1;
    if(cells[E]->isPassible){
        if(cells[testingID]->dist>0)
            cells[E]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
                cells[E]->dist = cells[testingID]->dist+1;
        testList.push_back(E);
    }
    S = (row+1) * cols + column;
    if(cells[S]->isPassible){
        if(cells[testingID]->dist>0)
        cells[S]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
            cells[S]->dist = cells[testingID]->dist+1;
        testList.push_back(S);
    }
    W = row * cols + column-1;
    if(cells[W]->isPassible){
        if(cells[testingID]->dist>0)
        cells[W]->dist = cells[testingID]->dist-1;
        if(cells[testingID]->dist<0)
            cells[W]->dist = cells[testingID]->dist+1;
        testList.push_back(W);
    }
    //cout<< " N : "<<N<< " E : "<<E<< " S : "<<S<< " W : "<<W<<"\n";
    //cout<<"test id : "<<testID<<"'s val :"<<cells[testID]->dist<<" and passible : "<<cells[testID]->isPassible<<"\n";
    
}
void PotentialField::calculateField(int _id){
    list<int> visitedList;
    if(cells[_id]->isPassible){ 
        testList.push_back(_id);
        //cout<<"testlist size : "<<testList.size()<<"\n";
        
        while(testList.size()){
            int targetN = testList.front();
            visitedList.push_back(targetN); //add to visited list
            visitedList.unique();

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
    }
//    //std::list<int>::iterator findIter = std::find(visitedList.begin(), visitedList.end(), 1);
//    if(!cells[_id]->isPassible){
//        testList.push_back(_id);
//        //cout<<"testlist size : "<<testList.size()<<"\n";
//        
//        while(testList.size()){
//            int targetN = testList.front();
//            visitedList.push_back(targetN); //add to visited list
//            visitedList.unique();
//            testList.pop_front(); //delete target one
//            int CurrentX = targetN%cols;
//            int CurrentY = targetN/cols;
//            //cout << "X : "<<CurrentX<<" Y :"<<CurrentY<<"\n";
//            
//            if(cells[targetN]->isPassible){
//                cells[targetN]->isPassible = false;
//                if(CurrentY<=0||CurrentX<=0||CurrentY>=rows-1||CurrentX>=cols-1)continue;
//                if(cells[targetN]->dist != 0){
//                    findNeighbors(CurrentX, CurrentY);
//                }
//                
//            }
//        }
//        //cout <<"v list size : "<<visitedList.size()<<"\n";
//    }
    cout <<"v list size : "<<visitedList.size()<<"\n";

    visitedList.clear();
}

//void PotentialField::calculateField(int _id){
//    
//        int targetID = _id;
//    if(cells[targetID]->isPassible){
//        testList.push_back(targetID);
//        //cells[targetID]->isPassible = false;
//        //cout<<"testlist size : "<<testList.size()<<"\n";
//
//        while(testList.size()){
//            int targetN = testList.front();
//            testList.pop_front(); //delete target one
//            int CurrentX = targetN%rows;
//            int CurrentY = targetN/rows;
//            cout << "X : "<<CurrentX<<" Y :"<<CurrentY<<"\n";
//            if(cells[targetN]->isPassible){
//            cells[targetID]->isPassible = false;
//            findNeighbors(CurrentX, CurrentY);
//            }
////            for(int i=0; i<Neihbors.size();i++){
////                int ntestID = Neihbors.front();
////                Neihbors.pop_front();
////                cells[ntestID]->isPassible = false;
////                int nCurrentX = targetID%rows;
////                int nCurrentY = targetID/rows;
//////                findNeighbors(nCurrentX, nCurrentY);
////                
////            }
//        }
//    }
//
//}

void PotentialField::draw(){
    
    
    for(int x=0; x < cols; x++){
        for(int y=0; y < rows; y++){
            int id = y * cols +x;
            cells[id]->draw(x*resolution,y*resolution);
        }
    }
}

