//File: line.h

#ifndef Line_h
#define Line_h
 
#include "shape.h"
 
//Similar to Rectangle, just overrides draw
//in order to create a different shape on
//the screen
class Line : public Shape
{
private:
    
public:
    ~Line();
    void draw(); //Required by Shape
};
 
#endif
