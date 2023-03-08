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

public:
    /**
     *
     * Initialize the solver with empty map, none of agents and none of allowed operations.
     */
    Solver();

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
     * In other word, it will set expanded_node_number and generated_node_number to be 0.
     */
    void clear_nodes();

    /**
     *
     * @param node pointer of the node which will be expanded to open list.
     *
     * It will increase expanded_node_number by 1 automatically.
     */
    virtual void expand_nodes(const Node *node);

    /**
     *
     * @param node pointer of the node which will be generated.
     *
     * It will increase expanded_node_number by 1 automatically.
     */
    virtual void generate_nodes(const Node *node);

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
     * @param node pointer of the node which will be checked whether it is a goal node.
     * @return true means it is a goal node, vice versa.
     */
    virtual bool is_goal_node(const Node *node) const = 0;
};


#endif //MAPF_CPP_SOLVER_H
