//
// Created by Administrator on 2023/3/4.
//

#include "SingleAgentState.h"

SingleAgentState::SingleAgentState(const Position &position_, const TIME_TYPE &time_): position(position_), time(time_) {
}

size_t SingleAgentState::SingleStateAgentHasher::operator()(const State &s) const {
    try {
        auto &single_state = dynamic_cast<const SingleAgentState &>(s);
        std::hash<TIME_TYPE> h;
        size_t h1 = Position::PositionHasher()(single_state.position), h2 = h(single_state.time);
        return (h1 >> 13) ^ (h1 << 19) ^ h2;
    }
    catch(const char *msg) {
        std::string s = msg;
        s = s + "\nState s could not be dynamic casted to SingleAgentState";
        throw s.c_str();
    }
}

bool SingleAgentState::equalTo(const State &s) const {
    auto &other = dynamic_cast<const SingleAgentState&>(s);
    SingleStateAgentHasher h;
    if(h(*this) != h(other))
        return false;
    return (position == other.position) && (time == other.time);
}

const Position & SingleAgentState::get_position() const {
    return position;
}

const TIME_TYPE & SingleAgentState::get_time() const {
    return time;
}

void SingleAgentState::set_position(const Position &position_) {
    position = position_;
}

void SingleAgentState::set_time(const TIME_TYPE &time_) {
    time = time_;
}

SingleAgentState::operator std::string() const {
    return "<" + (std::string)(position) + "," + std::to_string(time) + ">";
}

std::ostream& operator << (std::ostream &out, const SingleAgentState &s) {
    return out<<(std::string)(s);
}

std::istream& operator >> (std::istream &in, SingleAgentState &s) {
    return in >> s.position >> s.time;
}

SingleAgentState SingleAgentState::apply(const Vector &v) {
    SingleAgentState result = *this;
    result.position += v;
    return result;
}

State::StateHasher & SingleAgentState::get_hasher() const {
    SingleStateAgentHasher *h = new SingleStateAgentHasher();
    return *h;
}
