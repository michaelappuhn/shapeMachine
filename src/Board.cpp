//
//  WindowBoard.cpp
//  
//
//  Created by Michael on 10/24/15.
//
//

#include "Board.h"
#include "ofPoint.h"
#include "ofAppRunner.h"

Board::Board()
{
    this->settings(20, 20);
}

Board::Board(float w, float h)
{
    this->settings(w, h);
}

Board::~Board(){} // Destructor


void Board::settings(float w, float h)
{
    // On call, change the settings of the board
    this->shapeWidth = w;
    this->shapeHeight = h;
    
    // I'm not sure what this is, need to refactor
    this->patternLength1 = 1;
    this->patternLength2 = 1;
    this->patternSwitch = 0;
}

int Board::getShapesInWidth(){
    // Set the number of shapes to match the window width
    return (ofGetWindowWidth() / shapeWidth) + 1;
}

int Board::getShapesInHeight(){
    // Set the number of shapes to match the window height
    return (ofGetWindowHeight() / shapeHeight) + 1;
    
}

void Board::drawShapesOntoBoard()
{
    
    for (int x = 0; x < this->getShapesInWidth(); x++)
    {
        //
        for (int y = 0; y < this->getShapesInHeight(); y++)
        {
            Shape * s = new RightTriangle( x * shapeHeight, y * this->shapeHeight, this->shapeWidth, 1);
            // Shape * s = new IsoTriangle( x * shapeHeight, y * this->shapeHeight, this->shapeWidth, 1);
            s->draw();
            
        }
        
    }
}


void Board::setPattern(int p1, int p2)
{
    this->patternLength1 = p1;
    this->patternLength2 = p2;
}