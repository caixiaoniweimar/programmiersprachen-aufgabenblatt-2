#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
public:
	Rectangle();					//StandardKonstruktor
	Rectangle(Rectangle const& r);  //Konstruktor
	Rectangle(Vec2 const& max, Vec2 const& min, Color const& col);//Konstruktor

    // Eigenschaft: Length+Height
    void set_Min(Vec2 const& min);
    double get_Length() const; 

    void set_Max(Vec2 const& max);
    double get_Height() const;

    // Eigenschaft: Area/Flaeche
    double area_rectangle() const;
  
    // Eigenschaft: circumference
    double circumference() const;

    // draw Methode
    void draw(Window const& win) const;

	~Rectangle();

public:
	Vec2 max_;
	Vec2 min_; 
	Color color_;   

};
#endif