// File: shape.h

#ifndef ShapeDrawer_shape_h
#define ShapeDrawer_shape_h
#include "SwinGame.h"

// A class that contains information on
// the dimensions of any shape object
// that will later be created to inherit
// from this class
class Shape
{
    protected:
        color _color; //Color data
        point2d _position; //Point of shape
        int _width; //Shape width
        int _height; //Shape height
    public:
        // Constructor.
        Shape();
        // Desctructor
        virtual ~Shape();
        // Sets shape color.
        void set_color(color);
        // Gets shape color.
        color get_color();
        // Sets shape position.
        void set_position(point2d);
        // Gets shape current position.
        point2d get_position();
        // Sets shape width.
        void set_width(int);
        // Gets shape width.
        int get_width();
        // Sets shape height.
        void set_height(int);
        // Gets shape height.
        int get_height();
        // Checks if shape is at position.
        bool is_at(point2d pos);
        // Draws the shape.
        virtual void draw()=0;
};
#endif

