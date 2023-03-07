//
// Created by Administrator on 2023/3/4.
//

#include "Solver.h"
#include "Node.h"

Solver::Solver() {
    start_positions.clear();
    goal_positions.clear();
    agents_number = 0;
    clear_nodes();
}

void Solver::set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) {
    start_positions = start_positions_;
    goal_positions = goal_positions_;
    agents_number = start_positions.size();
}

void Solver::set_map(const Map &maps_) {
    maps = maps_;
}

void Solver::clear_nodes() {
    expanded_node_number = 0;
    generated_node_number = 0;
}

void Solver::expand_nodes(const Node &node) {
    ++expanded_node_number;
}

void Solver::generate_nodes(const Node &node) {
    ++generated_node_number;
}

std::vector< std::pair<Vector, HEURISTIC_TYPE> > &Solver::get_allowed_operations() {
    return allowed_operations;
}

const std::vector< std::pair<Vector, HEURISTIC_TYPE> > &Solver::get_allowed_operations() const {
    return allowed_operations;
}