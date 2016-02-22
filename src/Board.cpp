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
    //Loop through the x values…
    for (int x = 0; x < this->getShapesInWidth(); x++)
    {
        //Loop through the y values and add shapes…
        // wait; shouldn't this be the other way around?
        // I should replace this with a "drawShapeRow()" function
        for (int y = 0; y < this->getShapesInHeight(); y++)
        {

            // Create a new right triangle based on the x,y coordinates
            // Will replace with a Shape drawShapeAtCoordinates()
            Shape * s = new RightTriangle( x * shapeHeight, y * this->shapeHeight, this->shapeWidth, 1);

            // Shape * s = new IsoTriangle( x * shapeHeight, y * this->shapeHeight, this->shapeWidth, 1);
            s->draw();
            
        }
        
    }
}


// Set the pattern of the shapes on the board to a series of Shapes.
// This doesn't make sense yet, needs renaming / refactoring
void Board::setPattern(int p1, int p2)
{
    this->patternLength1 = p1;
    this->patternLength2 = p2;
}