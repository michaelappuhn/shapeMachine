//
//  WindowBoard.h
//  
//
//  Created by Michael on 10/24/15.
//
//

#ifndef ____WindowBoard__
#define ____WindowBoard__

#include <stdio.h>
#include "ShapeBox.h"
#include "ofPoint.h"


// On initialization, this board calculates the width and height of the window
// and creates a series of "Shape" objects
// to match that via 2-dimensional array,
// using the shape's width and height to determine that.

class Board {
    Shape * s;
    int shapesInWidth, shapesInHeight;
    int shapeWidth, shapeHeight;
    int patternLength1, patternLength2; // This is for creating horizontal patterns in the loop
    int patternSwitch; // This is to switch between patterns
public:
    Board();
    Board(float w, float h);
    ~Board();
    
    void settings(float shapeWidth, float shapeHeight);
    void drawShapesOntoBoard();
    void setPattern(int shapes1, int shapes2);
    
};


#endif /* defined(____WindowBoard__) */
