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
    
    topRight.x = topLeft.x + this->width(); // x value is the x value of topleft plus its width.
    topRight.y = topLeft.y;
    
    bottomLeft.x = topLeft.x;
    bottomLeft.y = topLeft.y + this->height() ;
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


float Shape::height() { return this->size; }

float Shape::width() { return this->size; }


RightTriangle::RightTriangle(float tlx, float tly, float sz, short an) : Shape(tlx, tly, sz), angle(an)
{}

void RightTriangle::draw ()
{

    // Change the angle of the right triangle based on input
    // Refactor this to describe the hypotenuse with an enumeration using compas direcitons
    switch (this->angle)
    {
        case (1): // Southeast Hypotenuse
            ofTriangle( this->bottomLeft.x, this->bottomLeft.y, this->topLeft.x, this->topLeft.y, this->topRight.x, this->topRight.y );
            break;
            
        case (2): // Southwest Hypotenuse
            ofTriangle( this->topLeft.x, this->topLeft.y, this->bottomRight.x, this->bottomRight.y, this->topRight.x, this->topRight.y );
            break;
            
        case (3): // Northwest Hypotenuse
            ofTriangle( this->topRight.x, this->topRight.y, this->bottomRight.x, this->bottomRight.y, this->bottomLeft.x, this->bottomLeft.y );
            break;

        case (4): //
            ofTriangle( this->bottomRight.x, this->bottomRight.y, this->bottomLeft.x, this->bottomLeft.y, this->topLeft.x, this->topLeft.y );
            break;
            
    }
}

Circle::Circle(float tlx, float tly, float sz) : Shape(tlx, tly, sz)
{}

// Draw the circle, with a width based on the input radius 'r'
void Circle::draw (float r)
{
    ofCircle (this->center, r);
}

IsoTriangle::IsoTriangle(float tlx, float tly, float sz) : Shape(tlx, tly, sz)
{}

// Draw an Isoceles (sp?) triangle
void IsoTriangle::draw()
{
    // Currently this way for testing
    ofTriangle( this->bottomLeft.x, this->topLeft.y, this->topCenter.x, this->topCenter.y, this->bottomRight.x, this->bottomRight.y );
    
}

