//
// Created by Administrator on 2023/3/8.
//

#ifndef MAPF_CPP_POSITIONLIST_H
#define MAPF_CPP_POSITIONLIST_H

#include "Position.h"
#include <vector>
#include <functional>

/**
 *
 * An array list of positions.
 */
class PositionList {
protected:
    /**
     *
     * Stores the positions for each the agent.
     */
    std::vector<Position> position_list;

public:
    /**
     * A hasher for positions list.
     */
    class PositionListHasher {
    public:
        /**
         *
         * @param positions the positions list which needs to get its hash value.
         * @return hash value of this positions list.
         */
        size_t operator () (const PositionList& positions) const;
    };
    /**
     *
     * Initialize positions-list as an empty array list.
     */
    PositionList();

    /**
     *
     * @param other source position list.
     *
     * Initialize this position list as the given source position list.
     */
    PositionList(const PositionList &other);

    /**
     *
     * @return the number of agents in the positions list.
     */
    int size() const;

    /**
     *
     * @param id the agent which you will get its positions.
     * @return reference of its positions.
     *
     * It will throw an exception if out of the number of agents.
     */
    Position& operator [] (int id);

    /**
     *
     * @param id the agent which you will get its positions.
     * @return read-only reference of its positions.
     *
     * It will throw an exception if out of the number of agents.
     */
    const Position& operator [] (int id) const;

    /**
     *
     * @return reference of the array list position_list.
     */
    std::vector<Position>& get_position_list();

    /**
     *
     * @return read-only reference of the array list position_list.
     */
    const std::vector<Position>& get_position_list() const;

    /**
     *
     * @return the hash value of this positions list.
     */
    const size_t get_hash() const;

    /**
     *
     * @param other the other positions list which need to be detected their equality.
     * @return true means equal, and false means not equal.
     */
    bool equalTo(const PositionList &other) const;

    /**
     *
     * @param lhs the first positions list which need to be detected their equality.
     * @param rhs the second positions list which need to be detected their equality.
     * @return true means equal, and false means not equal.
     */
    friend bool operator == (const PositionList &lhs, const PositionList &rhs);

    /**
     *
     * @param lhs the first positions list which need to be detected their inequality.
     * @param rhs the second positions list which need to be detected their inequality.
     * @return true means not equal, and false means equal.
     */
    friend bool operator != (const PositionList &lhs, const PositionList &rhs);

    /**
     *
     * @return a string describing the current positions list.
     */
    operator std::string() const;

    /**
     *
     * @param out a reference of out-stream.
     * @param p the positions list which is need to be outputted.
     * @return the origin reference of out-stream.
     *
     * It will transform this positions list to string, so that it is easy to output.
     */
    friend std::ostream& operator << (std::ostream& out, const PositionList &position_list);

    /**
     *
     * @param in a reference of in-stream.
     * @param p the positions list which is need to be inputted.
     * @return the origin reference of in-stream.
     *
     * It will read the number of agents at first,\n\n
     * and then it will read the x and y for each agents, one by one.
     */
    friend std::istream& operator >> (std::istream& in, PositionList &position_list);
};


#endif //MAPF_CPP_POSITIONLIST_H
