//
// Created by Administrator on 2023/3/5.
//

#include "MultiAgentState.h"

size_t MultiAgentState::MultiAgentStateHasher::operator()(const State &s) const {
    auto &multi_state = dynamic_cast<const MultiAgentState&>(s);
    std::hash<TIME_TYPE> h;
    Position::PositionHasher position_hash;
    size_t h1 = 0, h2 = h(multi_state.time);
    for(Position position : multi_state.position)
        h1 = (h1 << 3) ^ (h1 >> 29) ^ position_hash(position);
    return (h1>>13) ^ (h1<<19) ^ h2;
}

MultiAgentState::MultiAgentState(const TIME_TYPE &time_): time(time_) {
}

bool MultiAgentState::equalTo(const State &s) const {
    try {
        auto &rhs = dynamic_cast<const MultiAgentState &>(s);
        MultiAgentStateHasher h;
        if (h(*this) != h(rhs))
            return false;

        int agent_number = position.size();
        if (agent_number != rhs.position.size())
            return false;

        for (int i = 0; i < agent_number; ++i)
            if (position[i] != rhs.position[i])
                return false;
        return true;
    }
    catch(const char *msg) {
        std::string s = msg;
        s += "\nState s could not be dynamic casted to MultiAgentState.";
        throw s.c_str();
    }
}

int MultiAgentState::size() {
    return position.size();
}

std::vector<Position> &MultiAgentState::get_position() {
    return position;
}

const std::vector<Position> &MultiAgentState::get_position() const {
    return position;
}

const TIME_TYPE & MultiAgentState::get_time() const {
    return time;
}

void MultiAgentState::set_time(const TIME_TYPE &time_) {
    time = time_;
}

State::StateHasher &MultiAgentState::get_hasher() const {
    MultiAgentStateHasher *h = new MultiAgentStateHasher();
    return *h;
}

Position &MultiAgentState::operator[](int id) {
    if(id < position.size())
        return position[id];
    else
        throw "Out of agent numbers";
}

const Position &MultiAgentState::operator[](int id) const {
    if(id < position.size())
        return position[id];
    else
        throw "Out of agent numbers";
}

MultiAgentState::operator std::string() const {
    std::string s = "<";
    for(Position agent_position : position)
        s += (std::string)(agent_position) + ",";
    return s + std::to_string(time) + ">";
}

std::ostream &operator<<(std::ostream &out, const MultiAgentState &s) {
    return out << (std::string)(s);
}

std::istream &operator>>(std::istream &in, MultiAgentState &s) {
    int agent_number = s.size();
    for(int i=0; i<agent_number; ++i)
        in >> s.position[i];
    return in >> s.time;
}

MultiAgentState MultiAgentState::apply(const std::vector<Vector> &operation_list) {
    MultiAgentState result = *this;
    int agent_number = size();
    for(int i=0; i<agent_number; ++i)
        result.position[i] += operation_list[i];
    return result;
}


