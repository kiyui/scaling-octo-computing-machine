//File: drawing_controller.cpp
#include "drawing_controller.h"
 
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include <cstddef>
 
#define DEFAULT_COLOR ColorGreen
#define DEFAULT_WIDTH 200
#define DEFAULT_HEIGHT 200
 
 
void DrawingController::set_controlling(Drawing *d)
{
    _controlling = d; //Sets drawing d as the controlled drawing
}
 
Drawing * DrawingController::get_controlling()
{
    return _controlling; //Returns the controlled drawing
}
 
void DrawingController::add_new_shape(point2d pos)
{
    Shape *s;
    //Adds a new shape at the selected area
    
    switch (_adding) 
    {
        case DRAWING_ELEMENT_LINE:
            s = new Line();
            break;
        case DRAWING_ELEMENT_RECTANGLE:
            s = new Rectangle();
            break;
        case DRAWING_ELEMENT_TRIANGLE:
            s = new Triangle();
            break;
            
        default:
            return;
    }
    
    point2d p;
    p.x = pos.x - DEFAULT_WIDTH / 2.0f;
    p.y = pos.y - DEFAULT_HEIGHT / 2.0f;
    
    s->set_position(p);
    s->set_color(DEFAULT_COLOR);
    s->set_width(DEFAULT_WIDTH);
    s->set_height(DEFAULT_HEIGHT);
    
    _controlling->add_shape(s);
}
 
void DrawingController::handle_input()
{
    //Begin handling input
    if ( mouse_clicked(LEFT_BUTTON) ) //Adds a new shape if left mouse is selected
    {
        add_new_shape(mouse_position());
    }
    
    if ( mouse_clicked( RIGHT_BUTTON ) ) //Selects shape if right mouse is selected
    {
        _controlling->select_shape_at_point( mouse_position() );
    }
    
    if ( key_typed(VK_R) ) _adding = DRAWING_ELEMENT_RECTANGLE; 
    if ( key_typed(VK_L) ) _adding = DRAWING_ELEMENT_LINE;
    if ( key_typed(VK_T) ) _adding = DRAWING_ELEMENT_TRIANGLE;
    // Changes the selected object color when c is pressed
    if ( key_down(VK_C) ) change_color();
}
 
void DrawingController::change_color()
{
    //Changes selected shape by adding gue, giving the illusion of color change
    Shape *s = _controlling->get_seleted_shape();
    
    if ( s != NULL )
    {
        float hue, sat, bri;
        
        hue = hue_of(s->get_color());
        sat = saturation_of(s->get_color());
        bri = brightness_of(s->get_color());
        
        hue += 0.01f;
        if ( hue > 1 ) hue -= 1;
        
        s->set_color(hsbcolor(hue, sat, bri));
    }
}
