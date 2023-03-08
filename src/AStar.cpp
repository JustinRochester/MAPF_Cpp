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

    AStarNode *initial_node = new AStarNode();
    initial_node->get_state() = initial_state;
    calculate_heuristic(initial_node);
    open.push_node(initial_node);

    while(!open.empty()) {
        auto now_node = dynamic_cast<const AStarNode *>(open.top_node());
        open.pop();
//        std::cout<<now_node->get_state()<<" "<<now_node->get_g()<<" "<<now_node->get_h()<<" "<<now_node->get_static_f()<<"\n";
        if(is_goal_node(now_node))
            return ;
        expand_child_nodes(now_node);

        MultiAgentState now_state = now_node->get_state();
        close.add(&now_state);
        delete now_node;
    }
}

void AStar::search_moves(AStarNode *node, int agent_id,
                         std::unordered_set<PositionList, PositionList::PositionListHasher> reservation_table) {
    if(agent_id == -1) {
        calculate_heuristic(node);
        generate_nodes(node);
        return;
    }
    PositionList positions;
    for(const auto &[move, cost] : allowed_operations) {
        Position next_position = node->get_state()[agent_id] + move;
        if(next_position.gety() < 0 || next_position.gety() >= maps.get_height() )
            continue;
        if(next_position.getx() < 0 || next_position.getx() >= maps.get_width() )
            continue;
        if(maps[next_position.gety()][next_position.getx()] == UNPASSABLE)
            continue;

        std::unordered_set<PositionList, PositionList::PositionListHasher> new_reservation_table = reservation_table;

        positions.get_position_list() = std::vector<Position>({next_position});
        if(new_reservation_table.count(positions))
            continue;
        new_reservation_table.insert(positions);

        positions.get_position_list().push_back(node->get_state()[agent_id]);
        if(new_reservation_table.count(positions))
            continue;
        new_reservation_table.insert(positions);

        AStarNode *new_node = new AStarNode(*node);
        new_node->set_g(node->get_g()+cost);
        new_node->get_state()[agent_id] = next_position;
        search_moves(new_node, agent_id-1, new_reservation_table);
    }
}

void AStar::expand_child_nodes(const AStarNode *node) {
    AStarNode *now_node = new AStarNode(*node);
    now_node->get_state().set_time(node->get_state().get_time() + 1);
    search_moves(now_node, agents_number-1, std::unordered_set<PositionList, PositionList::PositionListHasher>());
}

bool AStar::expand_nodes(Node *node) {
    auto a_star_node = dynamic_cast<const AStarNode *>(node);
    MultiAgentState state = a_star_node->get_state();
    if(close.exists(&state))
        return false;
    open.push_node(node);
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

