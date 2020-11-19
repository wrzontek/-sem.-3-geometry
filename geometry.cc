#include "geometry.h"

#include <iostream>

Position::Position(int x, int y): x_coord(x), y_coord(y) {}

bool Position::operator==(const Position &that) {
    return x_coord == that.x_coord and y_coord == that.y_coord;
}

int Position::x() const {
    return x_coord;
}

int Position::y() const {
    return y_coord;
}

Position Position::reflection() const {
    return Position(y_coord, x_coord);
}

const Position Position::origin() {
    return Position(0,0);
}

template<class T>
class Vector {

};

template<class T>
class Rectangle {

};

template<class T>
class Rectangles {

};