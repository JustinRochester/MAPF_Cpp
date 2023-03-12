//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_ID_H
#define MAPF_CPP_ID_H

#include "Solver.h"
#include "AgentPath.h"
#include <vector>
#include "LeftistTree.h"

/**
 *
 * The class simulates the Independence Detection algorithm.
 */
class ID : public Solver {
protected:
    /**
     *
     * Solver in low layer for finding the solution independently.
     */
    Solver *low_solver;

    /**
     *
     * the solution path for all the agents.
     */
    std::vector<AgentPath> solution_path;

    /**
     *
     * the group organized by leftist-tree.
     */
    std::vector<LeftistTree*> groups;

public:
    /**
     *
     * @param low_solver_ Solver in low layer.
     *
     * Initialize this solver with a given low layer solver.
     */
    ID(Solver *low_solver_= nullptr);


    /**
     *
     * @param other source ID-solver.
     *
     * Initialize this ID-solver as the given source ID-solver.
     */
    ID(const ID &other);

    /**
     *
     * Free the pointer of leftist-tree in groups automatically, before delete this ID-solver.
     */
    ~ID();

    /**
     *
     * @param first_id the id of first agent which will be merged.
     * @param second_id the id of second agent which will be merged.
     *
     * It will merge the two groups which hold these two agents.
     */
    void merge_agents(int first_id, int second_id);

    /**
     *
     * @return the conflict pair of agents.
     *
     * It will answer pair(-1, -1) if there is no conflict.
     */
    std::pair<int, int> independence_detect() const;

    /**
     *
     * Solving the MAPF problem in the algorithm of Independence Detection.\n\n
     * It will planning independent path for each agent, and then finding the conflict between agents.\n\n
     * If there has still some conflict haven't been solve, it will merge this two groups and re-plan them together.
     */
    void solve() override;

    /**
     *
     * @param group_id an array list describe the each id of agents in this group.
     *
     * It will plan a paths solution for each agent in this group by low-layer solver.
     */
    void get_group_solution(const std::vector<int> &group_id);

    /**
     *
     * @return the pointer of the low-layer solver.
     */
    Solver *get_low_solver() const;

    /**
     *
     * @param lowSolver the pointer to the new low-layer solver.
     */
    void set_low_solver(Solver *lowSolver);

    /**
     *
     * @param k the agent id which will get its path
     * @return the path for this agens.
     *
     * It will throw an exception if k is greater than the number of agens.
     */
    AgentPath get_agent_path(int k) const override;

    /**
     *
     * @param start_positions_ start positions for each agents which will be set to this problem.
     * @param goal_positions_ goal positions for each agents which will be set to this problem.
     *
     * It will get the agent_number and initialize the solution-path, groups automatically.
     */
    void
    set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) override;
};


#endif //MAPF_CPP_ID_H
