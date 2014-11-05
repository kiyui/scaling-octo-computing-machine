//File drawing_controller.h
#ifndef ShapeDrawer_drawing_controller_h
#define ShapeDrawer_drawing_controller_h
 
#include "drawing.h"
 
typedef enum drawing_element { DRAWING_ELEMENT_LINE, DRAWING_ELEMENT_RECTANGLE, DRAWING_ELEMENT_TRIANGLE }  drawing_element;

// This class controls added shapes by being
// able to manipulate them. It is a collaborating class.
class DrawingController
{
private:
    Drawing         *_controlling; // Current controlled drawing
    drawing_element  _adding; //For selecting types 
 
    void add_new_shape(point2d pos); //Adds a new shape to collection
    void change_color(); //Changes selected shape color
 
public:
    Drawing *get_controlling(); //Gets the current controlled shape
    void set_controlling(Drawing *d); //Sets the controlled drawing
    
    void handle_input(); //Begin handling input
};
 
#endif
