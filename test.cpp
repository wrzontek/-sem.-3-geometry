#include <iostream>
#include "geometry.h"

using namespace std;
int main() {
    Position p1 = Position(1,2);
    cout << p1.x() << " " << p1.y() << endl;
    Position p2 = p1.reflection();
    cout << p2.x() << " " << p2.y() << endl;
    Position p3 = Position::origin(); // git chyba
    Vector v1 = Vector(5,15);
    Vector v2 = Vector(30, 40);
    //Position p2 = Position() // nie działa i ma nie działać, git


    Rectangle r1 = Rectangle(10,20);
    Rectangle r2 = Rectangle(50, 100, p1);
    Rectangle r3 = Rectangle(5,5);
    Rectangle r4 = Rectangle(10,10,Position(5,5));

    Rectangles rr1 = Rectangles();
    cout << rr1.size() << endl;

    //Rectangles rr2 = Rectangles({r1, r2});



    Position p4 = p1 + v1;
    Position p5 = v1 + p1;
    Vector v3 = v1 + v2;
    Rectangle r5 = r1 + v1;
    Rectangle r6 = v1 + r1;
    Rectangles rr2 = rr1 + v1;
    Rectangles rr3 = v1 + rr2;

    Position p10(1, 2);
    Vector v10(p10);
    cout << v10.x() << " " << v10.y() << endl;
    cout << p10.x() << " " << p10.y() << endl;

    Vector v20(2, 3);
    Position p20(v2);

    p20 = Position(v10);
    v10 = Vector(p20);

    Rectangles recs1({r3,r4});
    cout << recs1[0].pos().x() << endl;
    Rectangles recs2 = recs1 + v20;
    cout << endl;
    cout << recs2.size() << endl;
    cout << recs1[0].pos().x() << endl;
    cout << recs2[0].pos().x() << endl;
    //Rectangles recs2 = std::move(recs1) + Vector(1, 1);
    //Rectangles recs3 = Vector(1, 1) + std::move(recs2);


    //p2 = v1;// nie działa i ma nie działać, git
    //v1 = p2;// nie działa i ma nie działać, git

    return 0;
}
