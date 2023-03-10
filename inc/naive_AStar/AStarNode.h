//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_ASTARNODE_H
#define MAPF_CPP_ASTARNODE_H

#include <vector>
#include <functional>
#include "common.h"
#include "MultiAgentState.h"
#include "Position.h"
#include "Node.h"

/**
 *
 * Class of searching node for basic A* solver to MAPF Problem.
 */
class AStarNode : public Node {
protected:
    /**
     *
     * State of multi-agents in this A* node.
     */
    MultiAgentState agents_state;

    /**
     *
     * Time of stopping in the goal for each agent.\n\n
     * Some of the values will be set as -1 if these agents are not in the goal.
     */
    std::vector<int> stop_time;

public:
    /**
     *
     * @param g_ the cost of path from start node to this A* node.
     * @param h_ the estimating cost of path from this node to goal node.
     *
     * Initialize this A* node with a empty multi-agents state and given cost.\n\n
     * Costs of g and h will be set as 0 by default.
     */
    AStarNode(HEURISTIC_TYPE g_ = 0, HEURISTIC_TYPE h_ = 0, int agent_number = 0);

    /**
     *
     * @param other source A* node.
     *
     * Initialize this A* node as the given source A* node.
     */
    AStarNode(const AStarNode& other);

    /**
     *
     * @param id which agent's positions will be got.
     * @return a references of positions of the id-th agent.
     *
     * It will throw an exception if id is out of the number ot agents.
     */
    Position& operator [] (int id);

    /**
     *
     * @return reference of multi-agent state.
     */
    MultiAgentState& get_state();

    /**
     *
     * @return read-only reference of multi-agent state.
     */
    const MultiAgentState& get_state() const;

    /**
     *
     * @param operation_list an operator list with allowed move vector and its cost at each term.
     * @return a new A* node with a updated cost and positions for each agents.
     */
    AStarNode apply(const std::vector<std::pair<Vector, HEURISTIC_TYPE>> &operation_list);

    /**
     *
     * @return reference of stop_time array list for each agents.
     */
    std::vector<int>& get_stop_time();
};


#endif //MAPF_CPP_ASTARNODE_H
