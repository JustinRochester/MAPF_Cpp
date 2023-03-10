//
// Created by Administrator on 2023/3/4.
//

#include "Position.h"
#include "PositionList.h"


Position::Position(const GRID_TYPE &y_, const GRID_TYPE &x_): y(y_), x(x_) {}

Position::Position(const Position &other):y(other.y), x(other.x) {}

void Position::setx(const GRID_TYPE &x_) {
    x=x_;
}

void Position::sety(const GRID_TYPE &y_) {
    y=y_;
}

const GRID_TYPE & Position::getx() const {
    return x;
}

const GRID_TYPE & Position::gety() const {
    return y;
}

bool operator == (const Position &lhs, const Position &rhs) {
    Position::PositionHasher h;
    if(h(lhs) != h(rhs))
        return false;
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}
bool operator != (const Position &lhs, const Position &rhs) {
    Position::PositionHasher h;
    if(h(lhs) != h(rhs))
        return true;
    return (lhs.x != rhs.x) || (lhs.y != rhs.y);
}

Position::operator std::string() const {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

std::ostream &operator<<(std::ostream &out, const Position &p) {
    return out<<(std::string)(p);
}

std::istream &operator>>(std::istream &in, Position &p) {
    return in>>p.x>>p.y;
}

Position& Position::operator += (const Position &rhs) {
    x += rhs.getx();
    y += rhs.gety();
    return *this;
}

Position& Position::operator -= (const Position &rhs) {
    x -= rhs.getx();
    y -= rhs.gety();
    return *this;
}

Position Position::operator + (const Position &rhs) const {
    Position lhs = *this;
    return lhs += rhs;
}

Position Position::operator - (const Position &rhs) const {
    Position lhs = *this;
    return lhs -= rhs;
}

size_t Position::PositionHasher::operator()(const Position &p) const {
    std::hash<GRID_TYPE> h;
    size_t hx = h(p.x), hy = h(p.y);
    return (hx<<7) ^ (hx>>15) ^ hy;
}