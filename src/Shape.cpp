//
//  ShapeBox.cpp
//  -------------------------------------------
//
//  Created by Michael on 10/24/15.
//
//

#include "Shape.h"
#include <string>
#include "ofVec2f.h"
#include "ofMain.h"

using namespace std;

Shape::Shape(){}

Shape::Shape( float tlx, float tly, float sz) : topLeft(tlx, tly), size(sz)
{
    ofSetColor(255,255,255, 80);    // white, transparent, for testing
   
}


float Shape::getHeight() { return this->size; }

float Shape::getWidth() { return this->size; }


/* ------------------------------------------------
Shape GridCoordinate Getters
All of these are functions to get the x/y coordinates
 of a grid space like the one below:
 
 TopLeft ->  +---+---+  <-- e.g. TopRight!
             |   |   |
             +---+---+
             |   |   |
             +---+---+  <-- e.g. BottomRight!
                 ^
                 BottomCenter!
 
 From here, we can make shapes :-)
 ------------------------------------------------*/

// TOP LEFT
float Shape::getGridTopLeftX(){
    return this->getGridTopLeftX();
}
float Shape::getGridTopLeftY(){
    return this->getGridTopLeftY();
}

// TOP RIGHT
float Shape::getGridTopRightX(){
    // x value is the x value of topleft plus its width.
    return this->getGridTopLeftX() + this->getWidth();
}
float Shape::getGridTopRightY(){
    return this->getGridTopLeftY();
}

// BOTTOM LEFT
float Shape::getGridBottomLeftX(){
    return this->getGridTopLeftX();
}
float Shape::getGridBottomLeftY(){
    // y value is y plus the height of the grid
    return this->getGridTopLeftY() + this->getHeight() ;
}

// BOTTOM RIGHT
float Shape::getGridBottomRightX(){
    // Top left corner x value (starting point) plus the width
    return this->getGridTopLeftX() + this->getWidth();
}
float Shape::getGridBottomRightY(){
    // Top left corner y value (starting point) plus the height
    return this->getGridTopLeftY() + this->getHeight();
}

// CENTER CENTER
float Shape::getGridCenterX(){
    // Center of the value is half the width value plus the starting point
    return this->getGridTopLeftX() + ( this->getWidth() / 2) ;
}
float Shape::getGridCenterY(){
    // Center of the
    return this->getGridTopLeftY() + ( this->getHeight() / 2 );
}

// TOP CENTER
float Shape::getGridTopCenterX(){
    // This value is in the center
    return this->getGridCenterX();
}
float Shape::getGridTopCenterY(){
    // This value is at the top of the grid
    return this->getGridTopLeftY();
}

// BOTTOM CENTER
float Shape::getGridBottomCenterX(){
    // X value is the center point of the grid
    return this->getGridCenterX();
}

float Shape::getGridBottomCenterY(){
    // This value is at the bottom
    return this->getGridBottomLeftY();
}

// LEFT CENTER
float Shape::getGridLeftCenterX(){
    // This value is all the way to the left
    return this->getGridTopLeftX();
}
float Shape::getGridLeftCenterY(){
    // This value is the center
    return this->getGridCenterY();
}

// RIGHT CENTER
float Shape::getGridRightCenterX(){
    // This value is all the way to the right
    return this->getGridTopRightX();
}
float Shape::getGridRightCenterY(){
    // This value is in the center
    return this->getGridCenterY();
}


RightTriangle::RightTriangle(float tlx, float tly, float sz, short an) : Shape(tlx, tly, sz), angle(an){
}

void RightTriangle::draw (){

    // Change the angle of the right triangle based on input
    // Refactor this to describe the hypotenuse with an enumeration using compas direcitons
    switch (this->angle) {
        case (1): // Southeast Hypotenuse
            ofTriangle( this->getGridBottomLeftX(), this->getGridBottomLeftY(), this->getGridTopLeftX(), this->getGridTopLeftY(), this->getGridTopRightX(), this->getGridTopRightY() );
            break;
            
        case (2): // Southwest Hypotenuse
            ofTriangle( this->getGridTopLeftX(), this->getGridTopLeftY(), this->getGridBottomRightX(), this->getGridBottomRightY(), this->getGridTopRightX(), this->getGridTopRightY() );
            break;
            
        case (3): // Northwest Hypotenuse
            ofTriangle( this->getGridTopRightX(), this->getGridTopRightY(), this->getGridBottomRightX(), this->getGridBottomRightY(), this->getGridBottomLeftX(), this->getGridBottomLeftY() );
            break;

        case (4): //
            ofTriangle( this->getGridBottomRightX(), this->getGridBottomRightY(), this->getGridBottomLeftX(), this->getGridBottomLeftY(), this->getGridTopLeftX(), this->getGridTopLeftY() );
            break;
            
    }
}

Circle::Circle(float tlx, float tly, float sz) : Shape(tlx, tly, sz)
{}

// Draw the circle, with a width based on the input radius 'r'
void Circle::draw (float r)
{
    ofCircle (this->getGridCenterX(), this->getGridCenterY(), r);
}

IsoTriangle::IsoTriangle(float tlx, float tly, float sz) : Shape(tlx, tly, sz)
{}

// Draw an Isoceles (sp?) triangle
void IsoTriangle::draw()
{
    // Currently this way for testing
    ofTriangle( this->getGridBottomLeftX(), this->getGridTopLeftY(),
               this->getGridTopCenterX(), this->getGridTopCenterY(),
               this->getGridBottomRightX(), this->getGridBottomRightY()
   );
    
}

