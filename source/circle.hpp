#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <vector>

class Circle{
	public:
		Circle();   //StandardKonstruktor
		Circle(Circle const& c);  //Konstruktor
		Circle(Vec2 const& cen, double rad, Color const& col); //Konstruktor
		
		// Eigenschaft: Center
		Vec2 get_center() const;
		void set_center(Vec2 const& center);

	    // Eigenschaft: Radius
		double get_radius() const;
		void   set_radius(double radius);

		// Eigenschaft: Diamater
		double diameter() const;

		// Eigenschaft: Area/Flaeche
		double area() const;

		// Eigenschaft: circumference
		double circumference() const;

		// draw Methode - Aufgabe 2.11 
		void draw(Window const& win) const;

		// draw Methode - Aufgabe 2.12
		void draw(Window const& win, Color const& col) const;

		// Aufgabe 1.13 Methode is_inside
		bool is_inside(Vec2 const& vec) const;

		~Circle();
		Color color_;

	private:
		double radius_;   
		Vec2 center_;
};
//immer vergessen #endif Error!
#endif 