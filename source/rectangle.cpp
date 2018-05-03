#include "rectangle.hpp"

Rectangle::Rectangle():
    max_{ 1.0, 1.0 },
    min_{ 0.0, 0.0 } {}

Rectangle::Rectangle(Rectangle const& r):
	max_{r.max_},
	min_{r.min_} {}

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
Rectangle::~Rectangle() {}    