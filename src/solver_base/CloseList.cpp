//
// Created by Administrator on 2023/3/5.
//

#include "CloseList.h"

CloseList::CloseList() {
    close.clear();
}

CloseList::CloseList(const CloseList &other):close(other.close) {
}

void CloseList::clear() {
    for(const auto &[hash_value, l] : close)
        for(State* s : l)
            delete s;
    close.clear();
}

CloseList::~CloseList() {
    clear();
}

void CloseList::add(State *state) {
    size_t hash_val = state->get_hash();

    if(!close.count(hash_val))
        close[hash_val] = std::list<State*>();

    for(const State* check_state : close[hash_val])
        if(*check_state == *state) {
            delete state;
            return;
        }
    close[hash_val].push_back(state);
}

bool CloseList::exists(const State *state) {
    size_t hash_val = state->get_hash();
    if(!close.count(hash_val))
        return false;
    for(const State* check_state : close[hash_val])
        if(*check_state == *state)
            return true;
    return false;
}
