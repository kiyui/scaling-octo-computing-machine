//File: rectangle.h
#ifndef ShapeDrawer_rectangle_h
#define ShapeDrawer_rectangle_h
 
#include "shape.h"

// Rectangle class, overrides draw
// in order to create a rectangle
class Rectangle: public Shape
{
private:
    
public:
    ~Rectangle();
    void make_square(); //Makes a square
    void draw(); //Required by Shape
};
 
#endif
