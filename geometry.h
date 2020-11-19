#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H


#include <cstdio>

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
    bool operator==(const Position& that) const;
    int x() const;
    int y() const;
    Position reflection() const;
    static const Position origin(); // TODO zwraca zwykły a nie const Position
    Position& operator+=(Vector v);
};


class Vector {
private:
    int x_coord;
    int y_coord;
public:
    Vector(int x, int y);
    bool operator==(const Vector& that) const;
    int x() const;
    int y() const;
    Vector reflection() const;
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
    bool operator==(const Rectangle& that) const;
    int width() const;
    int height() const;
    Position pos() const;
    Rectangle& operator+=(Vector v);
    int area() const;
};


class Rectangles {
private:

public:
    Rectangles();
    Rectangle& operator[](size_t index);// może jakiś operator overloading tutaj i może w innych miejscach też?
    size_t size() const;
    bool operator==(const Rectangles& that) const;
    Rectangles& operator+=(Vector v);
};

#endif //GEOMETRY_LIBRARY_H
