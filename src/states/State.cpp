//
// Created by Administrator on 2023/3/5.
//

#include "State.h"

State::State():previous_state(nullptr) {
}

State::State(const State &other):previous_state(other.previous_state) {
}

State::~State() = default;

bool State::operator==(const State &s) const {
    return equalTo(s);
}

bool State::operator!=(const State &s) const {
    return !equalTo(s);
}

const State * State::get_previous_state() const {
    return previous_state;
}

void State::set_previous_state(const State *previousState) {
    previous_state = previousState;
}
