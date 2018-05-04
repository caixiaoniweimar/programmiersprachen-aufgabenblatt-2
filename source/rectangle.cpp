#include "rectangle.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include <iostream>

Rectangle::Rectangle():
    max_{ 1.0, 1.0 },
    min_{ 0.0, 0.0 },
    color_{ 0.0, 0.0, 0.0} {}

Rectangle::Rectangle(Rectangle const& r):
	max_{r.max_},
	min_{r.min_},
	color_{r.color_} {}

Rectangle::Rectangle(Vec2 const& max, Vec2 const& min, Color const& col):
	max_{max},
	min_{min},
	color_{col} {}

// Eigenschaft: Length+Height
    void Rectangle::set_Min(Vec2 const& min){
    	min_.x=min.x;
    	min_.y=min.y;
    }
    double Rectangle::get_Length() const{
    	return max_.x - min_.x;
    }
    void Rectangle::set_Max(Vec2 const& max){
    	max_.x=max.x;
    	max_.y=max.y;
    }
    double Rectangle::get_Height() const{
    	return max_.y - min_.y;
    }
// Eigenschaft: Area/Flaeche
    double Rectangle::area_rectangle() const{
    	return (max_.x - min_.x)*(max_.y - min_.y);
    }
// Eigenschaft: circumference
    double Rectangle::circumference() const{
    	return 2*(max_.x - min_.x)+2*(max_.y - min_.y);
    }

// Aufgabe 2.11 draw-Methode    
    void Rectangle::draw(Window const& win) const{
        win.draw_line(min_.x, min_.y, max_.x, min_.y, 1.0, 0.0, 1.0);
        win.draw_line(min_.x, min_.y, min_.x, max_.y, 1.0, 0.0, 1.0);
        win.draw_line(min_.x, max_.y, max_.x, max_.y, 1.0, 0.0, 1.0);
        win.draw_line(max_.x, max_.y, max_.x, min_.y, 1.0, 0.0, 1.0);
    }

// Aufgabe 2.12 draw-Methode    
    void Rectangle::draw(Window const& win, Color const& col) const{
        win.draw_line(min_.x, min_.y, max_.x, min_.y, col.r, col.h, col.g);
        win.draw_line(min_.x, min_.y, min_.x, max_.y, col.r, col.h, col.g);
        win.draw_line(min_.x, max_.y, max_.x, max_.y, col.r, col.h, col.g);
        win.draw_line(max_.x, max_.y, max_.x, min_.y, col.r, col.h, col.g);
    }

// Aufgabe 1.13 Methode is_inside
    float Rectangle::vergleichen(Vec2 const& p1, Vec2 const& p2, Vec2 const& p)const{
        return (p2.x -p1.x)*(p.y-p1.y)-(p.x-p1.x)*(p2.y-p1.y);
    }
    bool Rectangle::is_inside(Vec2 const& vec) const{
        bool result=false;
        Vec2 point_oben_min { min_.x, max_.y};
        Vec2 point_unter_max { max_.x, min_.y};
        if( vergleichen(point_oben_min, min_, vec) * 
            vergleichen(point_unter_max, max_, vec) >= 0 &&
            vergleichen(min_, point_unter_max, vec) *
            vergleichen(max_, point_oben_min, vec)  >=0 )
        {
            result=true;
        }
        return result;
    }

Rectangle::~Rectangle() {}  





