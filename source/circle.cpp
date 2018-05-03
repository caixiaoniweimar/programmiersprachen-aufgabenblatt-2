#include "circle.hpp"
#define PI 3.1415926 // kein "="
Circle::Circle():    //Konstruktor Circle::Circle klassenName::KonstruktorName
	radius_{1.0},
	center_{0.0, 0.0} {}

Circle::Circle(Circle const& c):
	radius_{c.radius_},
	center_{c.center_} {}
	
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

Circle::~Circle(){ }