//
// Created by Administrator on 2023/3/10.
//

#include "ID.h"

ID::ID(Solver *low_solver_) : Solver(), low_solver(low_solver_) {
    solution_path.clear();
    groups.clear();
}

ID::ID(const ID &other) : Solver(other), solution_path(other.solution_path), groups(other.groups) {
}

ID::~ID() {
    delete low_solver;
    for (int i = 0; i < agents_number; ++i)
        delete groups[i];
}

void ID::merge_agents(int first_id, int second_id) {
    merge_set(groups[first_id], groups[second_id]);
}

std::pair<int, int> ID::check_paths() const {
    int max_time = 0;
    for (int i = 0; i < agents_number; ++i)
        max_time = std::max(max_time, solution_path[i].size());

    for (int t = 0; t < max_time; ++t) {
        std::unordered_map<Position, std::pair<Position, int>, Position::PositionHasher> constraint_set;

        for (int i = 0; i < agents_number; ++i) {
            if (constraint_set.count(solution_path[i][t + 1]))
                return std::make_pair(
                        constraint_set[solution_path[i][t + 1]].second,
                        i
                );
            if (constraint_set.count(solution_path[i][t]) &&
                constraint_set[solution_path[i][t]].first == solution_path[i][t + 1])
                return std::make_pair(
                        constraint_set[solution_path[i][t]].second,
                        i
                );
            constraint_set[solution_path[i][t + 1]] = std::make_pair(
                    solution_path[i][t],
                    i
            );
        }
    }
    return std::make_pair(-1, -1);
}

void ID::solve() {
    clear_nodes();
    for(int i=0; i<agents_number; ++i)
        if(groups[i]->is_root())
            get_group_solution(groups[i]->get_pre_order());
    for(std::pair<int, int> conflict = check_paths(); conflict != std::make_pair(-1, -1); conflict = check_paths()) {
        merge_agents(conflict.first, conflict.second);
        get_group_solution(groups[conflict.first]->get_pre_order());
    }
}

void ID::get_group_solution(const std::vector<int> &group_id) {
    int group_size = group_id.size();
    std::vector<Position> group_start_positions(group_size);
    std::vector<Position> group_goal_positions(group_size);
    for(int i=0; i<group_size; ++i) {
        solution -= solution_path[group_id[i]].size();
        group_start_positions[i] = start_positions[group_id[i]];
        group_goal_positions[i] = goal_positions[group_id[i]];
    }

    low_solver->set_map(maps);
    low_solver->get_allowed_operations() = get_allowed_operations();
    low_solver->set_problem(group_start_positions, group_goal_positions);
    low_solver->solve();

    expanded_node_number += low_solver->get_expanded_node_number();
    generated_node_number += low_solver->get_generated_node_number();

    for(int i=0; i<group_size; ++i) {
        solution_path[group_id[i]] = low_solver->get_agent_path(i);
        solution += solution_path[group_id[i]].size();
    }
}

Solver *ID::get_low_solver() const {
    return low_solver;
}

void ID::set_low_solver(Solver *lowSolver) {
    low_solver = lowSolver;
}

AgentPath ID::get_agent_path(int k) const {
    if(k<agents_number)
        return solution_path[k];
    else
        throw "Out of the number of agents.";
}

void ID::set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) {
    Solver::set_problem(start_positions_, goal_positions_);
    solution_path.assign(agents_number, AgentPath());
    groups.assign(agents_number, nullptr);
    for (int i = 0; i < agents_number; ++i)
        groups[i] = new LeftistTree(i);
}
