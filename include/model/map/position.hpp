#ifndef POSITION_HPP
#define POSITION_HPP

struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    Position& operator+=(const Position& pos) {
        x += pos.x;
        y += pos.y;
        return *this;
    }

    Position& operator-=(const Position& pos) {
        x -= pos.x;
        y -= pos.y;
        return *this;
    }

    Position operator+(const Position& pos) const {
        return Position(x + pos.x, y + pos.y);
    }
    
    Position operator-(const Position& pos) const {
        return Position(x - pos.x, y - pos.y);
    }

    bool operator==(const Position& pos) const {
        return x == pos.x && y == pos.y;
    }

    bool operator!=(const Position& pos) const {
        return !(*this == pos);
    }
};

#endif