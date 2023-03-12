//
// Created by Administrator on 2023/3/12.
//

#ifndef MAPF_CPP_CAT_H
#define MAPF_CPP_CAT_H

#include "Position.h"
#include <unordered_map>

/**
 *
 * Conflict avoidance table, stores the conflict numbers in the given position and time.
 */
class CAT {
protected:
    /**
     *
     * Maps a position to a map of time and number of conflict.
     */
    std::unordered_map<
                Position,
                std::unordered_map<TIME_TYPE, int>,
                Position::PositionHasher
            > conflict_avoidance_table;

public:
    /**
     *
     * Initialize the CAT with an empty conflict-avoidance-table.
     */
    CAT();

    /**
     *
     * @param other source conflict-avoidance-table.
     *
     * Initialize this conflict-avoidance-table as the given source conflict-avoidance-table.
     */
    CAT(const CAT &other);

    /**
     *
     * @param position position which needs to adding into this conflict-avoidance-table
     * @param time time which needs to adding into this conflict-avoidance-table
     *
     * It will add into map automatically, if the key is not in the map.
     */
    void add(const Position &position, const TIME_TYPE &time);

    /**
     *
     * @param position position which needs to erasing from this conflict-avoidance-table
     * @param time time which needs to erasing from this conflict-avoidance-table
     *
     * It will erase the empty map automatically, after erase the given key.
     */
    void erase(const Position &position, const TIME_TYPE &time);

    /**
     *
     * @param position position which needs to checking in this conflict-avoidance-table
     * @param time time which needs to checking in this conflict-avoidance-table
     * @return the number of conflict will be occurred by selecting this position and time.
     */
    int conflict_number(const Position &position, const TIME_TYPE &time) const;
};


#endif //MAPF_CPP_CAT_H
