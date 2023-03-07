//
// Created by Administrator on 2023/3/5.
//

#include "AStarNode.h"

AStarNode::AStarNode(HEURISTIC_TYPE g_, HEURISTIC_TYPE h_): Node(g_, h_) {
    agents_state.get_position().clear();
}

Position& AStarNode::operator[](int id) {
    if(id < agents_state.get_position().size())
        return agents_state[id];
    else
        throw "Out of number of agents";
}

MultiAgentState &AStarNode::get_state() {
    return agents_state;
}

const MultiAgentState &AStarNode::get_state() const {
    return agents_state;
}


AStarNode AStarNode::apply(const std::vector<std::pair<Vector, HEURISTIC_TYPE>> &operation_list) {
    int agent_number = agents_state.get_position().size();
    AStarNode result = *this;

    std::vector<Vector> move_list(agent_number, Vector());
    for(int i=0; i<agent_number; ++i) {
        move_list[i]=operation_list[i].first;
        result.g += operation_list[i].second;
    }
    result.agents_state = result.agents_state.apply(move_list);
    return result;
}