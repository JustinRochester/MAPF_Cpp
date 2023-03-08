//
// Created by Administrator on 2023/3/5.
//

#include "MultiAgentState.h"

size_t MultiAgentState::MultiAgentStateHasher::operator()(const State &s) const {
    auto &multi_state = dynamic_cast<const MultiAgentState&>(s);
    std::hash<TIME_TYPE> h;
    size_t h1 = multi_state.positions.get_hash(), h2 = h(multi_state.time);
    return (h1>>13) ^ (h1<<19) ^ h2;
}

MultiAgentState::MultiAgentState(const TIME_TYPE &time_): time(time_) {
}

bool MultiAgentState::equalTo(const State &s) const {
    try {
        auto &rhs = dynamic_cast<const MultiAgentState &>(s);
        if (get_hash() != rhs.get_hash())
            return false;
        return positions != rhs.positions;
    }
    catch(const char *msg) {
        std::string str = msg;
        str += "\nState s could not be dynamic casted to MultiAgentState.";
        throw str.c_str();
    }
}

int MultiAgentState::size() {
    return positions.size();
}

PositionList & MultiAgentState::get_positions() {
    return positions;
}

const PositionList & MultiAgentState::get_positions() const {
    return positions;
}

const TIME_TYPE & MultiAgentState::get_time() const {
    return time;
}

void MultiAgentState::set_time(const TIME_TYPE &time_) {
    time = time_;
}

size_t MultiAgentState::get_hash() const {
    return MultiAgentStateHasher()(*this);
}

Position &MultiAgentState::operator[](int id) {
    if(id < positions.size())
        return positions[id];
    else
        throw "Out of agent numbers";
}

const Position &MultiAgentState::operator[](int id) const {
    if(id < positions.size())
        return positions[id];
    else
        throw "Out of agent numbers";
}

MultiAgentState::operator std::string() const {
    return "<" + std::to_string(time) + "," + (std::string)(positions) + ">";
}

std::ostream &operator<<(std::ostream &out, const MultiAgentState &s) {
    return out << (std::string)(s);
}

std::istream &operator>>(std::istream &in, MultiAgentState &s) {
    return in >> s.positions >> s.time;
}

MultiAgentState MultiAgentState::apply(const std::vector<Vector> &operation_list) {
    MultiAgentState result = *this;
    int agent_number = size();
    for(int i=0; i<agent_number; ++i)
        result.positions[i] += operation_list[i];
    return result;
}


