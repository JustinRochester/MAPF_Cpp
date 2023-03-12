//
// Created by Administrator on 2023/3/12.
//

#include "CAT.h"

CAT::CAT() = default;

CAT::CAT(const CAT &other):conflict_avoidance_table(other.conflict_avoidance_table) {
}

void CAT::add(const Position &position, const TIME_TYPE &time) {
    auto iter1 = conflict_avoidance_table.find(position);
    if(iter1 == conflict_avoidance_table.end()) {
        conflict_avoidance_table[position] = std::unordered_map<TIME_TYPE, int>();
        iter1 = conflict_avoidance_table.find(position);
    }

    auto iter2 = iter1->second.find(time);
    if(iter2 == iter1->second.end()) {
        conflict_avoidance_table[position][time] = 0;
        iter2 = iter1->second.find(time);
    }
    ++iter2->second;
}

void CAT::erase(const Position &position, const TIME_TYPE &time) {
    auto iter1 = conflict_avoidance_table.find(position);
    if(iter1 == conflict_avoidance_table.end())
        return ;
    auto iter2 = iter1->second.find(time);
    if(iter2 == iter1->second.end())
        return ;

    --iter2->second;

    if(iter2->second == 0)
        iter1->second.erase(iter2);
    if(iter1->second.empty())
        conflict_avoidance_table.erase(iter1);
}

int CAT::conflict_number(const Position &position, const TIME_TYPE &time) const {
    auto iter1 = conflict_avoidance_table.find(position);
    if(iter1 == conflict_avoidance_table.end())
        return 0;

    auto iter2 = iter1->second.find(time);
    if(iter2 == iter1->second.end())
        return 0;
    return iter2->second;
}