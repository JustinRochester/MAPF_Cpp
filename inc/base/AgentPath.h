//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_AGENTPATH_H
#define MAPF_CPP_AGENTPATH_H

#include "PositionList.h"

/**
 *
 * A packaged class for agent's single path.
 */
class AgentPath : public PositionList {
public:
    /**
     *
     * Initializer.
     */
    AgentPath();

    /**
     *
     * @param time the time we need to get the agent.
     * @return reference of the position this agent is in.
     *
     * We assume that the agent will stay in the goal if it reach the goal.
     */
    Position& operator [] (int time);

    /**
     *
     * @param time the time we need to get the agent.
     * @return reference of the position this agent is in.
     *
     * We assume that the agent will stay in the goal if it reach the goal.
     */
    const Position& operator [] (int time) const;
};


#endif //MAPF_CPP_AGENTPATH_H
