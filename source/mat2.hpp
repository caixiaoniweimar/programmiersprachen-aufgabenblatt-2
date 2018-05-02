#ifndef MAT2_HPP
#define MAT2_HPP
#include <array>  // wichtig!! Vergessen nicht!

struct Mat2{
	std::array<double, 4> arr; // wichtig Syntax std::array<Datentypen, Zahlen> name;
//Aufgabe 2.6
	Mat2();  // Standardkonstruktor
 	
 	Mat2(double a, double b, double c, double d); //User-Konstruktor
 	// 2d-Array kann auch in 1d-Array darstellen 

 	Mat2& operator*=(Mat2 const& m); // Innerhalb struct, KlassenName&; ausserhalb struct, keine Memberfunktion, KlassenName 

};   //struct name{}; sehr wichtig!!
Mat2 operator* (Mat2 const& m1, Mat2 const& m2); 
	
//Vergessen nicht!! #endif
#endif 
