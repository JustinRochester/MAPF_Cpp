//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_CLOSELIST_H
#define MAPF_CPP_CLOSELIST_H

#include <unordered_map>
#include <list>
#include "State.h"

class CloseList {
protected:
    std::unordered_map<size_t, std::list<State*> > close;

public:
    CloseList();
    void add(State *state);
    bool exists(State *state);
};


#endif //MAPF_CPP_CLOSELIST_H
