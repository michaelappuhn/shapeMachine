//
//  ShapeBox.h
//  
//
//  Created by Michael on 10/24/15.
//
//

#ifndef ____Shape__
#define ____Shape__

#include <stdio.h>
#include <string>
#include <ofVec2f.h>

using namespace std;


class Shape
{
private:
    float size;


public:
    ofVec2f topLeft, topRight, bottomLeft, bottomRight, center, topCenter, bottomCenter, leftCenter, rightCenter;
    
    
    // Here I could make a secondary constructor if the size is a non-square, this constructor
    // assumes it's a square otherwise
    
    Shape();
    Shape(float tlx, float tly, float sz);
    
    float getWidth();
    float getHeight();
    
    
    float getGridTopLeftX();
    float getGridTopLeftY();

    float getGridTopRightX();
    float getGridTopRightY();
    
    float getGridBottomLeftX();
    float getGridBottomLeftY();
    
    float getGridBottomRightX();
    float getGridBottomRightY();

    float getGridCenterX();
    float getGridCenterY();
    
    float getGridTopCenterX();
    float getGridTopCenterY();
    
    float getGridBottomCenterX();
    float getGridBottomCenterY();
    
    float getGridLeftCenterX();
    float getGridLeftCenterY();

    float getGridRightCenterX();
    float getGridRightCenterY();
    
    virtual void draw() = 0;
    
};

// A Right Triangle
class RightTriangle : public Shape
{
public:
    RightTriangle(float tlx, float tly, float sz, short an);
    short angle;
    void draw();
};

// A Circle!
class Circle : public Shape
{
public:
    Circle(float tlx, float tly, float sz);
    void draw (float r);
};

// An Isoceles Triangle
class IsoTriangle : public Shape
{
public:
    IsoTriangle(float tlx, float tly, float sz);
    void draw ();
};


#endif /* defined(____Shape__) */
