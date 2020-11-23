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
    explicit Position(const Vector& v);

    int x() const;
    int y() const;
    Position reflection() const;
    const static Position& origin();

    bool operator==(const Position& that) const;
    Position& operator+=(const Vector& v);
};
Position operator+(const Position& p, const Vector& v);
Position operator+(const Vector& v, const  Position& p); //TODO bez kopiowania kodu to zrobić??


class Vector {
private:
    int x_coord;
    int y_coord;
public:
    Vector(int x, int y);
    explicit Vector(const Position& p);

    int x() const;
    int y() const;
    Vector reflection() const;

    bool operator==(const Vector& that) const;
    Vector& operator+=(const Vector& v);
};
Vector operator+(const Vector& v1, const Vector& v2);

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
    Rectangle& operator+=(const Vector& v);
};
Rectangle operator+(const Rectangle& r, const Vector& v);
Rectangle operator+(const Vector& v, const Rectangle& r); //TODO kopiowanie kodu


class Rectangles {
private:
    std::vector<Rectangle> rectangles; // czy takie jest git czy to kopiuje????
public:
    Rectangles();
    Rectangles(std::initializer_list<Rectangle>);

    size_t size() const;

    const Rectangle& operator[](size_t index) const;
    Rectangle& operator[](size_t index);
    bool operator==(const Rectangles& that) const;
    Rectangles& operator+=(const Vector& v);
};
Rectangles operator+(const Rectangles& rr, const Vector& v);
Rectangles operator+(const Vector& v, const Rectangles& rr); //TODO kopiowanie kodu

Rectangle merge_horizontally(Rectangle r1, Rectangle r2);

Rectangle merge_vertically(Rectangle r1, Rectangle r2);

Rectangle merge_all(Rectangles r);

#endif //GEOMETRY_LIBRARY_H
