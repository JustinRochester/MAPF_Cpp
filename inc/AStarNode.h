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

public:
    /**
     *
     * @param g_ the cost of path from start node to this A* node.
     * @param h_ the estimating cost of path from this node to goal node.
     *
     * Initialize this A* node with a empty multi-agents state and given cost.\n\n
     * Costs of g and h will be set as 0 by default.
     */
    AStarNode(HEURISTIC_TYPE g_=0, HEURISTIC_TYPE h_=0);

    /**
     *
     * @param id which agent's position will be got.
     * @return a references of position of the id-th agent.
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
     * @return a new A* node with a updated cost and position for each agents.
     */
    AStarNode apply(const std::vector<std::pair<Vector, HEURISTIC_TYPE>> &operation_list);
};


#endif //MAPF_CPP_ASTARNODE_H
