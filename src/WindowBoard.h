//  WindowBoard.h
//  Created by Michael on 10/24/15.

#ifndef ____WindowBoard__
#define ____WindowBoard__

#include <stdio.h>
#include "Shape.h"
#include "ofPoint.h"


// On initialization, this board calculates the width and height of the window
// and creates a series of "Shape" objects
// to match that via 2-dimensional array,
// using the shape's width and height to determine that.

class Board {
    // A board is the container for a series of Shapes
    Shape * s;
    
    // Variables to determine the number of Shapes on the Board
    int shapesInWidth, shapesInHeight;
    
    // Variables to set all Shapes' width and height — cascades to Shape
    int shapeWidth, shapeHeight;
    
    // This is for creating horizontal patterns in the loop
    int patternLength1, patternLength2;
    
    
    int patternSwitch; // This is to switch between patterns
public:
    Board();
    Board(float w, float h);
    ~Board();
    
    int getShapesInWidth();
    int getShapesInHeight();
    
    void settings(float shapeWidth, float shapeHeight);
    void drawShapesOntoBoard();
    void setPattern(int shapes1, int shapes2);
    
};


#endif /* defined(____WindowBoard__) */
