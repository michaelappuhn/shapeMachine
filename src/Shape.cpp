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
    
    topRight.x = topLeft.x + this->getWidth(); // x value is the x value of topleft plus its width.
    topRight.y = topLeft.y;
    
    bottomLeft.x = topLeft.x;
    bottomLeft.y = topLeft.y + this->getHeight() ;
    // y value is y plus the height of the box
    
    bottomRight.x = topRight.x ;
    bottomRight.y = bottomLeft.y ;
    
    center.x = (topLeft.x + topRight.x) / 2 ;
    center.y = (topLeft.y + bottomLeft.y) / 2 ;
    
    topCenter.x = center.x ;
    topCenter.y = topRight.x;
    
    leftCenter.x = topLeft.x;
    leftCenter.y = center.y;
    
    rightCenter.x = topRight.x;
    rightCenter.y = center.y;
    

    bottomCenter.x = center.x ;
    bottomCenter.y = bottomLeft.y;
    
    

}


float Shape::getHeight() { return this->size; }

float Shape::getWidth() { return this->size; }


/* ------------------------------------------------
Shape GridCoordinate Getters
------------------------------------------------*/

float Shape::getGridTopLeftX(){
    return this->getGridTopLeftX();
}
float Shape::getGridTopLeftY(){
    return this->getGridTopLeftY();
}

float Shape::getGridTopRightX(){
    // x value is the x value of topleft plus its width.
    return this->getGridTopLeftX() + this->getWidth();
}
float Shape::getGridTopRightY(){
    return this->getGridTopLeftY();
}

float Shape::getGridBottomLeftX(){
    return this->getGridTopLeftX();
}
float Shape::getGridBottomLeftY(){
    // y value is y plus the height of the grid
    return this->getGridTopLeftY() + this->getHeight() ;
}

float Shape::getGridBottomRightX(){
    // Top left corner x value (starting point) plus the width
    return this->getGridTopLeftX() + this->getWidth();
}
float Shape::getGridBottomRightY(){
    // Top left corner y value (starting point) plus the height
    return this->getGridTopLeftY() + this->getHeight();
}

/* ------------------------
     Set the center points
 --------------------------- */

float Shape::getGridCenterX(){
    // Center of the value is half the width value plus the starting point
    return this->getGridTopLeftX() + ( this->getWidth() / 2) ;
}
float Shape::getGridCenterY(){
    // Center of the
    return this->getGridTopLeftY() + ( this->getHeight() / 2 );
}

float Shape::getGridTopCenterX(){
    // This value is in the center
    return this->getGridCenterX();
}
float Shape::getGridTopCenterY(){
    // This value is at the top of the grid
    return this->getGridTopLeftY();
}

float Shape::getGridBottomCenterX(){
    // X value is the center point of the grid
    return this->getGridCenterX();
}

float Shape::getGridBottomCenterY(){
    // This value is at the bottom
    return this->getGridBottomLeftY();
}

float Shape::getGridLeftCenterX(){
    // This value is all the way to the left
    return this->getGridTopLeftX();
}
float Shape::getGridLeftCenterY(){
    // This value is the center
    return this->getGridCenterY();
}

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
    ofTriangle( this->getGridBottomLeftX(), this->getGridTopLeftY(), this->topCenter.x, this->topCenter.y, this->getGridBottomRightX(), this->getGridBottomRightY() );
    
}

