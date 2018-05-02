#include "vec2.hpp"
#include <iostream>
//Aufgabe 2.2
Vec2::Vec2():	 //StandardKonstruktor!!! Vec2::Vec2(): x{},y{} {}
	x{0.0f},
	y{0.0f} {}


Vec2::Vec2(float x1, float y1):  //NormalKonstruktor
	x{x1},
	y{y1}  {}
//Aufgabe 2.3
Vec2& Vec2::operator+= (Vec2 const& v){ //Memberfunktionen!! Vec2& Vec2::
    x += v.x;                           //return *this
    y += v.y;
    return *this;
}
Vec2& Vec2::operator-= (Vec2 const& v){
	x -= v.x;
	y -= v.y;       
	return *this;
}
Vec2& Vec2::operator*= (float s){
	x *= s;
	y *= s;
	return *this;
}
Vec2& Vec2::operator/= (float s){
	if(s==0){
		x=0.0f;
		y=0.0f;
		std::cout<<"Fehler!"<<std::endl;
	}
	else{
		x/=s;
		y/=s;
	}
	return *this;
}
//Aufgabe 2.4
Vec2 operator+(Vec2 const& u, Vec2 const& v){
	Vec2 result(u);   // first erzeuge neue Objekt und copy u!!;
	result+=v;
	return result;
}
Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 result(u);
	result-=v;
	return result;
}
Vec2 operator*(Vec2 const& v, float s){
	Vec2 result(v);
	result*=s;
	return result;
}
Vec2 operator/(Vec2 const& v, float s){
	Vec2 result(v);
	if(s==0){
        result.x=0;             // muss x,y getrennt definiert
        result.y=0;
		std::cout<<"Fehler!"<<std::endl;
	}
	else{
		result/=s;
	}
	return result;
}
Vec2 operator*(float s, Vec2 const& v){
    return v*s;                // einfach v*s, operator keine Funktion, * ist schon definiert
}










