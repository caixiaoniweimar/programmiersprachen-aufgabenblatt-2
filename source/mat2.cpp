#include "mat2.hpp"
//Aufgabe 2.6
Mat2::Mat2():			// Mat2::Mat2():
    arr{ { 1.0, 0.0, 0.0, 1.0 } } {} // arr{ {a,b,c,d} } {}

Mat2::Mat2(double a, double b, double c, double d):
	arr{ { a, b, c, d} } {}

Mat2& Mat2::operator*=(Mat2 const& m){ // m: jede Objekt hat eigene Array
//    m:Objekt     Array: Zustand von Objekt

	double a = arr[0]*m.arr[0]+arr[1]*m.arr[2];
	double b = arr[0]*m.arr[1]+arr[1]*m.arr[3];
	double c = arr[2]*m.arr[0]+arr[3]*m.arr[2];
	double d = arr[2]*m.arr[1]+arr[3]*m.arr[3];
    arr[0]= a;    //temporäre Variablen definieren !! wichtig!!
    arr[1]= b;
    arr[2]= c;
    arr[3]= d;
    return *this;

}

Mat2 operator* (Mat2 const& m1, Mat2 const& m2){
	Mat2 result(m1);
	double a = result.arr[0]*m2.arr[0] + result.arr[1]*m2.arr[2];
	double b = result.arr[0]*m2.arr[1] + result.arr[1]*m2.arr[3];
	double c = result.arr[2]*m2.arr[0] + result.arr[3]*m2.arr[2];
	double d = result.arr[2]*m2.arr[1] + result.arr[3]*m2.arr[3];
	result.arr[0]=a;
	result.arr[1]=b;
	result.arr[2]=c;
	result.arr[3]=d;
	return result;
}