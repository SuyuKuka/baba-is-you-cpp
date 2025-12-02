#ifndef POSITION_HPP
#define POSITION_HPP

struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    Position& operator+=(const Position& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Position& operator-=(const Position& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Position operator+(const Position& other) const {
        return Position(x + other.x, y + other.y);
    }

    Position operator-() const {
        return Position(-x, -y);
    }
    
    Position operator-(const Position& other) const {
        return Position(x - other.x, y - other.y);
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

#endif