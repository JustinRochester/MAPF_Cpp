//
// Created by Administrator on 2023/3/5.
//

#include "OpenList.h"

bool OpenListComparer::operator()(const std::pair<Node*, int> &a, const std::pair<Node*, int> &b) {
    int result = a.first->compareTo(*b.first);
    if(result != 0)
        return result > 0;
    return a.second > b.second;
}

OpenList::OpenList():timestamp(0) {
}

OpenList::OpenList(const OpenList &other):timestamp(other.timestamp), open_priority_queue(other.open_priority_queue) {
}

OpenList::~OpenList() {
    while(!empty())
        pop();
}

void OpenList::push(Node *node) {
    open_priority_queue.emplace(node, ++timestamp);
}

const Node *OpenList::top() const {
    return open_priority_queue.top().first;
}

void OpenList::pop() {
    delete top();
    open_priority_queue.pop();
}

bool OpenList::empty() const {
    return open_priority_queue.empty();
}

int OpenList::size() const {
    return open_priority_queue.size();
}


