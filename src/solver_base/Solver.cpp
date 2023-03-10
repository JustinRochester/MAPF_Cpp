//
// Created by Administrator on 2023/3/4.
//

#include "Solver.h"
#include "Node.h"

Solver::Solver() {
    start_positions.clear();
    goal_positions.clear();
    agents_number = 0;
    solution = SOLUTION_NOT_FOUND;
    clear_nodes();
}

Solver::Solver(const Solver &other) : agents_number(other.agents_number), start_positions(other.start_positions),
                                      goal_positions(other.goal_positions),
                                      expanded_node_number(other.expanded_node_number),
                                      generated_node_number(other.generated_node_number), maps(other.maps),
                                      allowed_operations(other.allowed_operations),
                                      solution(other.solution) {
}

Solver::~Solver() {
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
    for(const State * state : state_log)
        delete state;
    state_log.clear();
}

bool Solver::expand_nodes(Node *node) {
    ++expanded_node_number;
    return true;
}

bool Solver::generate_nodes(Node *node) {
    ++generated_node_number;
    return true;
}

std::vector<std::pair<Vector, HEURISTIC_TYPE> > &Solver::get_allowed_operations() {
    return allowed_operations;
}

const std::vector<std::pair<Vector, HEURISTIC_TYPE> > &Solver::get_allowed_operations() const {
    return allowed_operations;
}

HEURISTIC_TYPE Solver::get_solution() const {
    if(solution == SOLUTION_NOT_FOUND)
        throw "Solution has not been found!";
    return solution;
}

void Solver::find_solutions(const Node *node) {
    solution = node->get_g();
    for(const State * state : solution_path)
        delete state;
    solution_path.clear();
}

const std::vector<const State *> &Solver::get_solution_path() const {
    return solution_path;
}
