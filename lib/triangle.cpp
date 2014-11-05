//File: triangle.cpp
#include "triangle.h"

Triangle::~Triangle() {}

void Triangle::draw()
{
    fill_triangle(_color, _position.x, _position.y, _width, _height, _position.x + _width, _position.y + _height);
}
