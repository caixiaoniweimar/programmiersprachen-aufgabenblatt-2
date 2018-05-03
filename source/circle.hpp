#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

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

		~Circle();


	private:
		double radius_;   
		Vec2 center_;
		Color color_;
};
//immer vergessen #endif Error!
#endif 