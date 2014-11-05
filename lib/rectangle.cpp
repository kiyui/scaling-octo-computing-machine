//File: rectangle.cpp
#include "rectangle.h"

Rectangle::~Rectangle() {}

void Rectangle::draw()
{
    //Creates a shape to draw
    fill_rectangle(_color, _position.x, _position.y, _width, _height);
}
 
void Rectangle::make_square()
{
    // makes a square (if wanted)
    if ( _height > _width )
        _width = _height;
    else
        _height = _width;
}
