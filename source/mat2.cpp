#include "mat2.hpp"
#include <iostream>
#include <cmath>
#define PI 3.1415926
//Aufgabe 2.5
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
//Aufgabe 2.6
/*1.*/float Mat2::det() const{     //im struct Mat2{}; Datentypen Klassenname::Methode
    return arr[0]*arr[3]-arr[1]*arr[2];
}
/* 2.3 stehen vec2.cpp */
/*4*/Mat2 inverse(Mat2 const& m){
     Mat2 result;
     double a=m.arr[0];
     double b=m.arr[1];
     double c=m.arr[2];
     double d=m.arr[3];
     if( (a*d-b*c)==0 ){
        result.arr[0]=0;
        result.arr[1]=0;
        result.arr[2]=0;
        result.arr[3]=0;
        std::cout<<"Fehler! Inverse existiert nicht."<<std::endl;
     }
     else{
        result.arr[0]=( 1/(a*d-b*c) )*d;
        result.arr[1]=( 1/(a*d-b*c) )*(-b);
        result.arr[2]=( 1/(a*d-b*c) )*(-c);
        result.arr[3]=( 1/(a*d-b*c) )*a;
     }
     return result;
}
/*5*/Mat2 transpose (Mat2 const& m){
     Mat2 result;
     double a=m.arr[0];
     double b=m.arr[1];
     double c=m.arr[2];
     double d=m.arr[3];
     result.arr[0]=a;
     result.arr[1]=c;
     result.arr[2]=b;
     result.arr[3]=d;
     return result;
}
/*6*/Mat2 make_rotation_mat2(float phi){
     double bogen = (phi*PI)/180;
     Mat2 result;
     result.arr[0] = cos(bogen);
     result.arr[1] = -sin(bogen);
     result.arr[2] = sin(bogen);
     result.arr[3] = cos(bogen);
     return result;
}












