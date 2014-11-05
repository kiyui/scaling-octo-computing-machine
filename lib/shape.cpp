// Author: Timothy Kiyui (4316886)
// File: shape.cpp

#include "shape.h"

Shape::Shape ()
{
    _width = 10; //Initial shape width is 10
    _height = 10; //Initial shape height is 10
    _position.x = 0; //Sets initial x position to 0
    _position.y = 0; //Sets initial y position to 0
    _color = ColorRed; //Initial color is red
}

// Modifier method for _color, sets value to value
void Shape::set_color(color value)
{
    _color = value;
}

// Accessor method for _color
color Shape::get_color()
{
    return _color;
}

// Modifier method for _position, set value to value
void Shape::set_position(point2d value)
{
    _position = value;
}

// Accessor method for _position
point2d Shape::get_position()
{
    return _position;
}

// Modifier method for _width, set value to value
void Shape::set_width(int value)
{
    _width = value;
}

// Accessor method for _width
int Shape::get_width()
{
    return this->_width;
}

// Modifier method for _height, set value to value
void Shape::set_height(int value)
{
    _height = value;
}

// Accessor method for _height
int Shape::get_height()
{
    return _height;
}

bool Shape::is_at(point2d pos)
{
    // Returns boolean value by comparing pos to _position
    return pos.x >= _position.x && 
        pos.x < _position.x + _width && 
        pos.y >= _position.y && 
        pos.y < _position.y + _height;
}
