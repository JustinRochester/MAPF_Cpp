//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_SOLVER_H
#define MAPF_CPP_SOLVER_H

#include <vector>
#include "common.h"
#include "Position.h"
#include "Map.h"
#include "Node.h"
#include "State.h"
#include "AgentPath.h"

/**
 *
 * It means that the solution has not been found.
 */
const HEURISTIC_TYPE SOLUTION_NOT_FOUND = -1;

/**
 *
 * An abstract class of each solver for MAPF problem.
 */
class Solver {
protected:
    /**
     *
     * The number of agents in this planning problem.
     */
    int agents_number;

    /**
     *
     * The solution of this planning problem.\n\n
     * It means that solution not exists if solution < 0.
     */
    HEURISTIC_TYPE solution;

    /**
     *
     * Start positions for each agents.
     */
    std::vector<Position> start_positions;

    /**
     *
     * Goal positions for each agents.
     */
    std::vector<Position> goal_positions;

    /**
     *
     * Counting the number of nodes which have been expanded to open list.
     */
    int expanded_node_number;

    /**
     *
     * Counting the number of nodes which have been generated in expanding nodes.
     */
    int generated_node_number;

    /**
     *
     * Detail of planning map.
     */
    Map maps;

    /**
     *
     * The array list of allowed operations in this planning problem.
     */
    std::vector< std::pair<Vector, HEURISTIC_TYPE> > allowed_operations;

    /**
     *
     * Stores the path for each states.
     */
    std::vector<const State *> state_log;

    /**
     *
     * Stores the whole path in the solution.
     */
     std::vector<const State *> solution_path;

    /**
     *
     * It should planning the path so that there is no conflict before conflict window.\n\n
     * It means infinity if its value is -1.
     */
    int conflict_window;

public:
    /**
     *
     * Initialize the solver with empty map, none of agents and none of allowed operations.
     */
    Solver();

    /**
     *
     * @param other source solver.
     *
     * Initialize this solver as the given source solver.
     */
    Solver(const Solver &other);

    /**
     *
     * clear the nodes construct by this solver.
     */
    ~Solver();

    /**
     *
     * @return the solution length of this planning task.
     *
     * It will throw an exception if the solution has not been found.
     */
    HEURISTIC_TYPE get_solution() const;

    /**
     *
     * @param start_positions_ start positions for each agents which will be set to this problem.
     * @param goal_positions_ goal positions for each agents which will be set to this problem.
     *
     * It will get the agent_number automatically.
     */
    virtual void set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_);

    /**
     *
     * @param maps_ maps for this planning problem which will be set.
     */
    virtual void set_map(const Map& maps_);

    /**
     *
     * Clear all nodes in this solver.\n\n
     * In other word, it will set expanded_node_number and generated_node_number to be 0.\n\n
     * And then, it will free all the states holds in state_log.
     */
    virtual void clear_nodes();

    /**
     *
     * @param node pointer of the node which will be expanded to open list.
     * @return if it expands a node successfully(not in the close).
     *
     * It will increase expanded_node_number by 1 automatically.
     */
    virtual bool expand_nodes(Node *node);

    /**
     *
     * @param node pointer of the node which will be generated.
     * @return if it generated a node successfully(not in the close).
     *
     * It will increase expanded_node_number by 1 automatically.
     */
    virtual bool generate_nodes(Node *node);

    /**
     *
     * An abstract method for solving problem.
     */
    virtual void solve() = 0;

    /**
     *
     * @return reference of the array list of allowed operations.
     */
    virtual std::vector< std::pair<Vector, HEURISTIC_TYPE> > &get_allowed_operations();

    /**
     *
     * @return read-only reference of the array list of allowed operations.
     */
    virtual const std::vector< std::pair<Vector, HEURISTIC_TYPE> > &get_allowed_operations() const ;

    /**
     *
     * @param node goal node.
     *
     * Defines some follow-up operations after find out the solution.
     */
    virtual void find_solutions(const Node *node);

    /**
     *
     * @return the solution path through the whole states.
     */
    const std::vector<const State*>& get_solution_path() const;

    /**
     *
     * @param k the agent id which will get its path
     * @return the path for this agens.
     *
     * It should throw an exception if k is greater than the number of agens.
     */
    virtual AgentPath get_agent_path(int k) const = 0;

    /**
     *
     * @return the number of expanded nodes.
     */
    int get_expanded_node_number() const;

    /**
     *
     * @return the number of generated nodes.
     */
    int get_generated_node_number() const;

    /**
     *
     * @return length of the conflict window.
     */
    int get_conflict_window() const;

    /**
     *
     * @param conflictWindow new conflict window length to update.
     */
    void set_conflict_window(int conflictWindow);
};


#endif //MAPF_CPP_SOLVER_H
