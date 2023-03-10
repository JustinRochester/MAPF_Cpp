//
// Created by Administrator on 2023/3/8.
//

#include "PositionList.h"


size_t PositionList::PositionListHasher::operator()(const PositionList &positions) const {
    Position::PositionHasher position_hash;
    size_t h = 0;
    for(Position position : positions.position_list)
        h = (h << 3) ^ (h >> 29) ^ position_hash(position);
    return h;
}

PositionList::PositionList() {
    position_list.clear();
}

PositionList::PositionList(const PositionList &other):position_list(other.position_list) {
}

int PositionList::size() const {
    return position_list.size();
}

Position& PositionList::operator [] (int id) {
    if(id < size()) {
        return position_list[id];
    }
    else
        throw "Out of the number of agents.";
}

const Position& PositionList::operator [] (int id) const {
    if(id < size()) {
        return position_list[id];
    }
    else
        throw "Out of the number of agents.";
}

std::vector<Position> &PositionList::get_position_list() {
    return position_list;
}

const std::vector<Position> &PositionList::get_position_list() const {
    return position_list;
}

const size_t PositionList::get_hash() const {
    return PositionListHasher()(*this);
}

bool PositionList::equalTo(const PositionList &other) const {
    if(get_hash() != other.get_hash())
        return false;
    if(size() != other.size())
        return false;
    for(int i=0; i<size(); ++i)
        if(position_list[i] != other[i])
            return false;
    return true;
}

bool operator==(const PositionList &lhs, const PositionList &rhs) {
    return lhs.equalTo(rhs);
}

bool operator!=(const PositionList &lhs, const PositionList &rhs) {
    return !lhs.equalTo(rhs);
}

PositionList::operator std::string() const {
    std::string message = "<";
    for(int i=0; i<size(); ++i) {
        if(i>0) message += ",";
        message += (std::string)(position_list[i]);
    }
    return message + ">";
}

std::ostream &operator<<(std::ostream &out, const PositionList &position_list) {
    return out << (std::string)(position_list);
}

std::istream &operator>>(std::istream &in, PositionList &position_list) {
    int number_of_agents;
    in>>number_of_agents;
    position_list.position_list.assign(number_of_agents, Position());
    for(int i=0; i<number_of_agents; ++i)
        in>>position_list[i];
    return in;
}

