//File: drawing.h

#include "shape.h"
#include "SwinGame.h"
#include <vector>

#ifndef ShapeDrawer_drawing_h
#define ShapeDrawer_drawing_h

using namespace std;

// This class contains a collection of shapes that will be manipulated
// by a DrawingController to draw and modify contained shapes.
class Drawing
{
    private:
        std::vector<Shape *> _shapes; //Contains all added shapes
        Shape *_selected_shape; //Sets selected shape
    public:
        Drawing(); //Constructor class
        ~Drawing(); //Destructor class
        Shape *get_seleted_shape(); //Gets a selected shape
        void add_shape(Shape *to_add); //Adds a shape to shape vector
        void select_shape_at_point(point2d pt); //Selects a shape at the coordinates
        void draw(); //Draws the shape
};

#endif
