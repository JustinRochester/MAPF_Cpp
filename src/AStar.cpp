//
// Created by Administrator on 2023/3/4.
//

#include <unordered_set>
#include "AStar.h"

AStar::AStar() {
    heuristic_maps.clear();
}

void AStar::set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) {
    Solver::set_problem(start_positions_, goal_positions_);
    heuristic_maps.assign(agents_number, HeuristicMap());
    for(int i=0; i<agents_number; ++i)
        heuristic_maps[i].calculate_heuristic(maps, goal_positions[i], allowed_operations);
}

void AStar::calculate_heuristic(AStarNode *node) const {
    HEURISTIC_TYPE h_val=0;
    for(int i=0; i<agents_number; ++i) {
        const Position &p = (*node)[i];
        h_val += heuristic_maps[i][p.gety()][p.getx()];
    }
    node->set_h(h_val);
}

void AStar::solve() {
    MultiAgentState initial_state(0);
    initial_state.get_positions().get_position_list() = start_positions;

    AStarNode *initial_node = new AStarNode(0, 0, agents_number);
    initial_node->get_state() = initial_state;
    calculate_heuristic(initial_node);
    open.push_safe(initial_node);
    delete initial_node;

    while(!open.empty()) {
        auto now_node = open.top_safe<AStarNode>();
        open.pop();
        if(is_goal_node(now_node)) {
            solution = now_node->get_g();
            return;
        }
        expand_child_nodes(now_node);
        close.add(new MultiAgentState(now_node->get_state()));
        delete now_node;
    }
}

void AStar::search_moves(AStarNode *node, int agent_id) {
    if(agent_id == -1) {
        calculate_heuristic(node);
        generate_nodes(node);
        return;
    }
    Position now_position = node->get_state()[agent_id];
    Position ban_position = Position(-1, -1);
    if(constraint_set.count(now_position))
        ban_position = constraint_set[now_position];

    HEURISTIC_TYPE now_g = node->get_g();
    bool at_goal = (now_position == goal_positions[agent_id]);

    for(const auto &[move, cost] : allowed_operations) {
        Position next_position = now_position + move;
        if(constraint_set.count(next_position) || next_position == ban_position)
            continue;
        if(next_position.gety() < 0 || next_position.gety() >= maps.get_height() )
            continue;
        if(next_position.getx() < 0 || next_position.getx() >= maps.get_width() )
            continue;
        if(maps[next_position.gety()][next_position.getx()] == UNPASSABLE)
            continue;

        constraint_set[next_position] = now_position;

        HEURISTIC_TYPE next_g = now_g;
        int stop_time = -1;
        if(at_goal) {
            if(move != Position(0, 0))
                next_g += node->get_state().get_time() - node->get_stop_time()[agent_id];
            else
                stop_time = node->get_stop_time()[agent_id];
        }
        else {
            next_g += cost;
            if(next_position == goal_positions[agent_id])
                stop_time = node->get_state().get_time();
        }

        AStarNode *new_node = new AStarNode(*node);
        new_node->set_g(next_g);
        new_node->get_state()[agent_id] = next_position;
        new_node->get_stop_time()[agent_id] = stop_time;
        search_moves(new_node, agent_id - 1);

        constraint_set.erase(next_position);
        delete new_node;
    }
}

void AStar::expand_child_nodes(const AStarNode *node) {
    AStarNode *now_node = new AStarNode(*node);
    now_node->get_state().set_time(node->get_state().get_time() + 1);
    constraint_set.clear();
    search_moves(now_node, agents_number - 1);
    delete now_node;
}

bool AStar::expand_nodes(Node *node) {
    auto a_star_node = dynamic_cast<const AStarNode *>(node);
    MultiAgentState state = a_star_node->get_state();
    if(close.exists( &(a_star_node->get_state()) ))
        return false;
    open.push_safe(a_star_node);
    Solver::expand_nodes(node);
    return true;
}

bool AStar::generate_nodes(Node *node) {
    if(!expand_nodes(node))
        return false;
    Solver::generate_nodes(node);
    return true;
}

bool AStar::is_goal_node(const Node *node) const {
    auto result_node = dynamic_cast<const AStarNode *>(node);
    for(int i=0; i<agents_number; ++i)
        if(result_node->get_state()[i] != goal_positions[i])
            return false;
    return true;
}

