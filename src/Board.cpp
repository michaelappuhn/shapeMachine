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
//#include "Row.h" // some day

Board::Board()
{
    this->settings(20, 20);
}

Board::Board(float w, float h)
{
    this->settings(w, h);
}

Board::~Board(){ // Destructor
    
}

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

void Board::drawAllRows(){
    for (int rowNumber = 0; rowNumber < this->getShapesInHeight(); rowNumber++) {
        this-> drawRowOfShapes( rowNumber);
    }
    
}

void Board::drawRowOfShapes( int rowNumber ) {
    // Breaks down Shape drawing on the board into one horizontal row at a time
    // starting from the top left corner
    for (int shapeNumberInRow = 0; shapeNumberInRow < this->getShapesInWidth(); shapeNumberInRow++) {
        this->drawShape( shapeNumberInRow, rowNumber );
    }
}

void Board::drawShape(int topLeftX, int topLeftY){ // Bad naming
    // This sucks, need to refactor and make more dynamic
    Shape * shape = new RightTriangle( topLeftX * this->shapeHeight, topLeftY * this->shapeHeight, this->shapeWidth, 1);
    shape->draw();
    delete shape;
    
}

// Set the pattern of the shapes on the board to a series of Shapes.
// This doesn't make sense yet, needs renaming / refactoring
void Board::setPattern(int p1, int p2)
{
    this->patternLength1 = p1;
    this->patternLength2 = p2;
}
