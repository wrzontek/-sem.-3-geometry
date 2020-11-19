#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H

#include <cstdio>
#include <vector>

class Position;
class Vector;
class Rectangle;
class Rectangles;

class Position {
private:
    int x_coord;
    int y_coord;
public:
    Position(int x, int y);

    int x() const;
    int y() const;
    Position reflection() const;
    static const Position origin(); // TODO zwraca zwykły a nie const Position

    bool operator==(const Position& that) const;
    Position& operator+=(Vector v);
};


class Vector {
private:
    int x_coord;
    int y_coord;
public:
    Vector(int x, int y);

    int x() const;
    int y() const;
    Vector reflection() const;

    bool operator==(const Vector& that) const;
    Vector& operator+=(Vector v);
};


class Rectangle {
private:
    int width_;
    int height_; // czy takie nazewnictwo (te _) git? to żeby gettery mogły mieć normalne nazwy
    Position pos_;
public:
    Rectangle(int width, int height, Position p);
    Rectangle(int width, int height);

    int width() const;
    int height() const;
    Position pos() const;
    int area() const;

    bool operator==(const Rectangle& that) const;
    Rectangle& operator+=(Vector v);
};


class Rectangles {
private:
    std::vector<Rectangle> rectangles; // czy takie jest git czy to kopiuje????
public:
    Rectangles();
    size_t size() const;

    const Rectangle& operator[](size_t index) const;
    Rectangle& operator[](size_t index);
    bool operator==(const Rectangles& that) const;
    Rectangles& operator+=(Vector v);
};

Rectangle merge_horizontally(Rectangle r1, Rectangle r2);

Rectangle merge_vertically(Rectangle r1, Rectangle r2);

Rectangle merge_all(Rectangles r);

#endif //GEOMETRY_LIBRARY_H
