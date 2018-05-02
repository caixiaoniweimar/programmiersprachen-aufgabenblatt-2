#ifndef MAT2_HPP
#define MAT2_HPP
#include <array>  // wichtig!! Vergessen nicht!
#include "vec2.hpp"


struct Mat2{
//Aufgabe 2.5
	std::array<double, 4> arr; // wichtig Syntax std::array<Datentypen, Zahlen> name;
	Mat2();  // Standardkonstruktor
 	
 	Mat2(double a, double b, double c, double d); //User-Konstruktor
 	// 2d-Array kann auch in 1d-Array darstellen 

 	Mat2& operator*=(Mat2 const& m); // Innerhalb struct, KlassenName&; ausserhalb struct, keine Memberfunktion, KlassenName 

//Aufgabe 2.6
 	float det() const;

};   //struct name{}; sehr wichtig!!
Mat2 operator* (Mat2 const& m1, Mat2 const& m2); 

//Aufgabe 2.6
Vec2 operator* (Mat2 const& m, Vec2 const& v);
Vec2 operator* (Mat2 const& v, Vec2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose (Mat2 const& m);
Mat2 make_rotation_mat2(float phi);
 
//Vergessen nicht!! #endif
#endif 
