#define CATCH_CONFIG_RUNNER 
#include <catch.hpp>
#include <iostream>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
// Test-Aufgabe 2.2
TEST_CASE ("test_standardkonstruktor","[standardkonstruktor]"){ //Standardkonstruktor
    Vec2 v1;
    REQUIRE(v1.x==0.0f);
    REQUIRE(v1.y==0.0f);
}
TEST_CASE ("test_konstruktor","[konstruktor]"){ //Konstruktor
    Vec2 v2{3.0f,4.0f};
    REQUIRE(v2.x==3.0f);
    REQUIRE(v2.y==4.0f);
}
// Test-Aufgabe 2.3
TEST_CASE ("test_operator+=","[operator+=]"){ // operator+=
    Vec2 v1;
    Vec2 v2{2.0f,3.0f};
    Vec2 v3{3.0f,4.0f};

    v1 += v2;     
    REQUIRE( v1.x == 2.0f );      
    REQUIRE( v1.y == 3.0f );
    v1 += v3;
    REQUIRE( v1.x == 5.0f );
    REQUIRE( v1.y == 7.0f );
    v2 += v3;
    REQUIRE( v2.x == 5.0f );
    REQUIRE( v2.y == 7.0f );
}
TEST_CASE ("test_operator-=","[operator-=]"){ // operator-=
    Vec2 v1;
    Vec2 v2{2.0f,3.0f};
    Vec2 v3{3.0f,4.0f};
    Vec2 v4{5.0f,4.0f};
    v1 -= v2;
    REQUIRE( v1.x == -2.0f );
    REQUIRE( v1.y == -3.0f );
    v1 -= v3;
    REQUIRE( v1.x == -5.0f );
    REQUIRE( v1.y == -7.0f );
    v2 -= v3;
    REQUIRE( v2.x == -1.0f );
    REQUIRE( v2.y == -1.0f );
    v4 -= v3;
    REQUIRE( v4.x == 2.0f );
    REQUIRE( v4.y == 0.0f );
}
TEST_CASE ("test_operator*=","[operator*=]"){  // operator*=
    Vec2 v1;
    Vec2 v2{2.0f,3.0f};
    Vec2 v3{3.0f,4.0f};
    v1 *= 0;
    REQUIRE( v1.x == 0.0f );
    REQUIRE( v1.y == 0.0f );
    v2 *= 1;
    REQUIRE( v2.x == 2.0f );
    REQUIRE( v2.y == 3.0f );
    v3 *= 2;
    REQUIRE( v3.x == 6.0f );
    REQUIRE( v3.y == 8.0f );
}
TEST_CASE ("test_operator/=","[operator/=]"){  // operator/=
    Vec2 v1;
    Vec2 v2{2.0f,3.0f};
    Vec2 v3{3.0f,6.0f};
    v1 /= 0;
    REQUIRE( v1.x == 0.0f );
    REQUIRE( v1.y == 0.0f );
    v2 /= 1;
    REQUIRE( v2.x == 2.0f );
    REQUIRE( v2.y == 3.0f );
    v3 /= 3;
    REQUIRE( v3.x == 1.0f );
    REQUIRE( v3.y == 2.0f );
}
// Test-Aufgabe 2.4
TEST_CASE ("test_operator+","[operator+]"){ 
    Vec2 v1;
    Vec2 v2{2.0f,3.0f};
    Vec2 v3{3.0f,6.0f};

    Vec2 result = v1 + v2;
    REQUIRE( result.x == 2.0f );
    REQUIRE( result.y == 3.0f );
    REQUIRE( (v2+v3).x == 5.0f );
    REQUIRE( (v2+v3).y == 9.0f );
}
TEST_CASE ("test_operator-","[operator-]"){ 
    Vec2 v1;
    Vec2 v2{2.0f,5.0f};
    Vec2 v3{3.0f,9.0f};
    REQUIRE( (v1-v2).x == -2.0f );
    REQUIRE( (v2-v1).y == 5.0f );
    REQUIRE( (v2-v3).x == -1.0f );
    REQUIRE( (v3-v2).y == 4.0f );
}
TEST_CASE ("test_operator*v,s","[operator*v,s]"){ 
    Vec2 v1;
    Vec2 v2{2.0f,5.0f};
    Vec2 v3{3.0f,9.0f};
    REQUIRE( (v1*0).x == 0.0f );
    REQUIRE( (v2*1).y == 5.0f );
    REQUIRE( (v2*2).x == 4.0f );
    REQUIRE( (v3*2).x == 6.0f );
    REQUIRE( (v3*2).y == 18.0f );
}
TEST_CASE ("test_operator/","[operator/]"){ 
    Vec2 v1;
    Vec2 v2{2.0f,6.0f};
    Vec2 v3{3.0f,9.0f};
    REQUIRE( (v1/0).x == 0.0f );
    REQUIRE( (v2/1).y == 6.0f );
    REQUIRE( (v2/2).x == 1.0f );
    REQUIRE( (v2/2).y == 3.0f );
    REQUIRE( (v3/3).x == 1.0f );
    REQUIRE( (v3/2).y == 4.5f );
}
TEST_CASE ("test_operator*s,v","[operator*s,v]"){ 
    Vec2 v1;
    Vec2 v2{2.0f,5.0f};
    Vec2 v3{3.0f,9.0f};
    REQUIRE( (0*v1).x == 0.0f );
    REQUIRE( (1*v2).y == 5.0f );
    REQUIRE( (2*v2).x == 4.0f );
    REQUIRE( (2*v3).x == 6.0f );
    REQUIRE( (2*v3).y == 18.0f );
}
// Test-Aufgabe 2.5
TEST_CASE ("test_einheitmatrix","[einheitmatrix]"){ //Einheitmatrix
    REQUIRE(Mat2().arr[0]==1);
    REQUIRE(Mat2().arr[1]==0);
    REQUIRE(Mat2().arr[2]==0);
    REQUIRE(Mat2().arr[3]==1);
}
TEST_CASE ("test_matrix*","[matrix*]"){
    Mat2 m1{1,2,3,4};
    Mat2 m2{1,1,1,1};
    Mat2 m3{0,0,0,0};
    m1 *= m2;
    m3 *= m2;
    REQUIRE(m1.arr[0]==3);
    REQUIRE(m1.arr[1]==3);
    REQUIRE(m1.arr[2]==7);
    REQUIRE(m1.arr[3]==7);
    REQUIRE(m3.arr[0]==0);
    REQUIRE(m3.arr[1]==0);
}
TEST_CASE ("test_matrix2","[matrix2]"){
    Mat2 m1{1,2,3,4};
    Mat2 m2{1,1,1,1};
    Mat2 m3=m1 * m2;
    REQUIRE(m3.arr[0]==3);
    REQUIRE(m3.arr[1]==3);
    REQUIRE(m3.arr[2]==7);
    REQUIRE(m3.arr[3]==7);
}
// Test-Aufgabe 2.6
TEST_CASE ("test_det","[det]"){
    Mat2 m1{1,2,3,4};
    Mat2 m2{1,1,1,1};
    Mat2 m3{12,-2,1,1};
    float m1_det = m1.det();
    float m2_det = m2.det();
    float m3_det = m3.det();
    REQUIRE( m1_det == -2);
    REQUIRE( m2_det == 0 );
    REQUIRE( m3_det == 14 );

}
TEST_CASE("test_vektor*Matrix","[vektor*Matrix]"){
    Mat2 m1{80,90,60,85};
    Vec2 v1{0.4, 0.6};
    Vec2 v1_m1 = v1*m1;
    Vec2 m1_v1 = m1*v1;
    REQUIRE(v1_m1.x==86);
    REQUIRE(v1_m1.y==75);
    REQUIRE(m1_v1.x==86);
    REQUIRE(m1_v1.y==75);
}
TEST_CASE ("test_inverse","[inverse]"){
    Mat2 m1{1,2,3,4};
    Mat2 m2{1,1,1,1};
    Mat2 m1_inver = inverse(m1);
    Mat2 m2_inver = inverse(m2);
    REQUIRE(m1_inver.arr[0]==-2);
    REQUIRE(m1_inver.arr[1]==1);
    REQUIRE(m1_inver.arr[2]==1.5);
    REQUIRE(m1_inver.arr[3]==-0.5);
    REQUIRE(m2_inver.arr[0]==0);
}
TEST_CASE ("test_transpose","[transpose]"){
    Mat2 m1{1,2,3,4};
    Mat2 m2{1,1,1,1};
    Mat2 m1_trans = transpose(m1);
    REQUIRE(m1_trans.arr[0]==1);
    REQUIRE(m1_trans.arr[1]==3);
    REQUIRE(m1_trans.arr[2]==2);
    REQUIRE(m1_trans.arr[3]==4);
}
TEST_CASE ("test_rotationmatrix","[rotationmatrix]"){
    Mat2 m1 = make_rotation_mat2(30);
    Mat2 m2 = make_rotation_mat2(60);
    REQUIRE(m1.arr[0]== Approx(0.8660254).epsilon(0.01));
    REQUIRE(m1.arr[1]== Approx(-0.50).epsilon(0.01));
    REQUIRE(m1.arr[2]== Approx(0.50).epsilon(0.01));
    REQUIRE(m1.arr[3]== Approx(0.8660254).epsilon(0.01));

    REQUIRE(m2.arr[0]== Approx(0.50).epsilon(0.01));
    REQUIRE(m2.arr[1]== Approx(-0.8660254).epsilon(0.01));
    REQUIRE(m2.arr[2]== Approx(0.8660254).epsilon(0.01));
    REQUIRE(m2.arr[3]== Approx(0.50).epsilon(0.01));
}
//Test-Aufgabe 2.8
TEST_CASE ("test_circle","[circle]"){
    Circle c1;
    Circle(c2);
    Vec2 center2{1.0,1.0};    //Funktion/Konstruktor: Objekt erzeugen 
    Vec2 center1{0.0,0.0};
    c2.set_center(center2);  //Methode name(Uebergabeparamter)
    c2.set_radius(3.0);
    REQUIRE(c1.get_radius()==1.0);
    REQUIRE(c1.get_center().y==0.0);
    REQUIRE(c2.get_radius()==3.0);
    REQUIRE(c2.get_center().x==1.0);
    REQUIRE(c2.diameter()==6.0);
    REQUIRE(c2.area()==Approx(28.2743).epsilon(0.01));
    REQUIRE(c2.circumference()==Approx(18.85).epsilon(0.01));
    REQUIRE(c1.circumference()==Approx(6.28).epsilon(0.01));
}
TEST_CASE ("test_rectangle","[rectangle]") {
    Rectangle r1;
    Rectangle r2(r1);
    Vec2 max2{6.5,4.9};
    Vec2 min2{3.7,0.4};
    r2.set_Max(max2);
    r2.set_Min(min2);
    REQUIRE(r1.get_Length()==1.0);
    REQUIRE(r1.get_Height()==1.0);
    REQUIRE(r2.get_Length()==Approx(2.8).epsilon(0.01));
    REQUIRE(r2.get_Height()==Approx(4.5).epsilon(0.01));
    REQUIRE(r2.circumference()==Approx(14.6).epsilon(0.01));
    REQUIRE(r1.circumference()==4.0);     
}
//Test-Aufgabe 2.9

























int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
