//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_SINGLEAGENTSTATE_H
#define MAPF_CPP_SINGLEAGENTSTATE_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include "common.h"
#include "Position.h"
#include "State.h"

/**
 *
 * A class describing the current position and time of a single agent.
 */
class SingleAgentState : public State{
protected:
    /**
     *
     * Current position of this agent(in this state).
     */
    Position position;

    /**
     *
     * Current time of this agent(in this state).
     */
    TIME_TYPE time;

public:
    /**
     *
     * @param position_ current position in this state.
     * @param time_ current time in this state.
     *
     * Initialize this single-agent-state by given position and time.
     * Sets position as initial position and sets time as -1 in default.
     */
    SingleAgentState(const Position &position_= Position(), const TIME_TYPE &time_= -1);

    /**
     *
     * A hasher used to hash class SingleAgentState.
     */
    class SingleStateAgentHasher : public State::StateHasher{
    public:
        /**
         *
         * @param s a SingleAgentState which need to be calculated its hash value.
         * @return hash value of s
         *
         * It will throw an exception if s could not be casted to SingleAgentState.
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
     * @return a string which describes this single-agent-state.
     */
    operator std::string() const override;

    /**
     *
     * @return read-only reference of current position about this single-agent-state.
     */
    const Position & get_position() const;

    /**
     *
     * @return read-only reference of current time about this single-agent-state.
     */
    const TIME_TYPE & get_time() const;

    /**
     *
     * @param position_ new position used to update the current position of this single-agent-state.
     */
    void set_position(const Position &position_);

    /**
     *
     * @param time_ new time used to update the current time of this single-agent-state.
     */
    void set_time(const TIME_TYPE &time_);

    /**
     *
     * @param out a references of out-stream.
     * @param s a single-agent-state which needs to be outputted.
     * @return the origin references of out-stream.
     *
     * It will output this single-agent-state by transform it to string.
     */
    friend std::ostream& operator << (std::ostream &out, const SingleAgentState &s);

    /**
     *
     * @param in a references of in-stream.
     * @param s a single-agent-state which needs to be inputted.
     * @return the origin references of in-stream.
     */
    friend std::istream& operator >> (std::istream &in, SingleAgentState &s);

    /**
     *
     * @param v a vector which will be applied to this single-agent-state.
     * @return a new single-agent-state which equals to the origin state apply this vector.
     */
    SingleAgentState apply(const Vector &v);

    /**
     *
     * @return an instance of SingleAgentStateHasher.
     */
    StateHasher & get_hasher() const override;
};


#endif //MAPF_CPP_SINGLEAGENTSTATE_H
