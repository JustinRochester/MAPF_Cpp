//
// Created by Administrator on 2023/3/10.
//

#include "AgentPath.h"

AgentPath::AgentPath() = default;

Position &AgentPath::operator[](int time) {
    if(time<position_list.size())
        return position_list[time];
    else
        return position_list.back();
}

const Position &AgentPath::operator[](int time) const {
    if(time<position_list.size())
        return position_list[time];
    else
        return position_list.back();
}
