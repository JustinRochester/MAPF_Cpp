//
// Created by Administrator on 2023/3/5.
//

#include "OpenList.h"

bool OpenListComparer::operator()(const std::pair<Node, int> &a, const std::pair<Node, int> &b) {
    int result = a.first.compareTo(b.first);
    if(result != 0)
        return result > 0;
    return a.second > b.second;
}

OpenList::OpenList():timestamp(0) {
}

void OpenList::push_node(const Node &node) {
    std::priority_queue<
            std::pair<Node, int>,
            std::vector< std::pair<Node, int> >,
            OpenListComparer
    >::emplace(node, ++timestamp);
}

const Node &OpenList::top_node() const {
    return std::priority_queue<
            std::pair<Node, int>,
            std::vector< std::pair<Node, int> >,
            OpenListComparer
    >::top().first;
}


