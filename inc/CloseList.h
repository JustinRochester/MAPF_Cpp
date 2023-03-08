//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_CLOSELIST_H
#define MAPF_CPP_CLOSELIST_H

#include <unordered_map>
#include <list>
#include "State.h"

/**
 *
 * A class simulates the close list.\n\n
 * It will stores states in the open hashing table.
 */
class CloseList {
protected:
    /**
     *
     * It stores states s in the list close[hash value of s].
     */
    std::unordered_map<size_t, std::list<State*> > close;

public:
    /**
     *
     * Initialize the close list with an empty unordered_map and none of list.
     */
    CloseList();

    /**
     *
     * @param other source close list.
     *
     * Initialize this close list as the given source close list.
     */
    CloseList(const CloseList& other);

    /**
     *
     * Delete all the pointer in this close list automatically.
     */
    void clear();

    /**
     *
     * Delete all the pointer in this close list automatically by calling clear method.
     */
    ~CloseList();

    /**
     *
     * @param state the state which needs to be added to this close list.
     *
     * It will deal nothing if this state is in this close list.\n\n
     * Please add a new pointer state, like 'add(new XXXState(yyy))'.
     */
    void add(State *state);

    /**
     *
     * @param state the state which needs to be checked whether it is in this close list.
     * @return true means this state is in the close list, vice versa.
     */
    bool exists(const State *state);
};


#endif //MAPF_CPP_CLOSELIST_H
