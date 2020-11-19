#include <iostream>
#include "geometry.h"

using namespace std;
int main() {
    Position p1 = Position(1,2);
    cout << p1.x() << " " << p1.y() << endl;
    Position p2 = p1.reflection();
    cout << p2.x() << " " << p2.y() << endl;
    Position p3 = Position::origin(); // powinien dawać const
    p3 = p1.reflection(); // źle że działa

    Vector v1 = Vector(5,15);
    Vector v2 = Vector(30, 40);
    //Position p2 = Position() // nie działa i ma nie działać, git

    Rectangle r1 = Rectangle(10,20);
    Rectangle r2 = Rectangle(50, 100, p1);
    Rectangle r3 = Rectangle(5,5);
    Rectangle r4 = Rectangle(10,10,Position(5,5));

    Rectangles rr1 = Rectangles();
    Rectangles rr2 = Rectangles({r1, r2});

    //TODO to wszystko ma działać a nie działa, patrz przykład z moodle
    Position p4 = p1 + v1;
    Position p5 = v1 + p1;
    Vector v3 = v1 + v2;
    Rectangle r3 = r1 + v1;
    Rectangle r4 = v1 + r1;
    Rectangles rr2 = rr1 + v1;
    Rectangles rr3 = v1 + rr2;

    Position p10(1, 2);
    Vector v10(p10);

    Vector v20(2, 3);
    Position p20(v2);

    p20 = Position(v10);
    v10 = Vector(p20);

    Rectangles recs1({r3,r4});
    Rectangles recs2 = std::move(recs1) + Vector(1, 1);
    Rectangles recs3 = Vector(1, 1) + std::move(recs2);
    //TODO to wszystko ma działać a nie działa, patrz przykład z moodle

    p2 = v1;// nie działa i ma nie działać, git
    v1 = p2;// nie działa i ma nie działać, git




    return 0;
}
