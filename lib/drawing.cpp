//File: drawing.cpp

#include "drawing.h"
#include "rectangle.h"
#include "line.h"
#include "triangle.h"
#include <cstddef> 

Drawing::Drawing()
{
    _selected_shape = NULL; //Sets selected shape as empty value
}

Drawing::~Drawing()
{
    //Iterates and deletes all added shapes
    for (std::vector<Shape *>::size_type i = 0; i != _shapes.size(); i++) 
    {
        Shape *s = _shapes[i];
        delete s;
    }
}

void Drawing::add_shape(Shape *to_add)
{
    //Adds new shape
    _shapes.push_back(to_add);
}

void Drawing::select_shape_at_point(point2d pt)
{
    _selected_shape = NULL;
    //Selects the shape pointed on by checking each shape one by one
    for (std::vector<Shape *>::size_type i = 0; i != _shapes.size(); i++) 
    {
        Shape *s = _shapes[i];
        if (s->is_at(pt)) 
        {
            _selected_shape = s;
        }
    }
}

Shape *Drawing::get_seleted_shape()
{
    //Returns the selected shape
    return _selected_shape;
}

void Drawing::draw()
{
    //Iterates and draws all shapes
    for (std::vector<Shape *>::size_type i = 0; i != _shapes.size(); i++) 
    {
        Shape *s = _shapes[i];
        s->draw();
    }
}
