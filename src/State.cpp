//
// Created by Administrator on 2023/3/5.
//

#include "State.h"

bool State::operator==(const State &s) const {
    return equalTo(s);
}

bool State::operator!=(const State &s) const {
    return !equalTo(s);
}
