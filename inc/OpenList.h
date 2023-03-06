//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_OPENLIST_H
#define MAPF_CPP_OPENLIST_H

#include <queue>
#include <vector>
#include "Node.h"

/**
 *
 * A comparer in nodes which is in open list.
 */
class OpenListComparer {
public:
    /**
     *
     * @param a the first node and its timestamp.
     * @param b the second node and its timestamp.
     * @return true means that a has an higher priority than b, vice versa.
     *
     * It compares a and b by the method compareTo, firstly.\n\n
     * It will return the priority directly if compareTo method returns a inequality about this two nodes.\n\n
     * Otherwise, it will follow the FIFO policy and give a higher priority for the early node
     * by checking their timestamps.
     */
    bool operator () (const std::pair<Node*, int> &a, const std::pair<Node*, int> &b);
};

/**
 *
 * A class simulates the open list.
 * It will compare two node by node priority and time one by one.
 */
class OpenList : public std::priority_queue<
            std::pair<Node*, int>,
            std::vector< std::pair<Node*, int> >,
            OpenListComparer
        > {
protected:
    /**
     *
     * It stores the current number of nodes which has been push into this open list.
     */
    int timestamp;

public:
    /**
     *
     * Initialize the open list as an empty priority queue, and set the timestamp with value 0.
     */
    OpenList();

    /**
     *
     * @param node the node which will be pushed into this list.
     *
     * It will push this node into the open list with a timestamp.
     */
    void push_node(Node *node);

    /**
     *
     * @return the read-only pointer to the node with the highest priority.
     */
    const Node* top_node() const;
};


#endif //MAPF_CPP_OPENLIST_H
