//
//  ShapeBox.h
//  
//
//  Created by Michael on 10/24/15.
//
//

#ifndef ____ShapeBox__
#define ____ShapeBox__

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
    
    float width();
    float height();
    
    virtual void draw() =0;
    
};

class RightTriangle : public Shape
{
public:
    RightTriangle(float tlx, float tly, float sz, short an);
    short angle;
    void draw();
};

class Circle : public Shape
{
public:
    Circle(float tlx, float tly, float sz);
    void draw (float r);
};

class IsoTriangle : public Shape
{
public:
    IsoTriangle(float tlx, float tly, float sz);
    void draw ();
};


#endif /* defined(____ShapeBox__) */
