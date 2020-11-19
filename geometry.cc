#include "geometry.h"

#include <iostream>
#include <cassert>

Position::Position(int x, int y): x_coord(x), y_coord(y) {}

bool Position::operator==(const Position &that) const {
    return x() == that.x() and y() == that.y();
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

Position& Position::operator+=(Vector v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}


Vector::Vector(int x, int y): x_coord(x), y_coord(y) {}

int Vector::x() const {
    return x_coord;
}

int Vector::y() const {
    return y_coord;
}

bool Vector::operator==(const Vector &that) const {
    return x() == that.x() and y() == that.y();
}

Vector &Vector::operator+=(Vector v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}


Rectangle::Rectangle(int w, int h, Position p): width_(w), height_(h), pos_(p)  {
    assert(w > 0 and h > 0);
}

Rectangle::Rectangle(int w, int h): width_(w), height_(h), pos_(Position(0,0)) {
    assert(w > 0 and h > 0);
}

bool Rectangle::operator==(const Rectangle &that) const {
    return width() == that.width() and height() == that.height()
            and pos() == that.pos();
}

int Rectangle::width() const {
    return width_;
}

int Rectangle::height() const {
    return height_;
}

Position Rectangle::pos() const {
    return pos_;
}

Rectangle &Rectangle::operator+=(Vector v) {
    pos_ += v;
    return *this;
}

int Rectangle::area() const {
    return width() * height();
}

Rectangles::Rectangles() {

}

Rectangle &Rectangles::operator[](size_t index) {
    //TODO
}

size_t Rectangles::size() const {
    //TODO (pewnie rozmiar tablicy/wektora)
}

bool Rectangles::operator==(const Rectangles &that) const {
    //TODO (porównanie liniowe tablic)
}

Rectangles &Rectangles::operator+=(Vector v) {
    // TODO (dodajemy v do każdego prostokąta)
    return *this;
}



