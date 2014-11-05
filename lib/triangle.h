//File triangle.h
#ifndef ShapeDrawer_triangle_h
#define ShapeDrawer_triangle_h
 
#include "shape.h"

// Triangle class, overrides draw
// in order to create a rectangle
class Triangle: public Shape
{
private:
    
public:
    ~Triangle();
    void draw(); //Required by Shape
};
 
#endif
