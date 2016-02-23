//  WindowBoard.h
//  Created by Michael on 10/24/15.

#ifndef ____Board__
#define ____Board__

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
    
    // This is for creating alternating patterns in the loop
    // e.g. A Circle, then an IsoTriange
    int patternLength1, patternLength2;
    int patternSwitch; // This is to switch between patterns
    
    void drawRowOfShapes( int yRowInPosition );
    void drawShape( int x, int y );
    void drawAllRows();
    
public:
    Board();
    Board(float w, float h);
    ~Board();
    
    float getShapeContainerHeight();
    float getShapeContainerWidth();
    
    // Get the number of Shapes that fit on one Board given the current settings.
    int getShapesInWidth();
    int getShapesInHeight();
    
    void settings(float shapeWidth, float shapeHeight);
    void setPattern(int shapes1, int shapes2);

    void drawShapesOntoBoard();
    
};


#endif /* defined(____Board__) */
