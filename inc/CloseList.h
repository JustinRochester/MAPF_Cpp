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
     * @param state the state which needs to be added to this close list.
     *
     * It will deal nothing if this state is in this close list.
     */
    void add(State *state);

    /**
     *
     * @param state the state which needs to be checked whether it is in this close list.
     * @return true means this state is in the close list, vice versa.
     */
    bool exists(State *state);
};


#endif //MAPF_CPP_CLOSELIST_H
