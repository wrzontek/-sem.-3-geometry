#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H

void hello();

class Position {
private:
    int x_coord;
    int y_coord;
public:
    Position(int x, int y);
    bool operator==(const Position& that);
    int x() const;
    int y() const;
    Position reflection() const;
    static const Position origin(); // TODO zwraca zwykły a nie const Position

};

#endif //GEOMETRY_LIBRARY_H
