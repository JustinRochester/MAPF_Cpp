//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_MULTIAGENTSTATE_H
#define MAPF_CPP_MULTIAGENTSTATE_H

#include <vector>
#include "Position.h"
#include "PositionList.h"
#include "State.h"

/**
 *
 * A class describing the current positions and time of a list of agents.
 */
class MultiAgentState : public State {
protected:
    /**
     *
     * Current positions of these agent(in this state).
     */
    PositionList positions;

    /**
     *
     * Current time of this agent(in this state).
     */
    TIME_TYPE time;

public:
    /**
     *
     * @param time_ current time in this state.
     *
     * Initialize this multi-agent-state by given time.
     * Sets time as -1 in default.
     */
    MultiAgentState(const TIME_TYPE &time_ = -1);

    /**
     *
     * @param other source multi-agent state.
     *
     * Initialize this multi-agent state as the given source multi-agent state.
     */
    MultiAgentState(const MultiAgentState &other);

    /**
     *
     * A hasher used to hash class MultiAgentState.
     */
    class MultiAgentStateHasher : public State::StateHasher {
    public:
        /**
         *
         * @param s a MultiAgentState which need to be calculated its hash value.
         * @return hash value of s
         *
         * It will throw an exception if s could not be casted to MultiAgentState.
         */
        size_t operator()(const State &s) const override;
    };

    /**
     *
     * @param s another state which is need to detecting equality.
     * @return true means equal, and false means not equal.
     *
     * It will be detecting by hash value firstly, and then by checking all the other attributes.
     */
    bool equalTo(const State &s) const override;

    /**
     *
     * @return a string which describes this multi-agent-state.
     */
    operator std::string() const override;

    /**
     *
     * @return the number of agents.
     */
    int size();

    /**
     *
     * @return references of current positions list about this multi-agent-state.
     */
    PositionList & get_positions();

    /**
     *
     * @return read-only references of current positions list about this multi-agent-state.
     */
    const PositionList & get_positions() const;

    /**
     *
     * @return read-only references of current time about this multi-agent-state.
     */
    const TIME_TYPE &get_time() const;

    /**
     *
     * @param time_ new time used to update the current time of this multi-agent-state.
     */
    void set_time(const TIME_TYPE &time_);

    /**
     *
     * @param out a references of out-stream.
     * @param s a multi-agent-state which needs to be outputted.
     * @return the origin references of out-stream.
     *
     * It will output this multi-agent-state by transform it to string.
     */
    friend std::ostream &operator<<(std::ostream &out, const MultiAgentState &s);

    /**
     *
     * @param in a references of in-stream.
     * @param s a multi-agent-state which needs to be inputted.
     * @return the origin references of in-stream.
     */
    friend std::istream &operator>>(std::istream &in, MultiAgentState &s);

    /**
     *
     * @param operation_list a vector list which will be applied to this multi-agent-state one by one.
     * @return a new multi-agent-state which equals to the origin state apply this vector list.
     *
     * It will read a number represents the number of agents, and then read positions of each agent(s).\n\n
     * Time will be read in the last.
     */
    MultiAgentState apply(const std::vector<Vector> &operation_list);

    /**
     *
     * @return an instance of MultiAgentStateHasher.
     */
    size_t get_hash() const override;

    /**
     *
     * @param id which agent's positions will be got.
     * @return a references of positions of the id-th agent.
     *
     * It will throw an exception if id is out of the number ot agents.
     */
    Position &operator[](int id);

    /**
     *
     * @param id which agent' positions will be got.
     * @return a read-only references of positions of the id-th agent.
     *
     * It will throw an exception if id is out of the number ot agents.
     */
    const Position &operator[](int id) const;
};


#endif //MAPF_CPP_MULTIAGENTSTATE_H
