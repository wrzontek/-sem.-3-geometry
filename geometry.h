#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H

#include <cstdio>
#include <vector>
#include <cstdint>
#include <cassert>

class Position;
class Vector;
class Rectangle;
class Rectangles;


class Position {
private:
    int_fast32_t x_coord;
    int_fast32_t y_coord;
public:
    Position(int_fast32_t x, int_fast32_t y);
    Position(const Position &other) = default;
    explicit Position(const Vector &v);

    int_fast32_t x() const;
    int_fast32_t y() const;
    Position reflection() const;
    const static Position &origin();

    bool operator==(const Position &that) const;
    Position &operator+=(const Vector &v);
    Position &operator=(const Position &other) = default;
};

Position operator+(const Position &p, const Vector &v);
Position operator+(const Vector &v, const Position &p);


class Vector {
private:
    int_fast32_t x_coord;
    int_fast32_t y_coord;
public:
    Vector(int_fast32_t x, int_fast32_t y);
    Vector(const Vector &other) = default;
    explicit Vector(const Position &p);

    int_fast32_t x() const;
    int_fast32_t y() const;
    Vector reflection() const;

    bool operator==(const Vector &that) const;
    Vector &operator+=(const Vector &v);
    Vector &operator=(const Vector &other) = default;
};

Vector operator+(const Vector &v1, const Vector &v2);

class Rectangle {
private:
    int_fast32_t width_;
    int_fast32_t height_;
    Position pos_;
public:
    Rectangle(int_fast32_t width, int_fast32_t height, Position p);
    Rectangle(int_fast32_t width, int_fast32_t height);
    Rectangle(const Rectangle &other) = default;

    int_fast32_t width() const;
    int_fast32_t height() const;
    Position pos() const;
    int_fast32_t area() const;

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
    Rectangles(std::initializer_list<Rectangle>);
    Rectangles(const Rectangles &other) = default;
    Rectangles(Rectangles&&) noexcept = default;
    ~Rectangles() = default;

    size_t size() const;

    const Rectangle &operator[](size_t index) const;
    Rectangle &operator[](size_t index);
    bool operator==(const Rectangles &that) const;
    Rectangles &operator+=(const Vector &v);
    Rectangles &operator=(Rectangles&&) noexcept = default;
    Rectangles &operator=(const Rectangles &other) = default;
};

Rectangles operator+(const Rectangles &rr, const Vector &v);
Rectangles operator+(const Vector &v, const Rectangles &rr);

Rectangles operator+(const Vector &v, Rectangles &&rr);
Rectangles operator+(Rectangles && rr, const Vector &v);

Rectangle merge_horizontally(const Rectangle &r1, const Rectangle &r2);

Rectangle merge_vertically(const Rectangle &r1, const Rectangle &r2);

Rectangle merge_all(const Rectangles &r);

#endif //GEOMETRY_LIBRARY_H
