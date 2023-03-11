//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_ASTAR_H
#define MAPF_CPP_ASTAR_H

#include <vector>
#include <unordered_map>
#include "Solver.h"
#include "HeuristicMap.h"
#include "AStarNode.h"
#include "OpenList.h"
#include "CloseList.h"
#include "AgentPath.h"

class AStar : public Solver{
protected:
    /**
     *
     * It stores the heuristic value for each position in this map.
     */
    std::vector<HeuristicMap> heuristic_maps;

    /**
     *
     * It stores the A* node and provide the method to get the best one.
     */
    OpenList open;

    /**
     *
     * It stores the searched A* node, and avoids to expand too many A* nodes to open.
     */
    CloseList close;

    /**
     *
     * Holds the source-position in goal-position of the previous agents in this move.
     */
    std::unordered_map<Position, Position,
        Position::PositionHasher> constraint_set;

    /**
     *
     * @param node the node which needs to expanding its child nodes.
     *
     * It will expand all the successor by the search_move method.
     */
    void expand_child_nodes(const AStarNode *node);

    /**
     *
     * @param node the node expanded in the previous agents.
     * @param agent_id the current agent which will be considered its move.
     * @param previous_state the previous state for the states in new generated nodes.
     */
    void search_moves(AStarNode *node, int agent_id, const State *previous_state);

    /**
     *
     * @param node the node which needs to check whether it is a goal node.
     * @return true means this node is a goal node, vice versa.
     */
    bool is_goal_node(const AStarNode *node) const;

public:
    /**
     *
     * Initialize the A* solver with no agent problem.
     */
    AStar();

    /**
     *
     * Clear the node it has expands and clear the open-list and close-list automatically.
     */
    void clear_nodes() override;

    /**
     *
     * @param node the node which needs to calculate is heuristic value.
     *
     * It will calculate its heuristic value by the state in this node, and update it in-place.
     */
    void calculate_heuristic(AStarNode *node) const;

    /**
     *
     * @param node the node which will be expanded.
     * @return true means that this node is not in the close list and has been expanded successfully, vice versa.
     */
    bool expand_nodes(Node *node) override;

    /**
     *
     * @param node the node which will be generated.
     * @return true means that this node is not in the close list and has been generated successfully, vice versa.
     */
    bool generate_nodes(Node *node) override;

    /**
     *
     * @param start_positions_ start positions for each agents which will be set to this problem.
     * @param goal_positions_ goal positions for each agents which will be set to this problem.
     *
     * It will get the agent_number and calculate the heuristic map automatically.
     */
    void
    set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) override;

    /**
     *
     * It will solve the MAPF problem by A* algorithm.\n\n
     * It will start by the initial node and generates all the nodes for the selected best node,
     * and get the result by the best-first search.
     */
    void solve() override;

    /**
     *
     * @param node the goal node
     *
     * It will walk through the states and their previous states by the previous-state-pointer,
     * and stores the solution path.
     */
    void find_solutions(const Node *node) override;

    /**
     *
     * @param k the agent id which will get its path
     * @return the path for this agens.
     *
     * It will throw an exception if k is greater than the number of agens.
     */
    AgentPath get_agent_path(int k) const override;
};


#endif //MAPF_CPP_ASTAR_H
