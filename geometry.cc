#include "geometry.h"
#include <cassert>

Position::Position(int x, int y): x_coord(x), y_coord(y) {}

Position::Position(const Vector& v): x_coord(v.x()), y_coord(v.y()) {}

int Position::x() const {
    return x_coord;
}

int Position::y() const {
    return y_coord;
}

Position Position::reflection() const {
    return Position(y_coord, x_coord);
}

const Position& Position::origin() {
    const static Position origin = Position(0,0);
    return origin;
}

bool Position::operator==(const Position& that) const {
    return x() == that.x() and y() == that.y();
}

Position& Position::operator+=(const Vector& v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}

Position operator+(const Position& p, const Vector& v) {
    return Position(p) += v;
}
Position operator+(const Vector& v, const Position& p) {
    return Position(p) += v;
}


Vector::Vector(int x, int y): x_coord(x), y_coord(y) {}

Vector::Vector(const Position& p): x_coord(p.x()), y_coord(p.y()) {}

int Vector::x() const {
    return x_coord;
}

int Vector::y() const {
    return y_coord;
}

Vector Vector::reflection() const {
    return Vector(y_coord, x_coord);
}

bool Vector::operator==(const Vector& that) const {
    return x() == that.x() and y() == that.y();
}

Vector& Vector::operator+=(const Vector& v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}

Vector operator+(const Vector& v1, const Vector& v2){
    return Vector(v1) += v2;
}


Rectangle::Rectangle(int w, int h, Position p): width_(w), height_(h), pos_(p)  {
    assert(w > 0 and h > 0);
}

Rectangle::Rectangle(int w, int h): width_(w), height_(h), pos_(Position(0,0)) {
    assert(w > 0 and h > 0);
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

int Rectangle::area() const {
    return width() * height();
}

bool Rectangle::operator==(const Rectangle &that) const {
    return width() == that.width() and height() == that.height()
           and pos() == that.pos();
}

Rectangle& Rectangle::operator+=(const Vector& v) {
    pos_ += v;
    return *this;
}

Rectangle operator+(const Rectangle& r, const Vector& v){
    return Rectangle(r) += v;
}
Rectangle operator+(const Vector& v, const Rectangle& r) {
    return Rectangle(r) += v;
}


Rectangles::Rectangles() = default;

size_t Rectangles::size() const {
    return rectangles.size();
}

const Rectangle& Rectangles::operator[](size_t index) const{
    return rectangles[index];
}

Rectangle& Rectangles::operator[](size_t index) {
    return rectangles[index];
}

bool Rectangles::operator==(const Rectangles &that) const {
    if (size() != that.size())
        return false;

    for (int i = 0; i < size(); i++)
        if (!(that[i] == rectangles[i]))
            return false;

    return true;
}

Rectangles &Rectangles::operator+=(const Vector& v) {
    for (int i = 0; i < size(); i++)
        rectangles[i] += v;

    return *this;
}

Rectangles::Rectangles(std::initializer_list<Rectangle> list) {
    for (Rectangle r: list)
        rectangles.push_back(r);
}

Rectangles operator+(const Rectangles& rr, const Vector& v) {
    return Rectangles(rr) += v;
}
Rectangles operator+(const Vector& v, const Rectangles& rr) {
    return Rectangles(rr) += v;
}



