//File: line.cpp

#include "line.h"

Line::~Line() {}

void Line::draw()
{
    //Draws a line from Graphics.h
    draw_line(_color, _position.x, _position.y, _position.x + _width, _position.y + _height);
}
