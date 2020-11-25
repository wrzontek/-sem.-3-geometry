#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H

#include <cstdio>
#include <vector>
#include <cassert>

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
    Position(const Position &other) = default;
    explicit Position(const Vector &v);

    int x() const;
    int y() const;
    Position reflection() const;
    const static Position &origin();

    bool operator==(const Position &that) const;
    Position &operator+=(const Vector &v);
    Position &operator=(const Position &other) = default;
};

Position operator+(const Position &p, const Vector &v);
Position operator+(const Vector &v, const Position &p); //TODO bez kopiowania kodu to zrobić??


class Vector {
private:
    int x_coord;
    int y_coord;
public:
    Vector(int x, int y);
    Vector(const Vector &other) = default;
    explicit Vector(const Position &p);

    int x() const;
    int y() const;
    Vector reflection() const;

    bool operator==(const Vector &that) const;
    Vector &operator+=(const Vector &v);
    Vector &operator=(const Vector &other) = default;
};

Vector operator+(const Vector &v1, const Vector &v2);

class Rectangle {
private:
    int width_;
    int height_; // czy takie nazewnictwo (te _) git? to żeby gettery mogły mieć normalne nazwy
    Position pos_;
public:
    Rectangle(int width, int height, Position p);
    Rectangle(int width, int height);
    Rectangle(const Rectangle &other) = default;

    int width() const;
    int height() const;
    Position pos() const;
    int area() const;

    bool operator==(const Rectangle &that) const;
    Rectangle &operator+=(const Vector &v);
    Rectangle &operator=(const Rectangle &other) = default;
};

Rectangle operator+(const Rectangle &r, const Vector &v);
Rectangle operator+(const Vector &v, const Rectangle &r);


class Rectangles {
private:
    std::vector<Rectangle> rectangles;
public:
    Rectangles() = default;
    Rectangles(const Rectangles&) {
        assert(((void)"Used copy constructor", false));
    }
    Rectangles& operator=(const Rectangles&) {
        assert(((void)"Used copy assignment", false));
    }
    Rectangles(Rectangles&&) noexcept = default;
    Rectangles& operator=(Rectangles&&) noexcept = default;
    ~Rectangles() = default;

    //Rectangles() = default;
    Rectangles(std::initializer_list<Rectangle>);
    //~Rectangles() = default;

    size_t size() const;

    const Rectangle &operator[](size_t index) const;
    Rectangle &operator[](size_t index);
    bool operator==(const Rectangles &that) const;
    Rectangles &operator+=(const Vector &v);
};

Rectangles operator+(const Rectangles &rr, const Vector &v);
Rectangles operator+(const Vector &v, const Rectangles &rr);

Rectangle merge_horizontally(const Rectangle &r1, const Rectangle &r2);

Rectangle merge_vertically(const Rectangle &r1, const Rectangle &r2);

Rectangle merge_all(const Rectangles &r);

#endif //GEOMETRY_LIBRARY_H
