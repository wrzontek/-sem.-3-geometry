#include <iostream>
#include "geometry.h"

using namespace std;
int main() {
    Position p1 = Position(1,2);
    cout << p1.x() << " " << p1.y() << endl;
    Position p2 = p1.reflection();
    cout << p2.x() << " " << p2.y() << endl;
    const Position p3 = Position::origin();
    p3 = p1.reflection();
    //Position p2 = Position() // nie działa i ma nie działać, git
    return 0;
}