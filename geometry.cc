#include "geometry.h"
#include <cassert>
#include <algorithm>

Position::Position(int x, int y) : x_coord(x), y_coord(y) {}

Position::Position(const Vector &v) : x_coord(v.x()), y_coord(v.y()) {}

int Position::x() const {
    return x_coord;
}

int Position::y() const {
    return y_coord;
}

Position Position::reflection() const {
    return Position(y_coord, x_coord);
}

const Position &Position::origin() {
    const static Position origin = Position(0, 0);
    return origin;
}

bool Position::operator==(const Position &that) const {
    return x() == that.x() && y() == that.y();
}

Position &Position::operator+=(const Vector &v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}

Position operator+(const Position &p, const Vector &v) {
    return Position(p) += v;
}

Position operator+(const Vector &v, const Position &p) {
    return Position(p) += v;
}


Vector::Vector(int x, int y) : x_coord(x), y_coord(y) {}

Vector::Vector(const Position &p) : x_coord(p.x()), y_coord(p.y()) {}

int Vector::x() const {
    return x_coord;
}

int Vector::y() const {
    return y_coord;
}

Vector Vector::reflection() const {
    return Vector(y_coord, x_coord);
}

bool Vector::operator==(const Vector &that) const {
    return x() == that.x() && y() == that.y();
}

Vector &Vector::operator+=(const Vector &v) {
    x_coord += v.x();
    y_coord += v.y();
    return *this;
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector(v1) += v2;
}


Rectangle::Rectangle(int w, int h, Position p) : width_(w), height_(h), pos_(p) {
    assert(w > 0 && h > 0);
}

Rectangle::Rectangle(int w, int h) : width_(w), height_(h), pos_(Position(0, 0)) {
    assert(w > 0 && h > 0);
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
    return width() == that.width() && height() == that.height()
           && pos() == that.pos();
}

Rectangle &Rectangle::operator+=(const Vector &v) {
    pos_ += v;
    return *this;
}

Rectangle operator+(const Rectangle &r, const Vector &v) {
    return Rectangle(r) += v;
}

Rectangle operator+(const Vector &v, const Rectangle &r) {
    return Rectangle(r) += v;
}


Rectangles::Rectangles(std::initializer_list<Rectangle> list) : rectangles(list) {}

size_t Rectangles::size() const {
    return rectangles.size();
}

const Rectangle &Rectangles::operator[](size_t index) const {
    assert(index < size());

    return rectangles[index];
}

Rectangle &Rectangles::operator[](size_t index) {
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

Rectangles &Rectangles::operator+=(const Vector &v) {
    for (int i = 0; i < size(); i++)
        rectangles[i] += v;

    return *this;
}

Rectangles operator+(const Rectangles &rr, const Vector &v) {
    return Rectangles(rr) += v;
}

Rectangles operator+(const Vector &v, const Rectangles &rr) {
    return Rectangles(rr) += v;
}


bool has_common_horizontal_edge(const Rectangle &r1, const Rectangle &r2) {
    return ((r1.pos().x() == r2.pos().x() && r1.width() == r2.width()) &&
            (r1.pos().y() + r1.height() == r2.pos().y() || r2.pos().y() + r2.height() == r1.pos().y()));
}

bool has_common_vertical_edge(const Rectangle &r1, const Rectangle &r2) {
    return ((r1.pos().y() == r2.pos().y() && r1.height() == r2.height()) &&
            (r1.pos().x() + r1.width() == r2.pos().x() || r2.pos().x() + r2.width() == r1.pos().x()));
}

Rectangle merge_horizontally(const Rectangle &r1, const Rectangle &r2) {
    assert(has_common_horizontal_edge(r1, r2));

    return Rectangle(r1.width(), r1.height() + r2.height(),
                     Position(r1.pos().x(), std::min(r1.pos().y(), r2.pos().y())));

}

Rectangle merge_vertically(const Rectangle &r1, const Rectangle &r2) {
    assert(has_common_vertical_edge(r1, r2));

    return Rectangle(r1.width() + r2.width(), r1.height(),
                     Position(std::min(r1.pos().x(), r2.pos().x()), r1.pos().y()));
}

Rectangle merge_all(const Rectangles &rr) {
    if (rr.size() == 0)
        return Rectangle(0, 0);

    Rectangle merged = rr[0];

    for (size_t i = 1; i < rr.size(); i++) {
        if (has_common_horizontal_edge(merged, rr[i]))
            merged = merge_horizontally(merged, rr[i]);
        else
            merged = merge_vertically(merged, rr[i]);
    }

    return merged;
}