// Author: Timothy Kiyui (4316886)
// File: main.cpp
#include "SwinGame.h"
#include "shape.h"
#include "rectangle.h"
#include "line.h"
#include "triangle.h"
#include "drawing.h"
#include "drawing_controller.h"
#include <cstdlib> //For rand()
 
int main()
{
    open_audio();
    open_graphics_window("Hello Again,  World!", 800, 600);
    load_default_colors();
    Drawing *d = new Drawing(); //Drawings
    // Random shapes to add to d
    Rectangle *s1 = new Rectangle();
    Triangle *s2 = new Triangle();
    Line *s3 = new Line(); //Default width and height stays 10 in Shape constructor
    // Drawing controller to control input
    DrawingController  *dc = new DrawingController();
    dc->set_controlling(d);
    // Color list for random colors
    color color_list[5] = {ColorBlue, ColorGreen, ColorRed, ColorBlack, ColorPink};
    //Assigns width and height for rectangles
    s1->set_width(rand() % 500);
    s2->set_width(rand() % 500);
    s1->set_height(rand() % 500);
    s2->set_height(rand() % 500);
    // Sets the shape color
    s1->set_color(color_list[rand() % 6]);
    s2->set_color(color_list[rand() % 6]);
    s3->set_color(color_list[rand() % 6]);
    // Sets shape random position
    s1->set_position(random_screen_point());
    s2->set_position(random_screen_point());
    s3->set_position(random_screen_point());
    // Add the shapes to d to be drawn and be controlled by dc
    d->add_shape(s1);
    d->add_shape(s2);
    d->add_shape(s3);
    do
    {
        process_events();
        // Colorful screen
        clear_screen(color_list[rand() % 6]);
        dc->handle_input();
        // Draw all objects
        d->draw();
        // Show framerate at 5, 5
        draw_framerate(5,5);
        //Refresh screen
        refresh_screen();
    } while ( ! window_close_requested() );
    // Free memory of d
    delete d;
    delete dc;
    //This is not required because d clears all the memory already.
    //delete s1;
    //delete s2;
    //delete s3;
    close_audio();
    release_all_resources();
    return 0;
}
