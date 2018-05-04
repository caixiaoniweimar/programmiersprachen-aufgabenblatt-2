#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <vector>   
#define PI 3.14

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 180 * std::sin(t)};
    float y1{400 + 180 * std::cos(t)};

    float x2{400 + 180 * std::sin(2.0f*t)};
    float y2{400 + 180 * std::cos(2.0f*t)};

    float x3{400 + 180 * std::sin(t-10.f)};
    float y3{400 + 180 * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,1.0,1.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 1.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 1.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 1.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 1.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

// Aufgabe 1.11 - draw circle
    Circle(c1);
    Vec2 center1{400,400};
    c1.set_center(center1);
    c1.set_radius(140.0);
    c1.draw(win);

//  Aufgabe 1.11 - draw rectangle
    Rectangle(r1);
    Vec2 max{550,500};
    Vec2 min{250,300};
    r1.set_Max(max);
    r1.set_Min(min);
    r1.draw(win);

// Aufgabe 1.12 - draw circle red
    Circle(c2);
    Color red{1.0,0.0,0.0};
    Vec2 center2{400,400};
    c2.set_center(center2);
    c2.set_radius(200.0);
    c2.draw(win,red);

//  Aufgabe 1.12 - draw rectangle red
    Rectangle(r2);
    Vec2 max2{350,350};
    Vec2 min2{450,450};
    r2.set_Max(max2);
    r2.set_Min(min2);
    r2.draw(win,red);

// Aufgabe 1.13 - Mauszeigerposition
    Vec2 pos1{ (float)m.first, (float)m.second };
    Color blue{0.0f,0.0f,1.0f};
    std::vector<Circle> circ{ c1,c2 };
    for( Circle cir : circ){
        if(cir.is_inside(pos1)==true){
            cir.draw(win,blue);
        }
    }

    Vec2 pos{ (float)m.first, (float)m.second };
    std::vector<Rectangle> vect{ r1,r2};
    for( Rectangle objekt : vect){
        if (objekt.is_inside(pos)==true){
            objekt.draw(win,blue);
        }
    }

// Aufgabe 1.14 - Analoguhr
    Circle(c3);
    Color color{0.0,1.0,1.0};
    Vec2 center3{400,400};
    c3.set_center(center3);
    c3.set_radius(380.0);
    c3.draw(win,color);

    int sekunden=0;
    int minuten=0;
    int stunden=0;

    sekunden =(int)t%60;
    minuten =(int)(t/60)%60;
    stunden =(int)(t/3600)%24;

    std::string text1 = "Die vergangenen Sekunden: " +std::to_string(t);
    win.draw_text(400, 700, 20.0f, text1);

    std::string text2 = "Zeit: " +std::to_string(stunden)+" Stunden "+std::to_string(minuten)
                        +" Minuten "+std::to_string(sekunden)+" Sekunden";
    win.draw_text(40, 40, 20.0f, text2);

    // Stundenzeiger
    float Radians = (double)stunden + (double)minuten/60.0 + (double)sekunden/3600.0 ;
          Radians *= (2*PI/12.0);
    win.draw_line(400, 400, 400 + (int)((double)(400/3)*std::sin(Radians)), 
                  400 - (int)((double)(400/3)*std::cos(Radians)), 0.0, 1.0, 0.0);
    // Minutenzeiger
    float Radians1 = (double)minuten + (double)sekunden/60.0 ;
          Radians1 *= (2*PI/60.0);
    win.draw_line(400, 400, 400 + (int)((double)(400*1/2)*std::sin(Radians1)), 
                  400 - (int)((double)(400*1/2)*std::cos(Radians1)), 1.0, 1.0, 0.0);
    // Sekundenzeiger
    float Radians2 = (double)sekunden;
          Radians2 *= (2*PI/60.0);
    win.draw_line(400, 400, 400 + (int)((double)(400*7/8)*std::sin(Radians2)), 
                  400 - (int)((double)(400*7/8)*std::cos(Radians2)), 1.0, 1.0, 1.0);

    win.update();
}

  return 0;
}
