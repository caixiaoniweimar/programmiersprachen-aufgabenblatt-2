#include "circle.hpp"
#include <iostream>
#include "window.hpp"
#include <cmath>
#include <vector>
#define PI 3.1415926 // kein "="

Circle::Circle():    //Konstruktor Circle::Circle klassenName::KonstruktorName
	radius_{1.0},
	center_{0.0, 0.0},
	color_{0.0,0.0,0.0} {}

Circle::Circle(Circle const& c):
	radius_{c.radius_},
	center_{c.center_},
	color_ {c.color_}   {}

Circle::Circle(Vec2 const& cen, double rad, Color const& col):
	radius_{rad},
	center_{cen},
	color_{col}  {}
	
// Eigenschaft: Center
	Vec2 Circle::get_center() const{  //方法前面Circle:: 类/Struct名
		return center_;
	}
	void Circle::set_center(Vec2 const& center){
		center_ = center;  // benutzt "=" sondern nicht "{}"
	}

// Eigenschaft: Radius
	double Circle::get_radius() const{
		return radius_;
	}
	void   Circle::set_radius(double radius){
		radius_ = radius;
	}

// Eigenschaft: Diamater
	double Circle::diameter() const {
		return radius_ *2 ;
	}

// Eigenschaft: Area/Flaeche
	double Circle::area() const {
		return  PI * radius_ * radius_ ;
	}
// Eigenschaft: circumference
	double Circle::circumference() const {
		return  PI*2*radius_;
	}    

// Aufgabe 2.11 draw-Methode	
void Circle::draw(Window const& win) const{

    for(int a=1000;a>0;a=a-0.1){
      double x5{center_.x + radius_ * std::sin(win.get_time()-a)};
      double y5{center_.y + radius_ * std::cos(win.get_time()-a)};
       win.draw_point(x5, y5, 1.0f, 1.0f, 0.0f);
    }
}
// Aufgabe 2.12 draw-Methode
void Circle::draw(Window const& win, Color const& col) const{
	
	for(int a=2000;a>0;a--){
      double x5{center_.x + radius_ * std::sin(win.get_time()-a)};
      double y5{center_.y + radius_ * std::cos(win.get_time()-a)};
      win.draw_point(x5, y5, col.r, col.h, col.g);
    }
}

// Aufgabe 1.13 Methode is_inside
	bool Circle::is_inside(Vec2 const& vec) const{
	   bool result=false;
	   double distance =( vec.x - center_.x )*( vec.x - center_.x )+
	   					( vec.y - center_.y )*( vec.y - center_.y );
	   if(distance <= radius_*radius_){
	   		result=true;
	   }

	   return result;
	}

Circle::~Circle(){ }

















