//
// Created by Administrator on 2023/3/5.
//

#include "State.h"

State::~State() = default;

bool State::operator==(const State &s) const {
    return equalTo(s);
}

bool State::operator!=(const State &s) const {
    return !equalTo(s);
}
